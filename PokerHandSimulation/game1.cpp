//  game1.cpp

#include <stdlib.h>
#include <iostream>
#include <iomanip>
#include <fstream>
#include "game1.h"

using namespace std;

extern ofstream csis1;


void Game1::draw()
{
    deck.shuffle(100);
    for (int i = 0; i < HANDSIZE; i++) {
        hand[i] = deck.getCard();
    }
}

void Game1::fold()
{
    for (int i = 0; i < HANDSIZE; i++) {
        deck.addCard(hand[i]);
    }
}

bool Game1::pair(Card curr_hand[])
{
    if (curr_hand[0].getValue() == curr_hand[1].getValue()) {
        return true;
    }
    else if (curr_hand[0].getValue() == curr_hand[2].getValue()) {
        return true;
    }
    else if (curr_hand[0].getValue() == curr_hand[3].getValue()) {
        return true;
    }
    else if (curr_hand[0].getValue() == curr_hand[4].getValue()) {
        return true;
    }
    else if (curr_hand[1].getValue() == curr_hand[2].getValue()) {
        return true;
    }
    else if (curr_hand[1].getValue() == curr_hand[3].getValue()) {
        return true;
    }
    else if (curr_hand[1].getValue() == curr_hand[4].getValue()) {
        return true;
    }
    else if (curr_hand[2].getValue() == curr_hand[3].getValue()) {
        return true;
    }
    else if (curr_hand[2].getValue() == curr_hand[4].getValue()) {
        return true;
    }
    else if (curr_hand[3].getValue() == curr_hand[4].getValue()) {
        return true;
    }
    else {
        return false;
    }
}

bool Game1::flush(Card curr_hand[])
{
    int i = 0;

    if (curr_hand[i].getSuit() == curr_hand[i+1].getSuit() && curr_hand[i+2].getSuit() == curr_hand[i+3].getSuit() && curr_hand[i].getSuit() == curr_hand[i+4].getSuit()) {
        return true;
    }

    return false;
}

void Game1::runGame(int trials)
{
    Game1 g;
    int no_pair,
        no_flush,
        trial_no = 1;
    double pair_per,
           flush_per;

    cout << setw(9) << "Trial #" << setw(12) << "# of Hands" << setw(12) << "# of Pairs" << setw(15) << "# of Flushes" << setw(20) << "Pair Percentage" << setw(20) << "Flush Percentage" << endl;
    cout << setw(9) << "-------" << setw(12) << "----------" << setw(12) << "----------" << setw(15) << "------------" << setw(20) << "---------------" << setw(20) << "----------------" << endl;
    csis1 << setw(9) << "Trial #" << setw(12) << "# of Hands" << setw(12) << "# of Pairs" << setw(15) << "# of Flushes" << setw(20) << "Pair Percentage" << setw(20) << "Flush Percentage" << endl;
    csis1 << setw(9) << "-------" << setw(12) << "----------" << setw(12) << "----------" << setw(15) << "------------" << setw(20) << "---------------" << setw(20) << "----------------" << endl;
    for (int i = 0; i < 10; i++ ) {
        no_pair = 0;
        no_flush = 0;

        for (int i = 0; i < trials; i++ ) {
            g.draw();

            if (g.pair(g.hand)) {
                no_pair++;
            }

            if (g.flush(g.hand)) {
                no_flush++;
            }

            g.fold();
        }
        pair_per = double(no_pair) / trials;
        flush_per = double(no_flush) / trials;

        cout << fixed << setprecision(2) << setw(9) << trial_no << setw(12) << trials << setw(12) << no_pair << setw(15) << no_flush << setw(20) << pair_per << setw(20) << flush_per << endl;
        csis1 << fixed << setprecision(2) << setw(9) << trial_no << setw(12) << trials << setw(12) << no_pair << setw(15) << no_flush << setw(20) << pair_per << setw(20) << flush_per << endl;
        trial_no++;
    }
}



