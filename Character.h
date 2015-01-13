//
//  Character.h
//  A5
//
//  Created by Jasper Wang on 14-11-15.
//  Copyright (c) 2014 Jasper Wang. All rights reserved.
//

#ifndef __A5__character__
#define __A5__character__

#include <iostream>
#include "Display.h"

class Character {
protected:
    char symbol;
    Display *d; // Character "has a" Display pointer
    int gold;
    int HP;
    std::string race;
    int Att;
    int Def;
    int x;   // the x-coordinates
    int y;   // the y-coordinates
    char prevFloor;  // get the floor beneath the character
    Character(Display *dis):d(dis),prevFloor('.'){};
public:
    virtual ~Character()=0;
    int dropGold();     // returns gold
    void setcoords(int x, int y);  // set coordinates when initialized or moved
    std::string getRace();
    void changeHP(int);
    void setDisplay(Display *dis){d=dis;}
    int getHP();
    int getX(){return x;}
    int getY(){return y;}
    void notify(int x,int y,char state);
};

#endif
