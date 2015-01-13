//
//  player.cc
//  A5
//
//  Created by Jasper Wang on 14-11-15.
//  Copyright (c) 2014 Jasper Wang. All rights reserved.
//
#include <string>
#include "Player.h"
#include "Display.h"
#include "Potion.h"
#include "Gold.h"
#include "allChara.h"
#include <ncurses.h>
using namespace std;

Player* Player::instance=0;

Player* Player::getInstance(Display *d,char race){
    if(!instance){
        if(race=='s'){
            instance = new Shade(d);
        }
        else if(race=='d'){
            instance = new Drow(d);
        }
        else if(race=='v'){
            instance = new Vampire(d);
        }
        else if(race=='t'){
            instance = new Troll(d);
        }
        else if(race=='g'){
            instance = new Goblin(d);
        }
        else if(race=='j'){instance = new Jasper(d);}
        else if(race=='w'){instance = new YoooWoody(d);}
        instance->gold = 0;
        d->notifyStat(instance->HP,instance->Att,instance->Def,instance->gold,instance->race);
    }
    
    return instance;
}

void Player::changeAtt(int val){
    if (attBuff + Att < 0) {
        return;
    }
    attBuff += val;
}

void Player::changeDef(int val){
    if (defBuff + Def < 0) {
        return;
    }
    defBuff += val;
}

// called by monsters
void Player::defense(int val){
    double selfDef = this->Def;
    HP -= (int)100/(100+selfDef) * val;
}


int Player::walk(string dir){
    int NextX=x,NextY=y;
    if (dir == "no") {
        NextY--;
    }
    else if (dir == "so"){
        NextY++;
    }
    else if (dir == "ea"){
        NextX++;
    }
    else if (dir == "we"){
        NextX--;
    }
    else if (dir == "ne"){
        NextX++;
        NextY--;
    }
    else if (dir == "nw"){
        NextX--;
        NextY--;
    }
    else if (dir == "se"){
        NextX++;
        NextY++;
    }
    else if (dir == "sw"){
        NextX--;
        NextY++;
    }
    // if the move is valid
    if (d->getChar(NextX, NextY) != '.'&&d->getChar(NextX, NextY) != '#'&&d->getChar(NextX, NextY) != '+'&&d->getChar(NextX, NextY) != '/') {
        clear();
        print(*d);
        printw("invalid move!!!!!!\n");
        return 1;
    }
    // if the move is valid
    d->notify(x, y, prevFloor);   // put the previous floor to that point
    x = NextX;
    y = NextY;
    prevFloor = d->getChar(x, y);  // set the new floor
    d->notify(x, y, '@');
    if (prevFloor == '/') {
        attBuff = 0;
        defBuff = 0;
        prevFloor = '.';
        return 2;
    }
    return 0;

}



void Player::usePotion(){
    if (!Inventory.size()) {            //if there is no potion in the inventory
        print(*d);
        printw("no potion available in inventory\n");
        return;
    }
    Potion *last = Inventory.back();    //return the last potion picked up
    string tmp = last->getName();
    if (tmp == "RH") {
        this->changeHP(10);
    }
    else if (tmp == "BA"){
        this->changeAtt(5);
    }
    else if (tmp == "BD"){
        this->changeDef(5);
    }
    else if (tmp == "PH") {
        this->changeHP(-10);
    }
    else if (tmp == "WA"){
        this->changeAtt(-5);
    }
    else{
        this->changeDef(-5);
    }
    // print out new result
    d->notifyStat(HP, Att+attBuff, Def+defBuff, gold, race);
    print(*d);
    printw("I have just used %s\n",tmp.c_str());
    Inventory.pop_back();
}

void Player::getGold(Gold *object){
    gold += object->getValue();
    object->removal();
    d->notifyStat(HP, Att+attBuff, Def+defBuff, gold, race);
}

void Player::getPotion(Potion *object){
    Inventory.push_back(object);
    object->removal();
}
