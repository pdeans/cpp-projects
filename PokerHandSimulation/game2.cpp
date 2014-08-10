//  game2.cpp

#include <stdlib.h>
#include <iostream>
#include <iomanip>
#include <fstream>
#include "hand.h"
#include "game2.h"

using namespace std;

extern ofstream csis2;

void Game2::runGame(int trials)
{
    Hand h;
    Card *hp;
    int no_pair,
        no_flush,
        trial_no = 1;
    double pair_per,
           flush_per;

    cout << setw(9) << "Trial #" << setw(12) << "# of Hands" << setw(12) << "# of Pairs" << setw(15) << "# of Flushes" << setw(20) << "Pair Percentage" << setw(20) << "Flush Percentage" << endl;
    cout << setw(9) << "-------" << setw(12) << "----------" << setw(12) << "----------" << setw(15) << "------------" << setw(20) << "---------------" << setw(20) << "----------------" << endl;
    csis2 << setw(9) << "Trial #" << setw(12) << "# of Hands" << setw(12) << "# of Pairs" << setw(15) << "# of Flushes" << setw(20) << "Pair Percentage" << setw(20) << "Flush Percentage" << endl;
    csis2 << setw(9) << "-------" << setw(12) << "----------" << setw(12) << "----------" << setw(15) << "------------" << setw(20) << "---------------" << setw(20) << "----------------" << endl;
    for (int i = 0; i < 10; i++ ) {
        no_pair = 0;
        no_flush = 0;

        for (int i = 0; i < trials; i++ ) {
            h.draw();
            hp = h.getHand();

            if (h.pair(hp)) {
                no_pair++;
            }

            if (h.flush(hp)) {
                no_flush++;
            }

            h.fold();
        }
        pair_per = double(no_pair) / trials;
        flush_per = double(no_flush) / trials;

        cout << fixed << setprecision(2) << setw(9) << trial_no << setw(12) << trials << setw(12) << no_pair << setw(15) << no_flush << setw(20) << pair_per << setw(20) << flush_per << endl;
        csis2 << fixed << setprecision(2) << setw(9) << trial_no << setw(12) << trials << setw(12) << no_pair << setw(15) << no_flush << setw(20) << pair_per << setw(20) << flush_per << endl;
        trial_no++;
    }

}
