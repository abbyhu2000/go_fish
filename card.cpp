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
    switch(this->myRank){
        case 1: cout<< "A";
        break;
        case 11: cout<<"J";
        break;
        case 12: cout<<"Q";
        break;
        case 13: cout<<"k";
        break;
        default: cout<<this->myRank;
    }
    switch(this->mySuit){
        case spades: cout<<"s"<<endl;
        break;
        case hearts: cout<<"h"<<endl;
        break;
        case diamonds: cout<<"d"<<endl;
        break;
        case clubs: cout<<"c"<<endl;
        break;
    }
}

bool Card::sameSuitAs(const Card& c) const{
    return c.mySuit == this->mySuit;
}

int  Card::getRank() const{
    return myRank;
}

string Card::suitString(Suit s) const {
    switch (s) {
        case spades:
            return "s";
            break;
        case hearts:
            return "h";
            break;
        case diamonds:
            return "d";
            break;
        case clubs:
            return "c";
            break;
    }
}

string Card::rankString(int r) const{
    switch(r){
        case 1: return "A";
            break;
        case 11: return "J";
            break;
        case 12: return "Q";
            break;
        case 13: return "k";
            break;

        default: return to_string(r);
    }
}

bool Card::operator == (const Card& rhs) const{
    return ((rhs.myRank==this->myRank)&&(rhs.mySuit==this->mySuit));
}

bool Card::operator != (const Card& rhs) const{
    return ((rhs.myRank!=this->myRank)||(rhs.mySuit!=this->mySuit));
}

