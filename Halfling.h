//
//  Halfling.h
//  A5
//
//  Created by Jasper Wang on 14-11-17.
//  Copyright (c) 2014 Jasper Wang. All rights reserved.
//

#ifndef __A5__Halfling__
#define __A5__Halfling__

#include <iostream>
#include "Enemy.h"
class Player;
class Halfling: public Enemy{
public:
    Halfling(Display *tp):Enemy(tp){
        symbol='L';
        race = "halfling";
        HP = 100;
        Att = 15;
        Def = 20;
    }
    void attack(Player *);
};


#endif /* defined(__A5__Halfling__) */
