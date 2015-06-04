#ifndef _Card_h
#define _Card_h
#include <cstdio>

class Card{
private:
    int suit;
    int value;
    
public:
    Card(int suit, int value);
    int get_suit() const;
    int get_value() const;
    int compare(const Card& c) const;
    void print_card(FILE *) const;
};



#endif
