//
//  Display.h
//  A5
//
//  Created by Jasper Wang on 14-11-16.
//  Copyright (c) 2014 Jasper Wang. All rights reserved.
//

#ifndef __Display__H__
#define __Display__H__

#include <iostream>
#include <iosfwd>
class Display {
    char **graphDisplay;
    int X;   // number of total x-coordinates
    int Y;   // number of total y-coordinates
    // the following are for text-display
    int HP;
    int Att;
    int Def;
    int Gold;
    std::string race;
    bool check_help(int x, int y,int a[25][79]); // helper function for check

public:
    int floor;
    Display(int,int,std::ifstream &);
    void notify(int x, int y, char c);   // change char in (x,y) to c
    void notifyStat(int,int,int,int,std::string);
    ~Display();         // change the text-display fields
    friend void print(const Display &d);
    bool check(int,int);    // see cc file
    char getChar(int,int);
    void setFloor(int f){floor = f;}
};

#endif
