// FILE: card_demo.cpp
// This is a small demonstration program showing how the Card and Deck classes are used.
#include <iostream>    // Provides cout and cin
#include <cstdlib>     // Provides EXIT_SUCCESS
#include "card.h"
#include "player.h"
#include "deck.h"

using namespace std;


// PROTOTYPES for functions used by this demonstration program:
void dealHand(Deck &d, Player &p, int numCards);




int main( )
{
    int numCards = 5;
    
    Player p1("Joe");
    Player p2("Jane");
    
    Deck d;  //create a deck of cards
    d.shuffle();
    
    dealHand(d, p1, numCards);
    dealHand(d, p2, numCards);
       
    cout << p1.getName() <<" has : " << p1.showHand() << endl;
    cout << p2.getName() <<" has : " << p2.showHand() << endl;
    
    return EXIT_SUCCESS;  
}



void dealHand(Deck &d, Player &p, int numCards)
{
   for (int i=0; i < numCards; i++)
      p.addCard(d.dealCard());
}

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



   



