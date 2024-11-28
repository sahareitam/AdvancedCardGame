
#ifndef ASSIGNMENT3_DECK_H
#define ASSIGNMENT3_DECK_H
#include <iostream>
#include <vector>
#include "Card.h"

class Deck {
    std::vector<Card> cards;
public:
    //distructor
    ~Deck() = default;
    //constructor
    Deck():cards(0){};
    //copy constructor
    Deck(const Deck& other) : cards(other.cards) {}
    [[nodiscard]] std::vector<Card> get_cards() const;
    void set_cards(const std::vector<Card> & new_cards);
    void operator+=(const Card& card);
    void operator-=(int num);
    const Card& operator[](int index) const;
    friend ostream& operator<<(ostream& out, const Deck& deck);
    [[nodiscard]] std::vector<Card>::size_type get_number_in_deck()const;
};


#endif //ASSIGNMENT3_DECK_H
