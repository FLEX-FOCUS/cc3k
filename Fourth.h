//
//  Fourth.h
//  A5
//
//  Created by Jasper Wang on 14-11-20.
//  Copyright (c) 2014 Jasper Wang. All rights reserved.
//

#ifndef A5_Fourth_h
#define A5_Fourth_h
#include "Level.h"

class Fourth:public Level{
public:
    Fourth(Display * dis,int r,int c):Level(dis,r,c){
        dis->setFloor(4);
    }
};

#endif
