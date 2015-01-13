//
//  Merchant.h
//  A5
//
//  Created by Jasper Wang on 14-11-17.
//  Copyright (c) 2014 Jasper Wang. All rights reserved.
//

#ifndef __A5__Merchant__
#define __A5__Merchant__

#include <iostream>
#include "Enemy.h"
class Player;
class Merchant: public Enemy{
public:
    Merchant(Display *tp):Enemy(tp){
        symbol='M';
        race = "merchant";
        HP = 30;
        Att = 70;
        Def = 5;
    }
    void attack(Player *);
};


#endif /* defined(__A5__Merchant__) */
