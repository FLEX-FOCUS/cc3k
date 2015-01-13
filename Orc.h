//
//  Orc.h
//  A5
//
//  Created by Jasper Wang on 14-11-16.
//  Copyright (c) 2014 Jasper Wang. All rights reserved.
//

#ifndef __A5__Orc__
#define __A5__Orc__

#include <iostream>
#include "Enemy.h"
class Player;
class Orc: public Enemy{
public:
    Orc(Display *tp):Enemy(tp){
        symbol='O';
        race = "orc";
        HP = 180;
        Att = 30;
        Def = 25;
    }
    void attack(Player *);
};

#endif
