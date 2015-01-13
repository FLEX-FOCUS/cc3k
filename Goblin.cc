//
//  Goblin.cc
//  A5
//
//  Created by Jasper Wang on 14-11-17.
//  Copyright (c) 2014 Jasper Wang. All rights reserved.
//

#include "Goblin.h"
#include "Enemy.h"
#include <cstdlib>
#include <ctime>

void Goblin::attack(Enemy *e){
    srand((unsigned)time(NULL));
    if (e->getRace() == "halfling" && rand()%2) {
        return;
    }
    int tmp = e->defense(Att+attBuff);
    if (tmp) {
        gold += tmp;
        gold += 5;   // steal gold
    }
    
}