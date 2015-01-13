//
//  Merchant.cc
//  A5
//
//  Created by Jasper Wang on 14-11-17.
//  Copyright (c) 2014 Jasper Wang. All rights reserved.
//

#include "Merchant.h"
#include "Player.h"
#include <cstdlib>
#include <ctime>

void Merchant::attack(Player *p){
    if (!p->isEnemy) return;
    srand((unsigned)time(NULL));
    if (rand()%2)return;
    p->defense(Att);
}