//
//  shade.cc
//  A5
//
//  Created by Jasper Wang on 14-11-17.
//  Copyright (c) 2014 Jasper Wang. All rights reserved.
//

#include "Shade.h"
#include "Enemy.h"
#include <cstdlib>
#include <ctime>

void Shade::attack(Enemy *e){
    srand((unsigned)time(NULL));
    if (e->getRace() == "halfling" && rand()%2) {
        return;
    }
    gold += e->defense(Att+attBuff);
}