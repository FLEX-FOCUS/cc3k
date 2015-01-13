//
//  Gold.h
//  A5
//
//  Created by Jasper Wang on 14-11-18.
//  Copyright (c) 2014 Jasper Wang. All rights reserved.
//

#ifndef __A5__Gold__
#define __A5__Gold__

#include <iostream>
#include "Item.h"

class Gold: public Item{
    int value;
public:
    bool get;
    Gold(bool get,int val, Display *dp):Item(dp),value(val),get(get){
        symbol='G';
    }
    int getValue(){return value;}
};

#endif /* defined(__A5__Gold__) */
