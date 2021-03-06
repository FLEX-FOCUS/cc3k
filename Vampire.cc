//
//  Vampire.cc
//  A5
//
//  Created by Jasper Wang on 14-11-17.
//  Copyright (c) 2014 Jasper Wang. All rights reserved.
//

#include "Vampire.h"
#include "Enemy.h"
#include <cstdlib>
#include <ctime>

void Vampire::attack(Enemy *e){
    srand((unsigned)time(NULL));
    if (e->getRace() == "halfling" && rand()%2) return;
    gold += e->defense(Att+attBuff);
    if (e->getRace() == "dwarf") {
        this->changeHP(-5);
    }
    else this->changeHP(5);
}