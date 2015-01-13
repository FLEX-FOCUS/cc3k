//
//  Troll.cc
//  A5
//
//  Created by Jasper Wang on 14-11-17.
//  Copyright (c) 2014 Jasper Wang. All rights reserved.
//

#include "Troll.h"
#include "Enemy.h"
#include <cstdlib>
#include <ctime>

void Troll::attack(Enemy *e){
    srand((unsigned)time(NULL));
    if (e->getRace() == "halfling" && rand()%2) {
        return;
    }
    gold += e->defense(Att+attBuff);
    if (this->getHP() <= 115) {
        this->changeHP(5);
    }
}