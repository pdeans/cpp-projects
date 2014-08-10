//  hand.h

#ifndef __Poker_Lab__hand__
#define __Poker_Lab__hand__

#include "card.h"
#include "deck.h"

const int HAND_SIZE = 5;

class Hand {
private:
    Deck deck;
    Card hand[HAND_SIZE];
public:
    void draw();
    Card * getHand();
    void fold();
    bool pair(Card curr_hand[]);
    bool flush(Card curr_hand[]);
};

#endif
