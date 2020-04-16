// FILE: deck.h
// written by Owen Astrachan and Roger Priebe
// this class respresents a deck of cards
// When a Deck is constructed, it contains 52 cards
// in a "regular" order (aces, twos, threes, ... , kings)
//
// Shuffling a deck makes it consist of 52 cards in a random order
//
// dealCard() returns a card from the deck and decreases the
// number of cards in the deck (returned by size())
// The idea is that after shuffling, calling dealCard() 52 times
// returns each card in the deck after shuffling.
//
// Calling shuffle again replenishes the deck with 52 cards.

#ifndef _DECK_H
#define _DECK_H

#include "card.h"

class Deck
{
    static const int SIZE = 52;

public:


    //Default constructor
    //fills the myCards array with sorted and new deck
    Deck();

    /* FUNCTION - void shuffle()
     * Shuffles the deck, all 52 cards present
         input parms - None
         output parms - None
    */
    void shuffle();

    /* FUNCTION - Card dealCard()
    * Gets a card from the top of the deck
        input parms - None
        output parms - returns a card from the top of the deck
   */
    Card dealCard();

    /* FUNCTION - int  size() const
    * Checks how many cards are left in the deck
        input parms - None
        output parms - returns # cards left in the deck
   */
    int  size() const;

private:

    Card myCards[SIZE];
    int myIndex;  // current card to deal
};

#endif
