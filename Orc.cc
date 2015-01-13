//
//  Orc.cc
//  A5
//
//  Created by Jasper Wang on 14-11-16.
//  Copyright (c) 2014 Jasper Wang. All rights reserved.
//

#include "Orc.h"
#include "Player.h"
#include <cstdlib>
#include <ctime>

void Orc::attack(Player *p){
    srand((unsigned)time(NULL));
    if (rand()%2)return;
    if (p->getRace() == "goblin") {
        p->defense(Att*1.5);
    }
    else p->defense(Att);
}