//
//  Elf.h
//  A5
//
//  Created by Jasper Wang on 14-11-17.
//  Copyright (c) 2014 Jasper Wang. All rights reserved.
//

#ifndef __A5__Elf__
#define __A5__Elf__

#include <iostream>
#include "Enemy.h"
class Player;
class Elf: public Enemy{
public:
    Elf(Display *tp):Enemy(tp){
        symbol='E';
        race = "elf";
        HP = 140;
        Att = 30;
        Def = 10;
    }
    void attack(Player *);
};


#endif /* defined(__A5__Elf__) */
