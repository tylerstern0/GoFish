//
// Created by Aditya Singh on 11/7/18.
//

//
// Created by Tyler Stern on 10/28/18.
//

#include "card.h"



//4 different constructors; we'll likely only ever use the last one
Card::Card()
{
    myRank = 1;
    mySuit = spades;
}

Card::Card(int _rank, Suit _s)
{
    myRank = _rank;
    mySuit = _s;
}



//get and set instance variables (name, artist, size)
string Card::toString() {
    std::string rank = std::to_string(myRank);
    std::string suit = std::to_string(mySuit);
    std:string strSR = suit[0] + rank;
    return (strSR);
}

/*
    switch(mySuit)
    {
        case spades: std:cout<<"s"<<rank<endl;

        case diamonds: std:cout<<"d"<<rank<endl;
        case hearts: std:cout<<"h"<<rank<endl;
        case clubs: std:cout<<"c"<<rank<endl;
    }


    return name;
}
 */


bool sameSuitAs(const Card& c) const{
    return true;
}


int  getRank() const{
    return(rank);

}

string suitString(Suit s) const{
    std::string suit = std::to_string(mySuit);
    return (suit[0]);
}

