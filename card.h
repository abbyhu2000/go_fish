//File Name: card.h
//
//Written by Owen Astrachan and Roger Priebe
// This class represents a playing card, i.e., "ace of spades"
// a Card is constructed from a rank (int in range 1..13)
// and a suit (Card::spades, Card::hearts, Card::diamonds,
// Card::clubs)
//
// Cards should be created by a Deck (see deck.h), a Deck returns
// good cards
// The function toString() converts a card to a string, e.g., to print
//
// Accessor functions include
//
// int GetRank()      -- returns 1, 2, ..., 13 for ace, two, ..., king
//
// bool SameSuitAs(c) -- returns true if same suit as Card c
//
// string suitString() -- returns "s", "h", "d" or "c"
//
// Note that the Ace is represented by 1 and the King by 13

#ifndef _CARD_H
#define _CARD_H

#include <iostream>
#include <string>
using namespace std;

class Card
{
public:


    enum Suit {spades, hearts, diamonds, clubs};

    //Default constructor
    //set the default rank to Ace (1) and default suit to spades
    Card();

    //Constructor with rank and suit parameter
    //The user of the class will pass in the rank and parameter
    //set the rank and suit to the parameters
    Card(int rank, Suit s);

    /* FUNCTION - string toString() const
    * Converts and returns the rank and suit of a card into one string
        input parms - None
        output parms - return string version e.g. Ac 4h Js
   */
    string toString() const;

    /* FUNCTION -  bool sameSuitAs(const Card& c) const
    * Checks if the input card c has the same suit as the
    * caller of the function
        input parms - Card c that is being compared to
        output parms - true if suit same as c
                       false if suit is not same as c
   */
    bool sameSuitAs(const Card& c) const;

    /* FUNCTION -   int  getRank() const
    * Gets the rank of the card
        input parms - None
        output parms - return rank, 1..13
    */
    int getRank() const;

    /* FUNCTION - string suitString(Suit s) const
    * Converts the suit into a string
        input parms - Suit of the card
        output parms - return "s", "h",...
    */
    string suitString(Suit s) const;

    /* FUNCTION - bool operator == (const Card& rhs) const
    * Checks if the rank and suit of the input card is the same
    * as the caller card.
        input parms - Card rhs that is going to be compared to
        output parms - true if rank and suit is the same
                       false if rank or suit is not the same
    */
    bool operator == (const Card& rhs) const;

    /* FUNCTION - bool operator != (const Card& rhs) const;
    * Checks if the rank and suit of the input card is not the same
    * as the caller card.
        input parms - Card rhs that is going to be compared to
        output parms - true if rank or suit is not the same
                      false if rank or suit is the same
    */
    bool operator != (const Card& rhs) const;

    /* FUNCTION - string rankString(int r) const
    * Converts the rank into a string
        input parms - rank of the card
        output parms - return "A", "2", ..."Q"
    */
    string rankString(int r) const;

private:

    int myRank;
    Suit mySuit;

};

ostream& operator << (ostream& out, const Card& c);



#endif
