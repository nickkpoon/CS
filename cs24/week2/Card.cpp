#include <cstdlib>	
#include <cstdio>
#include <iostream>
#include "Card.h"


Card::Card(const int s, int v)
{
	suit = s;
	value = v;
}

/*Card::Card()
{
	suit = 0;
	value = 0;
}
*/
int Card::get_suit() const
{
	return suit;

}

int Card::get_value() const
{
	return value;

}

int Card::compare(const Card& c) const
{
	int suit1 = this->get_suit();
	int suit2 = c.get_suit();
	int value1 = this->get_value();
	int value2 = c.get_value();
	
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

void Card::print_card(FILE *) const
{
	const char *suitchars = "CDHS";
	const char *valuechars = "WA23456789TJQK";
	if (this == NULL)
	{
		printf("Card is not allocated\n");
		return;
	}
	if ((this->get_suit() < 0) || (this->get_suit() > 3))
		printf("Invalid suit: %d\n",this->get_suit());
	else if ((this->get_value() < 0) || (this->get_value() > 13))
		printf("Invalid value: %d\n",this->get_value());
	else
		printf("%c %c ", suitchars[this->get_suit()], valuechars[this->get_value()]);

}




