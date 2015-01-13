//
//  Fifth.h
//  A5
//
//  Created by Jasper Wang on 14-11-20.
//  Copyright (c) 2014 Jasper Wang. All rights reserved.
//

#ifndef A5_Fifth_h
#define A5_Fifth_h
#include "Level.h"
class Fifth:public Level{
public:
    Fifth(Display * dis,int r,int c):Level(dis,r,c){
        dis->setFloor(5);
    }
};

#endif
