//
//  Drow.h
//  A5
//
//  Created by Jasper Wang on 14-11-17.
//  Copyright (c) 2014 Jasper Wang. All rights reserved.
//

#ifndef __A5__Drow__
#define __A5__Drow__

#include <iostream>
#include "Player.h"
class Enemy;
class Drow: public Player{
public:
    Drow(Display *tp):Player(tp){
        race = "drow";
        HP = 150;
        Att = 25;
        Def = 15;
    }
    void attack(Enemy *);
};

#endif /* defined(__A5__Drow__) */
