//
//  Jasper.h
//  A5
//
//  Created by Jasper Wang on 14-11-26.
//  Copyright (c) 2014年 Jasper Wang. All rights reserved.
//

#ifndef __A5__Jasper__
#define __A5__Jasper__

#include <iostream>
#include "Player.h"
class Enemy;

class Jasper: public Player{
public:
    Jasper(Display *tp):Player(tp){
        race = "dadjasper";
        HP = 1250;
        Att = 25;
        Def = 50;
    }
    void attack(Enemy *);
};



#endif /* defined(__A5__Jasper__) */
