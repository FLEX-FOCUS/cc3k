//
//  Enemy.cc
//  A5
//
//  Created by Jasper Wang on 14-11-18.
//  Copyright (c) 2014 Jasper Wang. All rights reserved.
//

#include "Enemy.h"
#include <cstdlib>
#include <ctime>
using namespace std;

int Enemy::defense(int val){
    srand((unsigned)time(NULL));
    double selfDef = this->Def;
    HP -= (int)100/(100+selfDef) * val;
    if (HP <= 0) {
        isAlive = false;
    }
    if (!isAlive && this->getRace() == "human") {
        d->notify(x, y, '.');
        return 4;
    }
    if (!isAlive && this->getRace() == "merchant") {
        return 0;
    }
    else if(!isAlive) return rand()%2+1; // small pile or normal pile
    else return 0;
}

bool Enemy::observe(){
    if (!isAlive) {
        return false;
    }
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if(d->getChar(x-1+i,y-1+j) == '@'){
                return 1;
            }
        }
    }
    return 0;
}

int Enemy::BigObserve(){
    if (!isAlive) {
        return false;
    }
    int u=-10;
    int v=-10;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if(d->getChar(x-2+i,y-2+j) == '@'){
                u=-2+i;
                v=-2+j;
                if(u==0){
                    if(v>0)
                        return 2;
                    else return 1;
                }
                else if(v==0){
                    if(u>0)
                        return 3;
                    else return 4;
                }
                else if(u<0){
                    if(v>0)
                        return 8;
                    else return 6;
                }
                else if(u>0){
                    if(v>0)
                        return 7;
                    else return 5;
                }
                
            }
        }
    }
    

    
    return 0;
}

bool Enemy::move(){
    int tmp=0;
    if (this->observe()) {
        return true;
    }
    if (!isAlive) {
        return false;
    }
    int nextX = 0;
    int nextY = 0;
    srand((unsigned)time(NULL)-rand());
    tmp=rand();
    if (this->BigObserve()) {
        tmp = BigObserve();
    }
    
    while (d->getChar(nextX, nextY) != '.') {
        switch (tmp) {
            case 1:
                nextX = x;
                nextY = y - 1;
                break;
            case 2:
                nextX = x;
                nextY = y + 1;
                break;
            case 3:
                nextX = x + 1;
                nextY = y;
                break;
            case 4:
                nextX = x - 1;
                nextY = y;
                break;
            case 5:
                nextX = x + 1;
                nextY = y - 1;
                break;
            case 6:
                nextX = x - 1;
                nextY = y - 1;
                break;
            case 7:
                nextX = x + 1;
                nextY = y + 1;
                break;
            case 8:
                nextX = x - 1;
                nextY = y + 1;
                break;
        }
        tmp = rand()%8+1;
    }
    d->notify(x, y, prevFloor);
    x=nextX;
    y=nextY;
    prevFloor = d->getChar(x, y);
    d->notify(x, y, symbol);
    //cout << "hey" << endl;
    if (this->observe()) {
        return true;
    }
    else return false;
}



