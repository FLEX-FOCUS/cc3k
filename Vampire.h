//
//  Vampire.h
//  A5
//
//  Created by Jasper Wang on 14-11-17.
//  Copyright (c) 2014 Jasper Wang. All rights reserved.
//

#ifndef __A5__Vampire__
#define __A5__Vampire__

#include <iostream>
#include "Player.h"
class Enemy;
class Vampire: public Player{
public:
    Vampire(Display *tp):Player(tp){
        race = "vampire";
        HP = 50;
        Att = 25;
        Def = 25;
    }
    void attack(Enemy *);
};

#endif /* defined(__A5__Vampire__) */
