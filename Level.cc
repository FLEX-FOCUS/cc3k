//
//  Level.cc
//  A5
//
//  Created by Jasper Wang on 14-11-19.
//  Copyright (c) 2014 Jasper Wang. All rights reserved.
//
#include <sstream>
#include <iostream>
#include "Level.h"
#include "Gold.h"
#include "Potion.h"
#include <cstdlib>
#include <ctime>
#include "allChara.h"
#include <string>
#include <ncurses.h>
using namespace std;
Level::Level(Display *dis,int r,int c): d(dis),row(r),column(c){
    // player here is a singleton
    if(!p->instance){               // initialize the player; choose race
        printw("Choose a hero from below: \n");
        printw("Shade(s) Drow(d) Vampire(v) Troll(t) Goblin(g) Jasper(j) Woody(w)\n");
        race=getch();
        summonHero(race);           // calls the method
    }
    else {                          // if player exists
        p->instance->setDisplay(d); // player "has a" new Display
        summonHero(race);}
    d->notifyStat(p->instance->getHP(), p->getAtt(), p->getDef(), p->returnGold(), p->getRace());
    // create elements in the floor
    Summon_Monster();
    Summon_Potion();
    Summon_Gold();
    clear();                        // clear the screen
    print(*d);
    printw("hello world! this is %s, I am in level %d",p->getRace().c_str(),d->floor);
}


void Level::summonHero(char race){
    srand((unsigned)time(NULL));
    // initialize the stage
    while (true) {
        int slash_x = rand()%column;
        int slash_y = rand()%row;
        if (d->getChar(slash_x, slash_y) == '.') { //only summon on '.'
            d->notify(slash_x, slash_y, '/');
            break;
        }
    }
    // initialize the hero
    while(true){
        //srand((unsigned)time(NULL));
        int summon_x=rand()%column;
        int summon_y=rand()%row;
        if(d->getChar(summon_x,summon_y)=='.'&&!d->check(summon_x,summon_y)){
            p = Player::getInstance(d,race);
            p->setcoords(summon_x,summon_y);
            break;
        }
    }
}


void Level::Summon_Monster(){
    srand((unsigned)time(NULL));
    string random_monster="HHHHDDDLLLLLEEOOMM";  // to randomly spawn enemies
    // spawn 20 enemies each floor
    for(int i=0;i<20;i++){
        int summon_x,summon_y;
        // to check whether it's a valid position to spawn
        while(true){
            summon_x=rand()%column;
            summon_y=rand()%row;
            if(d->getChar(summon_x,summon_y)=='.') break;
        }
        char summon_type=random_monster[rand()%18]; //randomly get a type
        switch(summon_type){
            case 'H': monster.push_back(new Human(d));
                monster.at(i)->setcoords(summon_x,summon_y);
                break;
            case 'D': monster.push_back(new Dwarf(d));
                monster.at(i)->setcoords(summon_x,summon_y);
                break;
            case 'L': monster.push_back(new Halfling(d));
                monster.at(i)->setcoords(summon_x,summon_y);
                break;
            case 'E': monster.push_back(new Elf(d));
                monster.at(i)->setcoords(summon_x,summon_y);
                break;
            case 'O': monster.push_back(new Orc(d));
                monster.at(i)->setcoords(summon_x,summon_y);
                break;
            case 'M': monster.push_back(new Merchant(d));
                monster.at(i)->setcoords(summon_x,summon_y);
                break;
        }
    }
}


// destructor for level 
Level::~Level(){
    delete d;                       //free the Display
    int s = (int)monster.size();
    // free the monsters in the vector
    for (int i = 0; i < s ; i++) {
        delete monster.at(i);
    }
    monster.clear();
    s = (int)potion.size();
    // free the Potions in the vector
    for (int i = 0; i < s ; i++) {
        delete potion.at(i);
    }
    potion.clear();
    s = (int)gold.size();
    // free the Gold in the vector
    for (int i = 0; i < s ; i++) {
        delete gold.at(i);
    }
    gold.clear();
}



bool Level::walk(std::string dir){
    int tmp = p->walk(dir);
    if(tmp==2) return true;     // if meets a floor
    if (tmp==1) return false;   // if the move is invalid
    one_turn();                 // when move is valid, the other monsters move
    return false;
}


