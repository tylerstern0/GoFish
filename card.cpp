

#include "card.h"



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



//member functions
string Card::toString() const{
    return(rankString(myRank) + suitString(mySuit));
}


/*
     std::string rank = std::to_string(myRank);
    std::string suit = std::to_string(mySuit);
    std:string strSR = suit[0] + rank;
    return (strSR);
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


bool Card::sameSuitAs(const Card& c) const{
    return(mySuit == c.mySuit);

}


int  Card::getRank() const{
    return(myRank);

}

string Card::suitString(Suit s) const{
    switch(s)
    {
        case spades: return("s");
        case diamonds: return("d");
        case hearts: return("h");
        case clubs: return("c");

    }
    return ("NULL");
}

string Card::rankString(int r) const{
    if(r != 1 and r != 11 and r!= 12 and r != 13)
    {
        return(std::to_string(myRank));
    }
    if(r == 1)
    {
        return("A");
    }
    if(r == 11)
    {
        return("J");
    }
    if(r == 12)
    {
        return("Q");
    }
    else
    {
        return("K");
    }

}


char Card::getSuit() const {
    return mySuit;
}


// operators

bool Card::operator == (const Card& rhs) const{
    bool result = (myRank == rhs.myRank);
    return result;
}

bool Card::operator != (const Card& rhs) const{
    bool result = (myRank != rhs.myRank);
    return result;
}

ostream& Card::operator << (const Card& c){
    return cout << c.toString();
}
