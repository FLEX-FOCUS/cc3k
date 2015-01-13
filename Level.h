
//
//  Level.h
//  A5
//
//  Created by Jasper Wang on 14-11-15.
//  Copyright (c) 2014 Jasper Wang. All rights reserved.
//

#ifndef __A5__Level__
#define __A5__Level__
#include "Player.h"
#include "Item.h"
#include "Display.h"
#include "Potion.h"
#include "Gold.h"
#include "Enemy.h"
#include <vector>

class Level{
protected:
	Player *p;
    std::vector<Enemy *> monster;
   	std::vector<Gold *> gold;
	std::vector<Potion *> potion;
    Display * d;
	int row;
	int column;
    char race;
    
	public:
    Level(Display * dis,int r,int c);
    std::string action;
    virtual ~Level()=0;   // make this class abstract
    virtual bool walk(std::string dir);     //the walk action of player
    virtual void attack(std::string dir);   //attack action of player
    virtual void get_item(std::string dir); //get action of player
    char getRace(){return race;}
    std::string Race(){return p->getRace();}
    virtual void use_potion();
    virtual void one_turn();
    bool playerStatus(){
        return p->getHP()>0;
    }
    virtual void summonHero(char name);     //summon hero randomly position
    virtual void Summon_Monster();  //summon random monster in randomly position
    virtual void Summon_Potion();   //summon potition in random position
    virtual void Summon_Gold(); //summon differet type of gold in random position

};

#endif





