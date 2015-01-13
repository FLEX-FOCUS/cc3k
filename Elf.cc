//
//  Elf.cc
//  A5
//
//  Created by Jasper Wang on 14-11-17.
//  Copyright (c) 2014 Jasper Wang. All rights reserved.
//

#include "Elf.h"
#include "Player.h"
#include <cstdlib>
#include <ctime>

void Elf::attack(Player *p){
    srand((unsigned)time(NULL));
    if (rand()%2) p->defense(Att); // check whether the first attack miss
    if (p->getRace()=="drow") return;
    if (rand()%2) p->defense(Att);  // check whether the second attack miss
}