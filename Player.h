//
//  Player.h
//  A5
//
//  Created by Jasper Wang on 14-11-15.
//  Copyright (c) 2014 Jasper Wang. All rights reserved.
//

#ifndef __A5__Player__
#define __A5__Player__

#include <iostream>
#include "Character.h"
#include "Display.h"
#include <vector>

class Gold;
class Potion;
class Enemy;

class Player: public Character{
protected:
    int attBuff;  // track the effects of ATT potions
    int defBuff;  // track the effects of DEF potions
    int weapon;
    //std::vector<int> armor;
    std::vector <Potion *> Inventory;
   
public:
    static Player * instance;
    bool isEnemy;   // mainly called by Merchant
    ~Player(){
        Inventory.clear();
        //armor.clear();
    }
    Player(Display *d):Character(d),isEnemy(false){
        symbol='@';
        isEnemy = false;
    }
    static Player * getInstance(Display *d,char race);
    
    void changeAtt(int val);
    void changeDef(int val);
    void defense(int);
    int walk(std::string);
    void usePotion();
    int returnGold(){return gold;}
    void getGold(Gold *);
    void getPotion(Potion *);
    int getAtt(){return Att;}
    int getDef(){return Def;}
    virtual void attack(Enemy *)=0;
};

#endif /* defined(__A5__player__) */
