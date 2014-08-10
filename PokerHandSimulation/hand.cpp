//  hand.cpp

#include "hand.h"

void Hand::draw()
{
    deck.shuffle(100);
    for (int i = 0; i < HAND_SIZE; i++) {
        hand[i] = deck.getCard();
    }
}

Card * Hand::getHand()
{
    return hand;
}

void Hand::fold()
{
    for (int i = 0; i < HAND_SIZE; i++) {
        deck.addCard(hand[i]);
    }
}

bool Hand::pair(Card curr_hand[])
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

bool Hand::flush(Card curr_hand[])
{
    int i = 0;

    if (curr_hand[i].getSuit() == curr_hand[i+1].getSuit() && curr_hand[i+2].getSuit() == curr_hand[i+3].getSuit() && curr_hand[i].getSuit() == curr_hand[i+4].getSuit()) {
        return true;
    }

    return false;
}
