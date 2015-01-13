//
//  Human.h
//  A5
//
//  Created by Jasper Wang on 14-11-17.
//  Copyright (c) 2014 Jasper Wang. All rights reserved.
//

#ifndef __A5__Human__
#define __A5__Human__

#include <iostream>
#include "Enemy.h"

class Player;
class Human: public Enemy{
public:
    Human(Display *tp):Enemy(tp){
        symbol ='H';
        race = "human";
        HP = 140;
        Att = 20;
        Def = 20;
    }
    void attack(Player *);
};


#endif /* defined(__A5__Human__) */
