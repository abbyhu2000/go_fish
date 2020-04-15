#include "card.h"
#include <string>
#include <ctime>
#include <cstdlib>

using namespace std;

Card::Card(){
    myRank = 1;
    mySuit = spades;
}

Card::Card(int rank, Suit s){
    myRank = rank;
    mySuit = s;
}

string Card::toString() const{
    string s = suitString(mySuit);
    string r = rankString(myRank);

    return(r + s);
}

bool Card::sameSuitAs(const Card& c) const{
    return (c.mySuit == mySuit);
}

int  Card::getRank() const{
    return myRank;
}

string Card::suitString(Suit s) const {
    switch (s) {
        case spades: return "s";
        case hearts: return "h";
        case diamonds: return "d";
        case clubs: return "c";
    }
}

string Card::rankString(int r) const{
    switch(r){
        case 1: return "A";
        case 11: return "J";
        case 12: return "Q";
        case 13: return "K";
        default: return to_string(r);
    }
}

bool Card::operator == (const Card& rhs) const{
    return ((rhs.myRank == myRank) && (rhs.mySuit == mySuit));
}

bool Card::operator != (const Card& rhs) const{
    return ((rhs.myRank != myRank) || (rhs.mySuit != mySuit));
}

