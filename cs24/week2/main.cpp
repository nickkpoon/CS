#include <cstdio> 
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;
#include "Deck.h"
#include "Card.h"

int main(int argc, char *argv[])
{	


	Card **hand;
	Deck *fulldeck;
	int i, j, k;
	/* create an array of card pointers */
	hand = new Card *[5];
	/* make a card for each one */
	for(i=0;i<5;i++)
		hand[i] = new Card(i%4, (i*17)%14);
		
	/* print out the cards in the hand */
	// vvv probably need to incorporate printf part into print fxn 
	printf("Hand: ");
	for(i=0;i<5;i++)
 		hand[i]->print_card(stdout);
	printf("\n"); 
	
	/* make a standard deck of cards */
	fulldeck = new Deck();
	if (fulldeck == NULL)
	{
		printf("make_standard_deck not yet implemented ... exiting\n");
		exit(0);
	}	
	/* print out all of the cards */
	for(i=0;i<fulldeck->get_num_cards();)
		for(j=0;j<13 && i<fulldeck->get_num_cards();j++,i++)
		 	(fulldeck->get_card(i))->print_card(stdout);
	

	/* compare some cards */
	printf("Compare: ");
	(fulldeck->get_card(5))->print_card(stdout);
	(fulldeck->get_card(17))->print_card(stdout);
	printf(": %d\n", (fulldeck->get_card(5))->compare(*(fulldeck->get_card(17))));

	printf("find index: C 5: %d", fulldeck->find_index(0,5));

}

