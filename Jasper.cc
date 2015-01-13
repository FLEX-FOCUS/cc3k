//
//  Jasper.cc
//  A5
//
//  Created by Jasper Wang on 14-11-26.
//  Copyright (c) 2014年 Jasper Wang. All rights reserved.
//

#include "Jasper.h"
#include "Enemy.h"
#include <cstdlib>
#include <ctime>

void Jasper::attack(Enemy *e){
    srand((unsigned)time(NULL));
    gold += e->defense(Att+attBuff);
    Att += 2;
}
