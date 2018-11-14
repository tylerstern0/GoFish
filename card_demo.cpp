// FILE: card_demo.cpp
// This is a small demonstration program showing how the Card and Deck classes are used.
#include <iostream>    // Provides cout and cin
#include <cstdlib>     // Provides EXIT_SUCCESS
#include "card.h"
#include "player.h"
#include "deck.h"
#include <unistd.h>
#include <fstream>

using namespace std;


// PROTOTYPES for functions used by this demonstration program:
void dealHand(Deck &d, Player &p, int numCards);
void turn(Player &pA, Player &pB, Deck &d, ofstream &outFile);




int main( )
{
    int numCards = 5;

    ofstream outFile;
    outFile.open("gofish.txt");


    Player p1("Tyler");
    Player p2("Aditya");


    Deck d;  //create a deck of cards

    d.shuffle();


    dealHand(d, p1, numCards);

    dealHand(d, p2, numCards);

    outFile << p1.getName() <<" has : " << p1.showHand() << endl;
    outFile << p2.getName() <<" has : " << p2.showHand() << endl;


    while ((p1.getBookSize() + p2.getBookSize()) < 25){
        turn(p1, p2, d, outFile);
        outFile << p1.getName() << "'s hand: " << p1.showHand() << endl;
        outFile << p2.getName() << "'s hand: " << p2.showHand() << endl;
        outFile << p1.getName() << "'s books: " << p1.showBooks() << endl;
        outFile << p2.getName() << "'s books: " << p2.showBooks() << endl;
        turn(p2, p1, d, outFile);
        outFile << p1.getName() << "'s hand: " << p1.showHand() << endl;
        outFile << p2.getName() << "'s hand: " << p2.showHand() << endl;
        outFile << p1.getName() << "'s books: " << p1.showBooks() << endl;
        outFile << p2.getName() << "'s books: " << p2.showBooks() << endl;

    }

    outFile << "Game over." << endl;
    if(p1.getBookSize() > p2.getBookSize()){
        outFile << p1.getName() << " wins." << endl;
    }
    if(p2.getBookSize() > p1.getBookSize()){
        outFile << p2.getName() << " wins." << endl;
    }else{
        outFile<<"The game ends in a tie."<< endl;
    }
    outFile.close();
    
    return EXIT_SUCCESS;  
}



void dealHand(Deck &d, Player &p, int numCards)
{
   for (int i=0; i < numCards; i++)
      p.addCard(d.dealCard());
}

void turn(Player &pA, Player &pB, Deck &d, ofstream &outFile){
    if(!pA.handEmpty()){

        //ask the other player for a rank of card
        Card ask = pA.chooseCardFromHand();
        outFile << pA.getName() << ": " << pB.getName() << ", do you have a " << ask.getRank() << "?" << endl;


        Card newCard;
        //if the other player does have a card of the desired rank: reply, choose newCard
        if(pB.rankInHand(ask)){
            outFile << pB.getName() << ": I gotchu, bro." << endl;
            newCard = pB.searchHand(ask);
            pB.removeCardFromHand(newCard);

        //if the other player doesn't have a card of the desired rank: reply, choose newCard
        }else{
            outFile << pB.getName() << ": Nah, bro, sorry, bro. Go Fish." << endl;
            newCard = d.dealCard();
            outFile<< pA.getName()<<" draws "<< newCard.toString()<<"."<< endl;
        }

        //add the newCard to the player's hand and check/make books, then return
        pA.addCard(newCard);



        Card booked1;
        Card booked2;

        int book = pA.checkHandForBook(booked1, booked2);

        //if(book){

            //pA.bookCards(booked1, booked2);

        //}

        //cout << pA.getName() << " has booked " << booked1.toString()<< " and " << booked2.toString() << "." << endl;
        return;


    //if the player has no cards in the hand, draw one from the deck
    }else{
        Card newCard = d.dealCard();
        pA.addCard(newCard);
        outFile << pA.getName() << " draws a " << newCard.toString()<< endl;

        //check if that card makes any books
        Card booked1;
        Card booked2;
        int book = pA.checkHandForBook(booked1, booked2);
        //if(book){
          //  pA.bookCards(booked1, booked2);
        //}
        //cout << pA.getName() << " has booked " << booked1.toString()<< " and " << booked2.toString() << "." << endl;
        return;
    }


}



////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////




/*

// FILE: card_demo.cpp
#include <iostream>    // Provides cout and cin
#include <cstdlib>     // Provides EXIT_SUCCESS
#include <ctime>
#include <vector>
#include "card.h"
#include "deck.h"
#include "player.h"

using namespace std;

int main( )
{

    Deck d;
    //d.shuffle();

    Card c = d.dealCard();
    cout << "deal test " << c << endl;
    cout << endl;

    Player p("Joe");
    cout << p.getName() << endl;
    p.addCard(c);
    p.addCard(d.dealCard());
    cout << p.showHand() << endl;


    int numCards = 5;

    vector <Card> cards(numCards);

    srand((unsigned)time(0));  //seed the random number generator

    for (int i = 0; i < numCards; i++) {
        int rank = (rand() % 13) + 1;
        int suit = (rand() % 4);
        Card c(rank,(Card::Suit)suit);
        cout << "rank - " << rank << "  "  << c <<  endl;
        cards[i] = c;
    }

    for (int i = 0; i < cards.size(); i++)
        cout << cards[i] << endl;

    cards.erase(cards.begin()+2);

    cout <<"after"<<endl;

    for (int i = 0; i < cards.size(); i++)
        cout << cards[i] << endl;

    return EXIT_SUCCESS;
}




*/



   



