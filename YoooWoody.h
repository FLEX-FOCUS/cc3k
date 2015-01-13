//
//  YoooWoody.h
//  A5
//
//  Created by Jasper Wang on 14-11-26.
//  Copyright (c) 2014年 Jasper Wang. All rights reserved.
//

#ifndef __A5__YoooWoody__
#define __A5__YoooWoody__

#include <stdio.h>
#include <iostream>
#include "Player.h"
class Enemy;

class YoooWoody: public Player{
public:
    YoooWoody(Display *tp):Player(tp){
        race = "YoooWoody the Empire!";
        HP = 1;
        Att = 666999;
        Def = 10000;
    }
    void attack(Enemy *);
};
#endif /* defined(__A5__YoooWoody__) */
