//
//  First.h
//  A5
//
//  Created by Jasper Wang on 14-11-20.
//  Copyright (c) 2014 Jasper Wang. All rights reserved.
//

#ifndef A5_First_h
#define A5_First_h
#include "Level.h"
#include <ncurses.h>
class First:public Level{
public:
    First(Display * dis,int r,int c):Level(dis,r,c){
        dis->setFloor(1);
    }
};
#endif
