//
// Created by jezzy on 4/13/2020.
//

#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include "player.h"
#include "card.h"
#include "deck.h"

using namespace std;

    Player::Player() {
        myName = "";
    }

    Player::Player(string name){
        myName = name;
    }

    void Player::addCard(Card c) {
        myHand.push_back(c);
    }

    void Player::bookCards(Card c1, Card c2) {
        myBook.push_back(c1);
        myBook.push_back(c2);
    }

    //OPTIONAL
    // comment out if you decide to not use it
    //this function will check a players hand for a pair.
    //If a pair is found, it returns true and populates the two variables with the cards tha make the pair.

    bool Player::checkHandForBook(Card &c1, Card &c2) {
        return (c1.getRank()==c2.getRank());
    }

    //OPTIONAL
    // comment out if you decide to not use it
    //Does the player have a card with the same rank as c in her hand?
    bool Player::rankInHand(Card c) const {
        for(int i=0;i<myHand.size();i++){
            if(myHand[i].getRank()==c.getRank()){
                return true;
            }
        }
        return false;
    }

    //uses some strategy to choose one card from the player's
    //hand so they can say "Do you have a 4?"
    Card Player::chooseCardFromHand() const {
        Card c;
        int size = myHand.size();
        unsigned int currentTime = (unsigned) time(0);
        srand(currentTime);
        long index = (rand() % size);
        c = myHand[index];
        return c;
    }

    //Does the player have the card c in her hand?
    bool Player::cardInHand(Card c) const {
        for(int i=0; i<myHand.size();i++){
            if((myHand[i].toString()==c.toString())){
                return true;
            }
        }
        return false;
    }

    //Remove the card c from the hand and return it to the caller
    //Remove all cards that have the same rank
    Card Player::removeCardFromHand(Card c) {
        for(int i=myHand.size()-1;i>=0;i--){
            if(myHand[i].getRank()==c.getRank()){
                myHand.erase(myHand.begin()+i);
            }
        }
        return c;
    }

    void Player :: removeAllCardsSameRank(Card c, Player &p){
        for(int i=myHand.size()-1;i>=0;i--){
            if(myHand[i].getRank()==c.getRank()){
                p.myHand.push_back(myHand[i]);
                myHand.erase(myHand.begin()+i);
            }
        }
    }

    string Player::showHand() const {
        string s;
        for(int i=0;i<myHand.size();i++){
            s += myHand[i].toString();
            s += " ";
        }
        return s;
    }

    string Player::showBooks() const {
        string s;
        for(int i=0;i<myBook.size();i++){
            s += myBook[i].toString();
            s += " ";
        }
        return s;
    }

    int Player::getHandSize() const {
        return myHand.size();
    }

    int Player::getBookSize() const {
        return myBook.size();
    }

    //OPTIONAL
    // comment out if you decide to not use it
    //this function will check a players hand for a pair.
    //If a pair is found, it returns true and populates the two variables with the cards tha make the pair.

    bool Player::checkHandForPair(Card &c1, Card &c2) {

    }

    //OPTIONAL
    // comment out if you decide to not use it
    //Does the player have a card with the same rank as c in her hand?
    //e.g. will return true if the player has a 7d and the parameter is 7c

    bool Player::sameRankInHand(Card c) const {

    }

    void Player::checkPairToBook() {
        if (myHand.size()>1) {
            Card c(0, Card::clubs);
            for (int i = 0; i < myHand.size() - 1; i++) {
                for (int j = i + 1; j < myHand.size(); j++) {
                    if ((checkHandForBook(myHand[i], myHand[j])) && (myHand[i] != c)) {
                        myBook.push_back(myHand[i]);
                        myBook.push_back(myHand[j]);
                        cout << myName << " booked " << myHand[i].toString() << " and " << myHand[j].toString() << endl;
                        myHand[i] = c;
                        myHand[j] = c;
                    }
                }
            }
            for (int i = myHand.size() - 1; i >= 0; i--) {
                if (myHand[i] == c) {
                    myHand.erase(myHand.begin() + i);
                }
            }
        }
    }


