// FILE:  player.h
// written by Roger Priebe
// 1/22/08 (revised 9/2/08)
// This class represents a player in a card game that takes "tricks"
// The "Books" represent a container for holding tricks

#ifndef _PLAYER_H
#define _PLAYER_H

#include <iostream>
#include <string>
#include <vector>
#include "card.h"

using namespace std;


class Player
{
public:

    //Default constructor
    //leaves the name blank
    Player();

    //Constructor with name parameter
    //set the name to the input parameter
    Player(string name);

    /* FUNCTION - string getName() const
    * Gets the name of the player
        input parms - None
        output parms - returns the name as a string
    */
    string getName() const {
        return myName;
    }

    /* FUNCTION - void addCard(Card c)
    * Adds a card to the hand
        input parms - Card that will be added
        output parms - None
    */
    void addCard(Card c);

    /* FUNCTION - void bookCards(Card c1, Card c2)
    * Books a pair of card
        input parms - Cards that will be booked
        output parms - None
    */
    void bookCards(Card c1, Card c2);

    /* FUNCTION - bool checkHandForBook(Card &c1, Card &c2)
    * this function will check a players hand for a pair.
    * If a pair is found, it returns true and populates the two variables with the cards tha make the pair.
        input parms - Cards that will be checked if they are pairs
        output parms - true if pair is found
                       false if pair is not found
    */
    bool checkHandForBook(Card &c1, Card &c2);

    /* FUNCTION - bool rankInHand(Card c) const
    * Does the player have a card with the same rank as c in her hand?
        input parms - Cards that will be compared to
        output parms - true if same rank
                       false if not the same rank
    */
    bool rankInHand(Card c) const;

    /* FUNCTION - Card chooseCardFromHand() const
    * uses some strategy to choose one card from the player's
    * hand so they can say "Do you have a 4?"
        input parms - None
        output parms - returns a card from players hand
    */
    Card chooseCardFromHand() const;

    /* FUNCTION - bool cardInHand(Card c) const
    * Does the player have the card c in her hand?
        input parms - Card that is checked for
        output parms - true if player has the card
                       false if player does not have the card
   */
    bool cardInHand(Card c) const;

    /* FUNCTION - Card removeCardFromHand(Card c)
    * Remove the card c from the hand and return it to the caller
        input parms - Card that will be removed
        output parms - returns the card that is removed
    */
    Card removeCardFromHand(Card c);

    /* FUNCTION - string showHand() const
    * Converts all of the player's card into one string together
        input parms - None
        output parms - returns string of all of the player's cards
    */
    string showHand() const;

    /* FUNCTION - string showBooks() const
    * Converts all of the booked cards of the player into one string together
        input parms - None
        output parms - returns string of all of the player's booked cards
    */
    string showBooks() const;

    /* FUNCTION - int getHandSize() const
    * Gets the number of cards the player has
        input parms - None
        output parms - returns the number of cards the player has
    */
    int getHandSize() const;

    /* FUNCTION - int getBookSize() const
    * Gets the number of booked pairs the player has
        input parms - None
        output parms - returns the number of booked cards the player has
    */
    int getBookSize() const;

    //OPTIONAL
    // comment out if you decide to not use it
    //this function will check a players hand for a pair.
    //If a pair is found, it returns true and populates the two variables with the cards tha make the pair.

//    bool checkHandForPair(Card &c1, Card &c2);

    //OPTIONAL
    // comment out if you decide to not use it
    //Does the player have a card with the same rank as c in her hand?
    //e.g. will return true if the player has a 7d and the parameter is 7c

//    bool sameRankInHand(Card c) const;

    //new functions
    // check if the hand has any pair, if yes, push to the book deck
 //   void checkPairToBook();

private:

    vector <Card> myHand;
    vector <Card> myBook;

    string myName;

};


#endif
