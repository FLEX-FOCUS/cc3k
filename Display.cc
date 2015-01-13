//
//  Display.cc
//  A5
//
//  Created by Jasper Wang on 14-11-16.
//  Copyright (c) 2014 Jasper Wang. All rights reserved.
//

#include "Display.h"
#include <fstream>
#include <iomanip>
#include <ncurses.h>
using namespace std;
#include<iostream>
#include<string>

void Display::notify(int col, int row, char c){
    graphDisplay[row][col] = c;
}

Display::Display(int x, int y, ifstream& f):X(x),Y(y){
    graphDisplay = new char*[Y];
    for (int i = 0; i < Y; i++) {
        graphDisplay[i] = new char[X+1];
        string s;
        getline(f, s);
        //graphDisplay[i] = (char *)s.c_str();
        for(int j = 0;j<X;j++){
            graphDisplay[i][j]=s.at(j);
        }
        graphDisplay[i][X]='\0';
    }
}
void Display::notifyStat(int hp,int att,int def,int gold,std::string r){
    race = r;
    HP = hp;
    Att = att;
    Def = def;
    Gold = gold;
}

char Display::getChar(int col, int row){
    return graphDisplay[row][col];
}

bool Display::check_help(int x, int y,int a[25][79]){
    if(a[y][x]==0){
        return false;
    }
    switch(graphDisplay[y][x]) {
        case '/': return true;
        case '|': return false;
        case '-': return false;
        case '+': return false;
        case '.': a[y][x]=0;
                  break;
    }
    
    return check_help(x, y+1,a)||check_help(x, y-1,a)||check_help(x-1, y,a)||check_help(x+1, y,a);
}


/*
 * called by Level::Summon_Hero when set the position of the player
 * return true if the stage is in same chamber relative to this position
 * false otherwise
 */
bool Display::check(int x,int y){
    int a[25][79];
    for(int i=0;i<25;i++){
        for(int j=0;j<79;j++)
            a[i][j]=-1;}
    return check_help(x,y,a);
}

/*
 * print the result on the screen
 */
void print(const Display &d){
    for (int i = 0; i < d.Y; i++) {
        printw("%s\n",d.graphDisplay[i]);
    }
    printw("Race: %-30s Gold: %-28d",d.race.c_str(), d.Gold);
    printw("Floor: %d\n",d.floor);
    printw("HP: %d\n",d.HP);
    printw("Atk: %d\n",d.Att);
    printw("Def: %d\n",d.Def);
    printw("Action: ");

}


// Destructor of Display
Display::~Display(){
    // free the 2D array on the heap
    for(int i = 0; i < Y; i++){
        delete [] graphDisplay[i];
    }
    delete [] graphDisplay;
}
