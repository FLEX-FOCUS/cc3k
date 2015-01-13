//
//  Troll.h
//  A5
//
//  Created by Jasper Wang on 14-11-17.
//  Copyright (c) 2014 Jasper Wang. All rights reserved.
//

#ifndef __A5__Troll__
#define __A5__Troll__

#include <iostream>
#include "Player.h"
class Enemy;
class Troll: public Player{
public:
    Troll(Display *tp):Player(tp){
        race = "troll";
        HP = 120;
        Att = 25;
        Def = 15;
    }
    void attack(Enemy *);
};

#endif /* defined(__A5__Troll__) */
