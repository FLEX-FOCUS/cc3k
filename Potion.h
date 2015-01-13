//
//  Potion.h
//  A5
//
//  Created by Jasper Wang on 14-11-18.
//  Copyright (c) 2014 Jasper Wang. All rights reserved.
//

#ifndef __A5__Potion__
#define __A5__Potion__

#include <iostream>
#include "Item.h"

class Potion: public Item{
    std::string name;
public:
    Potion(std::string n, Display *dp):Item(dp),name(n){
    symbol='P';}
    std::string getName(){return name;}
};

#endif /* defined(__A5__Potion__) */
