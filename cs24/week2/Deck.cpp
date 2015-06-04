#include <cstdlib>	
#include <cstdio>
#include <iostream>
#include "Deck.h"

/*Deck::Deck(const int n, Card **c)
{
	num_cards = n;
	**cards = **c;
}
*/
Deck::Deck()
{
	num_cards = 0;
	Card **cards = NULL;
}

int Deck::find_index(int suit, int value) const
{
	int i;
	for(i = 0; i < this->get_num_cards(); i++)
	{
		if (cards[i]->get_value() == value && cards[i]->get_suit() == suit)
			return i;
	}
		
	
	return -1;
}

const Card * Deck::get_card(int index) const
{
		
	return cards[index];
}

int Deck::get_num_cards() const
{
		
	return num_cards;
}


