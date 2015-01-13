//
//  Third.h
//  A5
//
//  Created by Jasper Wang on 14-11-20.
//  Copyright (c) 2014 Jasper Wang. All rights reserved.
//

#ifndef A5_Third_h
#define A5_Third_h
#include "Level.h"
class Third:public Level{
public:
    Third(Display * dis,int r,int c):Level(dis,r,c){
        dis->setFloor(3);
    }

};

#endif
