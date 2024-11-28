
#ifndef ASSIGNMENT3_DECK_H
#define ASSIGNMENT3_DECK_H
#include "Card.h"


class Deck {
private:
    Card* cards;
    int number_of_cards;
    ostream& print(ostream& out)const;

public:
    //distructor
    Deck();

    //constructor
    ~Deck();

    void operator+=(const Card& card);
    void operator-=(int num);
    Card& operator[](int index) const;
    friend ostream& operator<<(ostream& out, const Deck& deck);

    int get_number_in_deck()const;
};


#endif //ASSIGNMENT3_DECK_H
