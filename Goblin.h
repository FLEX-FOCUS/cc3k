//
//  Goblin.h
//  A5
//
//  Created by Jasper Wang on 14-11-17.
//  Copyright (c) 2014 Jasper Wang. All rights reserved.
//

#ifndef __A5__Goblin__
#define __A5__Goblin__

#include <iostream>
#include "Player.h"
class Enemy;
class Goblin: public Player{
public:
    Goblin(Display *tp):Player(tp){
        race = "goblin";
        HP = 110;
        Att = 15;
        Def = 20;
    }
    void attack(Enemy *);
};


#endif /* defined(__A5__Goblin__) */