void Level::attack(std::string dir){
    int x=p->getX();
    int y=p->getY();
    if(dir=="so")
        y+=1;
    else if(dir=="no")
        y-=1;
    else if(dir=="ea")
        x+=1;
    else if(dir=="we")
        x-=1;
    else if(dir=="se"){
        y+=1;
        x+=1;
    }
    else if(dir=="sw"){
        x-=1;
        y+=1;
    }
    else if(dir=="ne"){
        x+=1;
        y-=1;
    }
    else if(dir=="nw"){
        x-=1;
        y-=1;
    }
    //if it is a valid enemy
    if(d->getChar(x,y)=='H'||d->getChar(x,y)=='D'||d->getChar(x,y)=='L'||
       d->getChar(x,y)=='E'||d->getChar(x,y)=='O'||d->getChar(x,y)=='M')
    {
        int size=(int)monster.size();
        //find the corresponding enemy in the monster vector
        for(int i=0;i<size;i++){
            int m_x =monster.at(i)->getX();
            int m_y =monster.at(i)->getY();
            if(m_x ==x && m_y ==y){
                if (monster.at(i)->getRace() == "merchant") {
                    p->isEnemy = true;     //set player as enemy of merchant
                }
                int change = monster.at(i)->getHP();
                int my_change=p->getHP();
                p->attack(monster.at(i));
                ostringstream os("");
                os << change-monster.at(i)->getHP();
                string tmp;
                tmp = os.str();
                if (!monster.at(i)->getStatus()) // if the monster dies
                {
                    d->notify(m_x, m_y, '.');
                    if (dynamic_cast<Merchant *>(monster.at(i))) {
                        //if the merchant is monster, a gold of 4
                        //will be left to the ground
                        gold.push_back(new Gold(true,4,d));
                        int j = (int)gold.size()-1;
                        gold.at(j)->setcoords(m_x,m_y);
                        d->notify(m_x, m_y, 'G');
                    }
                    else if (dynamic_cast<Dragon *>(monster.at(i))) {
                        //if the died monster is a dragon, its gold
                        //can be picked up by the player
                        int sg = (int)gold.size();
                        for(int j=0;j<sg;j++){
                            Dragon *tmp = static_cast<Dragon *>(monster.at(i));
                            if(gold.at(j)->getX() == tmp->get_hx() &&  gold.at(j)->getY() == tmp->get_hy())
                            gold.at(j)->get = true;
                        }
                    }
                    //set up the action(string)
                    string get_race=monster.at(i)->getRace();
                    action = " I have just slayed "+ get_race;
                    Enemy *tmp=monster.at(i);
                    monster.erase(monster.begin()+i);
                    delete tmp;

                }
                else{
                    //set up the action(string)
                    string tmp2;
                    ostringstream os2;
                    os2 << my_change-p->getHP();
                    tmp2 = os2.str();
                    monster.at(i)->attack(p);
                    action="I deals "+tmp+" damage to "+monster.at(i)->getRace()
                    +" "+monster.at(i)->getRace()+" deals "+tmp2+" damage to me";

                }
                break;
            }
        }
        one_turn(); //every monster will move after you attack an enemy
    }
}


void Level::get_item(std::string dir){
    int x=p->getX();
    int y=p->getY();
    if(dir=="no")
        y-=1;
    else if(dir=="so")
        y+=1;
    else if(dir=="ea")
        x+=1;
    else if(dir=="we")
        x-=1;
    else if(dir=="se"){
        y+=1;
        x+=1;
    }
    else if(dir=="sw"){
        x-=1;
        y+=1;
    }
    else if(dir=="ne"){
        x+=1;
        y-=1;
    }
    else if(dir=="nw"){
        x-=1;
        y-=1;
    }
    if(d->getChar(x,y)=='G'){
        
        int size=(int)gold.size();
        //find the corresponding gold in the vector
        for(int i=0;i<size;i++){
            if(gold.at(i)->getX() == x && gold.at(i)->getY() == y){
                if (!gold.at(i)->get) {
                    clear();
                    print(*d);
                    printw("You need to kill the Dragon\n");
                    return;
                }
                d->notify(x, y, '.');
                p->getGold(gold.at(i));
            }
        }
         d->notifyStat(p->getHP(), p->getAtt(), p->getDef(), p->returnGold(), p->getRace());
        clear();
        print(*d);
        printw("%s just get a gold\n",p->getRace().c_str());
    }
    else if(d->getChar(x,y)=='P'){
        int size=(int)potion.size();
        //find the corresponding gold in the vector
        for(int i=0;i<size;i++){
            if(potion.at(i)->getX() ==x && potion.at(i)->getY()==y){
                p->getPotion(potion.at(i));
                d->notify(x, y, '.');
            }
        }
         d->notifyStat(p->getHP(), p->getAtt(), p->getDef(), p->returnGold(), p->getRace());
        clear();
        print(*d);
        printw("%s just get a potion\n",p->getRace().c_str());
    }
}


void Level::use_potion(){
    p->usePotion();
}

