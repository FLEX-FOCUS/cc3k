//
//  Item.cc
//  A5
//
//  Created by Jasper Wang on 14-11-18.
//  Copyright (c) 2014 Jasper Wang. All rights reserved.
//

#include "Item.h"

void Item::removal(){
    isExist = false;
    d->notify(x, y, '.');
}