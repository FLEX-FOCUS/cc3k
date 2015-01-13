//
//  Game.cc
//  A5
//
//  Created by Jasper Wang on 14-11-19.
//  Copyright (c) 2014 Jasper Wang. All rights reserved.
//

#include "Game.h"
#include "Level.h"
#include "First.h"
#include "Fifth.h"
#include "Fourth.h"
#include "Second.h"
#include "Third.h"
#include <fstream>
#include <ncurses.h>
#include "Shade.h"
using namespace std;


// floor initialization
void Game::init(){
    ifstream f(file.c_str());            // read the file into fstream
    Display *d=new Display(column,row,f);
    d->floor = difficulty;
    // create the new floor
    switch(difficulty){
        case 1:lvl=new First(d,row,column);
            break;
        case 2: lvl=new Second(d,row,column);
            break;
        case 3: lvl=new Third(d,row,column);
            break;
        case 4:	lvl=new Fourth(d,row,column);
            break;
        case 5:	lvl=new Fifth(d,row,column);
            break;
        case 6:  //     when you pass the fifth floor (i.e. win the game)
            delete d;
            clear();
            printw("You Win!\n");
            printw("Your score is ");
            // print the score
            if (dynamic_cast<Shade *>(Player::instance)) { // if winner is Shade
                printw("%d\n",Player::instance->returnGold()*2);
            }
            else{printw("%d\n",Player::instance->returnGold());}
            printw("Do you want to play again ? y(yes) or n(no)\n");
            char input='\0';
            while (input != 'y'||input != 'n') {
                input = getch();
                if (input == 'y') {         // playing again
                    clear();
                    this->restart();
                }
                else{           // quit the game
                this->end = true;
                Player* temp= Player::instance;
                Player::instance=NULL;
                delete temp;
                delete lvl;
                return;
                }
            }
            break;
    }
    

}

void Game::playerStatus(){
    if(!lvl->playerStatus()){       //if the player's HP is 0 or lower
        clear();
        printw("You lost!\n");
        printw("Your score is ");
        // print the score
        if (dynamic_cast<Shade *>(Player::instance)) {
            printw("%d\n",Player::instance->returnGold()*2);
        }
        else{printw("%d\n",Player::instance->returnGold());}
        printw("Do you want to play again ? y(yes) or n(no)\n");
        char input='\0';
        while (input != 'y'||input != 'n') {
            input = getch();
            if (input == 'y') {         //playing again
                clear();
                this->restart();
            }
            else{                       //quit the game
                this->end = true;
                Player* temp= Player::instance;
                Player::instance=NULL;
                delete temp;
                delete lvl;
                return;
            }
        }
    }
}

// called by main to control the player's walking
void Game::walk(string dir){
    if(lvl->walk(dir)){        //if going to the the next floor or win
        if(difficulty < 5){         //if difficulty is 5(i.e. winning the game),
            delete lvl;             //delete lvl would cause double free
            lvl = NULL;}
        difficulty++;
        init();
    }
}

void Game::restart(){
    Player* temp= Player::instance;
    Player::instance=NULL;
    delete temp;
    delete lvl;
    difficulty = 1;
    init();
}

void Game::attack(string dir){
    lvl->attack(dir);
}

void Game::get_item(string dir){
    lvl->get_item(dir);
}

void Game::use_potion(){
    lvl->use_potion();
} 


