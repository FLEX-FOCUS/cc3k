//
//  Item.h
//  A5
//
//  Created by Jasper Wang on 14-11-18.
//  Copyright (c) 2014 Jasper Wang. All rights reserved.
//

#ifndef __A5__Item__
#define __A5__Item__

#include <iostream>
#include "Display.h"

class Item {
protected:
    char symbol;
    bool isExist;
    Display *d;
    int x;
    int y;
public:
    Item(Display *dp):isExist(true),d(dp){}
    bool getStatus(){return isExist;}   //check whether it can be picked up
    void removal();         // remove it from display & make it not pickable
    void setcoords(int X, int Y){x=X;y=Y;d->notify(x, y, symbol);}
    int getX(){return x;}
    int getY(){return y;}
};

#endif /* defined(__A5__Item__) */
