/******************************************************************************
 Program Name:      main.cpp (Poker Hand Simulation Driver)
 Author:            Patrick Stearns
 Date:              July 1, 2014
 Class:             CSCI 222
 OS:                OS X 10.9.3
 Description:       Poker hand simulation; 10 trials each @ 10,000 hands dealt
 Input Files:       None
 Output Files:      csis1.txt, csis2.txt
 ******************************************************************************/

#include <stdlib.h>
#include <iostream>
#include <time.h>
#include <fstream>
#include "game1.h"
#include "game2.h"
#include "hand.h"

using namespace std;

ofstream csis1;
ofstream csis2;

int main(int argc, const char * argv[])
{
    Game1 game1;
    Game2 game2;

    srand((unsigned)time(NULL));

    csis1.open("csis1.txt");
    csis2.open("csis2.txt");

    cout << "Game 1:\n\n";
    csis1 << "Game 1:\n\n";
    game1.runGame(10000);

    cout << "Game 2:\n\n";
    csis2 << "Game 2:\n\n";
    game2.runGame(10000);

    csis1.close();
    csis2.close();

    return 0;
}

