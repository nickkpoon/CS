#ifndef DECK_H
#define DECK_H
#include "Card.h"

class Deck {
 private:
  int num_cards;
  Card **cards; // this is an array of Card * - not an array of Cards.
 public:
  Deck();
  int find_index(int suit, int value) const;
  const Card *get_card(int index) const;
  int get_num_cards() const;
};


#endif /* DECK_H */
