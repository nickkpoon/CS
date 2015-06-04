#include <stdio.h>
#include <stdlib.h>
#include "problem1helpers.h"

/* This defines a single card.  
 * A card has one of four suits, ranging from 0 to 3:
 * 3 = Spades, 2 = hearts, 1 = diamonds, 0 = clubs
 * A card also has a value, ranging from 0 to 13:
 * 0 = wild card or joker
 * 1 = Ace
 * 2-10 = cards labeled 2-10
 * 11 = jack
 * 12 = queen
 * 13 = king
 */ 
 
 
/* typedef struct _card {
	int suit;
	int value;
} card;

typedef struct _deck {
	int num_cards;
	card *cards;
} deck;
*/



/* make_card
 *
 * Allocate space for AND initialize the values for a single card
 */
 
card *make_card(int suit, int value)
{
	card* newcard = malloc (sizeof(card));
	if (NULL != newcard)
	{
		newcard->suit = suit;
		newcard->value = value;
	}
	
	
	return newcard;
}

/* make_standard_deck
 *
 * Create a full standard deck.  A standard deck contains 52 cards - 
 * for each suit, it contains an Ace through a King.  Do not include
 * any wild cards or jokers
 *
 * Your job is to allocate all of the necessary space for the entire 
 * deck - the deck and all of the cards - and initialize all values
 * of all of the structures you allocate.
 *
 * You are not required to have any particular order - we will sort it 
 * and check for all cards when we grade it.
 */
 
 /* typedef struct _card {
	int suit;
	int value;
} card;

typedef struct _deck {
	int num_cards;
	card *cards;
} deck;
*/


deck *make_standard_deck()
{
	
	int i;
	deck* newdeck;
	newdeck = malloc(sizeof(deck));
	newdeck->num_cards = 52;
	newdeck ->cards = malloc(52 * sizeof(card));
	
	/*for (i = 1; i < 52; i++)
	{
		
		newdeck[i]->cards = make_card(1, 1);
	}*/
	/*for (i = 1; i <= 13; i++)
	{
		for (j = 0; j < 4; j++)
		{
			newdeck[i].cards -> *make_card(j, i);
		}
	}*/
		
	
	return newdeck;
}
/* compare
 *
 * Compare two cards.  The way we compare cards is to first look at the 
 * value.  If the values are different, then the card with the higher value
 * is higher.  If the values are the same, then we check the suit.  The vard
 * with a suit with a higher value (0-3) is higher.
 *
 * The compare result is -1, 0, or 1.  If c1 < c2, then return -1.  If
 * c1 == c2, then return 0.  If c1 > c2, then return 1.
 */
int compare(card *c1, card *c2)
{
	int suit1 = c1->suit;
	int suit2 = c2->suit;
	int value1 = c1->value;
	int value2 = c2->value;
	
	if (value1 > value2)
		return 1;
	else if (value1 < value2)
		return -1;
	else if (value1 == value2 && suit1 > suit2)
		return 1;
	else if (value1 == value2 && suit1 < suit2)
		return -1;
	else
		return 0;
}
/* find_index
 *
 * Find the index of a card in the deck.  This looks in the cards array and
 * returns the index of the corresponding card.  If the card is not present,
 * it returns -1.
 */
int find_index(int suit, int value)
{
	int size = d->num_cards;
	int i;
	for(i = 0; i < size; i++)
	{
		if (d[i].cards->value == value && d[i].cards->suit == suit)
			return i;
	}
		
		
	return -1;
}

/* *********** DO NOT CHANGE CODE BELOW THIS LINE *************** */
/* This code *will* go into problem1helpers.c */

void print_card(card *c)
{
	char *suitchars = "CDHS";
	char *valuechars = "WA23456789TJQK";
	if (c == NULL)
	{
		printf("Card is not allocated\n");
		return;
	}
	if ((c->suit < 0) || (c->suit > 3))
		printf("Invalid suit: %d\n",c->suit);
	else if ((c->value < 0) || (c->value > 13))
		printf("Invalid value: %d\n",c->value);
	else
		printf("%c %c ", suitchars[c->suit], valuechars[c->value]);
}
