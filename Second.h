//
//  Second.h
//  A5
//
//  Created by Jasper Wang on 14-11-20.
//  Copyright (c) 2014 Jasper Wang. All rights reserved.
//

#ifndef A5_Second_h
#define A5_Second_h
#include "Level.h"
class Second:public Level{
public:
    Second(Display * dis,int r,int c):Level(dis,r,c){
        dis->setFloor(2);
    }
};

#endif
