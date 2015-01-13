

//
//  Character.cc
//  A5
//
//  Created by Jasper Wang on 14-11-15.
//  Copyright (c) 2014 Jasper Wang. All rights reserved.
//

#include <iostream>
#include "Character.h"
using namespace std;


int Character::dropGold(){
    return gold;
}

string Character::getRace(){
    return race;
}

Character::~Character(){
}


void Character::changeHP(int val){
    HP += val;
}

int Character::getHP(){
    return HP;
}


void Character::setcoords(int X, int Y){
    x = X;
    y = Y;
    d->notify(x, y, symbol);
}


