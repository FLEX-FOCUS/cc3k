//
//  Game.h
//  A5
//
//  Created by Jasper Wang on 14-11-15.
//  Copyright (c) 2014 Jasper Wang. All rights reserved.
//

#ifndef __A5__Game__
#define __A5__Game__
#include <iostream>
#include "Player.h"
#include "Character.h"
#include "Display.h"
#include "Level.h"


class Game {
    int row;            //for Display initialization
    int column;         //for Display initialization
	int difficulty;     // i.e. floor
	Level * lvl;        // Game "has a" Level pointer
    
	public:
    std::string file;   // for Display initialization
    bool end;           // true if the game
    explicit Game():lvl(0){
        end = false;
        row=25;
        column=79;
        difficulty=1;
    } 
    void init();    // initialization of the floor
    void walk(std::string dir);
	void use_potion();
	void get_item(std::string dir);
	void attack(std::string dir);
    void restart();
    void empty_level(){delete lvl;}//called by main only when press ESC
    void playerStatus();        //return false if the player dies
};






#endif
