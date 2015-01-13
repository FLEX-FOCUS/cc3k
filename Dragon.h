//
//  Dragon.h
//  A5
//
//  Created by Jasper Wang on 14-11-17.
//  Copyright (c) 2014 Jasper Wang. All rights reserved.
//

#ifndef __A5__Dragon__
#define __A5__Dragon__

#include <iostream>
#include "Enemy.h"
class Player;
class Dragon: public Enemy{
    int hoard_x;        // x-coordinate for hoard
    int hoard_y;        // y-coordinate for hoard
public:
    Dragon(Display *tp, int hx, int hy):Enemy(tp){
        symbol='D';
        hoard_x = hx;
        hoard_y = hy;
        race = "dragon";
        HP = 150;
        Att = 20;
        Def = 20;
    }
    void attack(Player *);
    bool move();        // override the virtual method in Enemy
    bool observe();     // override the virtual method in Enemy
    int get_hx(){return hoard_x;}
    int get_hy(){return hoard_y;}
};


#endif /* defined(__A5__Dragon__) */
