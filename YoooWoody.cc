//
//  YoooWoody.cpp
//  A5
//
//  Created by Jasper Wang on 14-11-26.
//  Copyright (c) 2014年 Jasper Wang. All rights reserved.
//

#include "YoooWoody.h"
#include "Enemy.h"
#include <cstdlib>
#include <ctime>

void YoooWoody::attack(Enemy *e){
    srand((unsigned)time(NULL));
    gold += e->defense(Att+attBuff);
    Att -= 200;
}