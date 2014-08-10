//  game1.h

#ifndef Poker_Lab_game1_h
#define Poker_Lab_game1_h

#include "card.h"
#include "deck.h"

const int HANDSIZE = 5;

class Game1 {
private:
    Card hand[HANDSIZE];
    Deck deck;
public:
    void draw();
    void fold();
    bool pair(Card curr_hand[]);
    bool flush(Card curr_hand[]);
    void runGame(int trials);
};

#endif
