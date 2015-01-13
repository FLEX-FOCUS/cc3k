//
//  shade.h
//  A5
//
//  Created by Jasper Wang on 14-11-17.
//  Copyright (c) 2014 Jasper Wang. All rights reserved.
//

#ifndef __A5__shade__
#define __A5__shade__

#include <iostream>
#include "Player.h"
class Enemy;

class Shade: public Player{
public:
    Shade(Display *tp):Player(tp){
        race = "shade";
        HP = 125;
        Att = 25;
        Def = 25;
    }
    void attack(Enemy *);
};

#endif /* defined(__A5__shade__) */