//Each monster will remain its block and combat with the player
//if the player stands within their attack range. (1 block)
//Each monster will move to player's position if the player is in
//their signt range (5 blocks)
//The monster will move in randomly direction if neither of above events happen
void Level::one_turn(){
    srand((unsigned)time(NULL)-2*rand());
    unsigned int temp_rand=rand();
    srand(temp_rand);
    int size=(int)monster.size();
    
    //For every monster
    for(int i=0;i<size;i++){
        //if a monster find a player with or without a move
        if(monster.at(i)->move()){
            int change = monster.at(i)->getHP();
            if (dynamic_cast<Merchant *>(monster.at(i))&&!p->isEnemy) {continue;}
            else {p->attack(monster.at(i));}
            if (monster.at(i)->getStatus()) {  //if monster is alive
                int my_change = p->getHP();
                 if (dynamic_cast<Merchant *>(monster.at(i))){
                     if(p->isEnemy) {
                         monster.at(i)->attack(p);
                     }
                 }
                 else {monster.at(i)->attack(p);}
                ostringstream os("");
                os << change-monster.at(i)->getHP();
                string tmp;
                string tmp2;
                tmp = os.str();
                ostringstream os2;
                os2 << my_change-p->getHP();
                tmp2 = os2.str();
                action="I deals "+tmp+" damage to "+monster.at(i)->getRace()
                +" "+monster.at(i)->getRace()+" deals "+tmp2+" damage to me";
            }
            else {  // when monsters dies
                d->notify(monster.at(i)->getX(), monster.at(i)->getY(), '.');
                if (dynamic_cast<Merchant *>(monster.at(i))) { //merchant dies
                    gold.push_back(new Gold(true,4,d));
                    int j = (int)gold.size()-1;
                    int x =monster.at(i)->getX();
                    int y =monster.at(i)->getY();
                    gold.at(j)->setcoords(x,y);
                    d->notify(x, y, 'G');
                }
                else if (dynamic_cast<Dragon *>(monster.at(i))) {//dragon dies
                    int sg = (int)gold.size();
                    for(int j=0;j<sg;j++){
                        Dragon *tmp = static_cast<Dragon *>(monster.at(i));
                        if(gold.at(j)->getX() == tmp->get_hx() &&  gold.at(j)->getY() == tmp->get_hy())
                            gold.at(j)->get = true;
                    }
                }
                clear();
                d->notifyStat(p->getHP(), p->getAtt(), p->getDef(), p->returnGold(), p->getRace());
                print(*d);
                action="I have just slayed "+monster.at(i)->getRace();
                delete monster.at(i);
                monster.erase(monster.begin()+i);
                size--;
            }
        }
    }//for-loop
    d->notifyStat(p->getHP(), p->getAtt(), p->getDef(), p->returnGold(), p->getRace());
    clear();
    print(*d);
    printw(action.c_str());
    action = "";
}



void Level::Summon_Gold(){
    //the gold summon rate for different level
    string random_gold="NNNNNDSS";
    if (d->floor == 2) {
        random_gold="NNNDDDSS";
    }
    if (d->floor == 3) {
        random_gold="DDDDDSSS";
    }
    if (d->floor == 4) {
        random_gold="DDDDDDSS";
    }
    if (d->floor == 5) {
        random_gold="DDDDDDDD";
    }
    srand((unsigned)time(NULL));
    //summon the ten gold randomly
    for(int i=0;i<10;i++){
        int summon_x,summon_y;
        while(true){
            summon_x=rand()%column;
            summon_y=rand()%row;
            if(d->getChar(summon_x,summon_y)=='.') break;
        }
        int tmpX = 0;
        int tmpY = 0;
        char summon_type=random_gold[rand()%8];
        switch(summon_type){
            //if it is a normal gold
            case 'N': gold.push_back(new Gold(true,2,d));
                gold.at(i)->setcoords(summon_x,summon_y);
                break;
            //if a dragon hoard
            case 'D': gold.push_back(new Gold(false,6,d));
                gold.at(i)->setcoords(summon_x,summon_y);
                
                while (d->getChar(tmpX, tmpY) != '.') {
                    tmpX = summon_x + rand()%3-1;
                    tmpY = summon_y + rand()%3-1;
                }
                monster.push_back(new Dragon(d, summon_x, summon_y));
                monster.at(monster.size()-1)->setcoords(tmpX,tmpY);
                break;
            //if a small hoard
            case 'S': gold.push_back(new Gold(true,1,d));
                gold.at(i)->setcoords(summon_x,summon_y);
                break;
        }
    }
}


void Level::Summon_Potion(){
    srand((unsigned)time(NULL));
    //summon the potions in random position
    for(int i=0;i<10;i++){
        int summon_x,summon_y;
        while(true){
            summon_x=rand()%column;
            summon_y=rand()%row;
            if(d->getChar(summon_x,summon_y)=='.')
                break;
        }
        int summon_type=rand()%6+1;
        //different types of potions(different effect )
        switch(summon_type){
            case 1: potion.push_back(new Potion("RH",d));
                potion.at(i)->setcoords(summon_x,summon_y);
                break;
            case 2: potion.push_back(new Potion("BA",d));
                potion.at(i)->setcoords(summon_x,summon_y);
                break;
            case 3: potion.push_back(new Potion("BD",d));
                potion.at(i)->setcoords(summon_x,summon_y);
                break;
            case 4: potion.push_back(new Potion("PH",d));
                potion.at(i)->setcoords(summon_x,summon_y);
                break;
            case 5: potion.push_back(new Potion("WA",d));
                potion.at(i)->setcoords(summon_x,summon_y);
                break;
            case 6: potion.push_back(new Potion("WD",d));
                potion.at(i)->setcoords(summon_x,summon_y);
                break;
        }
    }
}




