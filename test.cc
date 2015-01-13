#include <iostream>
#include "Display.h"
#include <fstream>
#include <string>
using namespace std;

int main(int argc, const char * argv[]) {
    string input;
    ifstream *f=new ifstream("/Users/jasperwang/Desktop/A5/A5/grid.txt");
    Display d(79,25,*f);
    cout << d << endl;
}
