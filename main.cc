//
//  main.cc
//  A5
//
//  Created by Jasper Wang on 14-11-15.
//  Copyright (c) 2014 Jasper Wang. All rights reserved.
//

#include <iostream>
using namespace std;
#include "Game.h"
#include "Display.h"
#include "Player.h"
#include "allChara.h"
#include "Level.h"
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <ncurses.h>

int main(int argc, const char * argv[]) {
    initscr();       //init screen for ncurser purpose
    int input;       //receive the input from the keyboard,KEY_UP,DOWN etc
    Game g;
    if(argv[1]){     //check if there is command field for customized map
        g.file = argv[1];
    }
    else {g.file = "grid.txt";} //otherwise use default map
    noecho();
    printw("Welcome to CC3K, do you want to play or quit\n");
    raw();
    keypad(stdscr, true);       //Enure you can use KEY_UP,KEY_DOWN,etc
    while ((input=getch())) {
        if (input == 27||g.end) {       //when press ESC
            Player* temp= Player::instance;    //Delete player character
            Player::instance=NULL;
            delete temp;
            g.empty_level();            //delete the level
            break;
        }
        else if(input == 'p'){          //play the game
            g.init();
            if (g.end) {                //if the game is end
                break;
            }
        }
        else if(input == ' '){          //space is the attack command
            input=getch();              //get the attack direction
            if (input == 'w'||input == KEY_UP){g.attack("no");}
            else if (input == 'e'){g.attack("ne");}
            else if (input == 'd'||input == KEY_RIGHT){g.attack("ea");}
            else if (input == 'c'){g.attack("se");}
            else if (input == 'x'||input == KEY_DOWN){g.attack("so");}
            else if (input == 'z'){g.attack("sw");}
            else if (input == 'a'||input == KEY_LEFT){g.attack("we");}
            else if (input == 'q'){g.attack("nw");}
            else printw("invalid command\n");
            continue;
        }
        else if (input == 'g'){         //g is 'get' command
            input=getch();              //choose the direction of items to pick
            if (input == 'w'||input == KEY_UP){g.get_item("no");}
            else if (input == 'e'){g.get_item("ne");}
            else if (input == 'd'||input == KEY_RIGHT){g.get_item("ea");}
            else if (input == 'c'){g.get_item("se");}
            else if (input == 'x'||input == KEY_DOWN){g.get_item("so");}
            else if (input == 'z'){g.get_item("sw");}
            else if (input == 'a'||input == KEY_LEFT){g.get_item("we");}
            else if (input == 'q'){g.get_item("nw");}
            else printw("invalid command\n");
            continue;
        }
        else if (input == 'r'){         //r is 'restart' command
            clear();                 //clear the window(termainl),nurcuser only
            g.restart();
        }
        else if (input == 'u'){       //u is the 'use command'
            clear();
            g.use_potion();           //use the last potion you get
        }
        if (g.end) {                    //if the game is end
            break;
        }
        
        //below is the walk command. To make the player move
        //KEY_UP KEY_DOWN,KEY_LEFT,KEY_RIGHT, or WAXD
        //will respond to up down left and right
        //'q' 'e' 'z' 'd' respond to northwest, northeast
        //southwest,southeast respectively
        else if (input == 'w'||input == KEY_UP){g.walk("no");
                printw(" I am going north\n");}
        else if (input == 'e'){g.walk("ne");
                printw(" I am going north-west\n");}
        else if (input == 'd'||input == KEY_RIGHT){g.walk("ea");
                printw(" I am going east\n");}
        else if (input == 'c'){g.walk("se");
            printw(" I am going south-east\n");}
        else if (input == 'x'||input == KEY_DOWN){g.walk("so");
            printw(" I am going south\n");}
        else if (input == 'z'){g.walk("sw");
            printw(" I am going south-west\n");}
        else if (input == 'a'||input == KEY_LEFT){g.walk("we");
            printw(" I am going west\n");}
        else if (input == 'q'){g.walk("nw");
            printw(" I am going north-west\n");}
        g.playerStatus();    //make g.end to true if the player's HP
        if (g.end) {         //become 0 or lower
            break;
        }
        refresh();          //refresh the terminal, ncurser only
    }
    endwin();               //end the window, ncurser only
}

