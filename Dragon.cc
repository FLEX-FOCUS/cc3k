//
//  Dragon.cc
//  A5
//
//  Created by Jasper Wang on 14-11-17.
//  Copyright (c) 2014 Jasper Wang. All rights reserved.
//

#include "Dragon.h"
#include "Player.h"
#include <cstdlib>
#include <ctime>

void Dragon::attack(Player *p){
    srand((unsigned)time(NULL));
    if (rand()%2)return;
    p->defense(Att);
}


bool Dragon::observe(){
    if (!isAlive) {
        return false;
    }
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if(d->getChar(x-1+i,y-1+j) == '@'){
                return 1;
            }
        }
    }
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if(d->getChar(hoard_x-1+i,hoard_y-1+j) == '@'){
                return 1;
            }
        }
    }
    return 0;
}



bool Dragon::move(){
    if (!isAlive) {
        return false;
    }
    if (this->observe()) {
        return true;
    }
    else return false;
}



