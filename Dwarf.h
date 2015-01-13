//
//  Dwarf.h
//  A5
//
//  Created by Jasper Wang on 14-11-17.
//  Copyright (c) 2014 Jasper Wang. All rights reserved.
//

#ifndef __A5__Dwarf__
#define __A5__Dwarf__

#include <iostream>
#include "Enemy.h"
class Player;
class Dwarf: public Enemy{
public:
    Dwarf(Display *tp):Enemy(tp){
        race = "dwarf";
        symbol='D';
        HP = 100;
        Att = 20;
        Def = 30;
    }
    void attack(Player *);
};


#endif /* defined(__A5__Dwarf__) */
