//
//  Enemy.h
//  A5
//
//  Created by Jasper Wang on 14-11-18.
//  Copyright (c) 2014 Jasper Wang. All rights reserved.
//

#ifndef __A5__Enemy__
#define __A5__Enemy__

#include <iostream>
#include "Character.h"
class Player;

class Enemy: public Character{
protected:
    bool isAlive;
public:
    bool getStatus(){return isAlive;}
    Enemy(Display *d):Character(d),isAlive(true){}
    int defense(int); // return gold if dead, 0 otherwise
    virtual bool move();   // called by Level when the player is moved
    virtual bool observe();  // check whether the player is around
    virtual void attack(Player *)=0;
    int BigObserve();
};

#endif /* defined(__A5__Enemy__) */
