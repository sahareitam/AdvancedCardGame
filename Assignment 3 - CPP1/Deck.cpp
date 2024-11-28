#include "Deck.h"
#include "Card.h"

Deck::Deck() {
    this->number_of_cards = 0;
    this->cards = new Card[number_of_cards];
}


Deck::~Deck() {
    delete[] cards;
}

void Deck::operator+=(const Card& card){
    Card* new_card_arr = new Card[number_of_cards + 1];
    new_card_arr[0] = card;
    for (int i = 0; i < number_of_cards; ++i) {
        new_card_arr[i+1] = cards[i];
    }
    delete[] cards;
    this->cards = new_card_arr;
    number_of_cards++;
}

void Deck::operator-=(int num) {
    if(num >= number_of_cards){

        delete[] cards;
        number_of_cards = 0;
        cards = new Card[number_of_cards];
    } else{
        number_of_cards = number_of_cards - num;
        Card* new_card_arr = new Card[number_of_cards];

        for (int i = 0; i < number_of_cards ; ++i) {
            new_card_arr[i] = cards[i];
        }


        delete[] cards; // Deallocate memory for the old array
        cards = new_card_arr; // Update cards pointer to point to the new array
    }
}
Card& Deck::operator[](int index) const {
    if (index < 0 || index >= number_of_cards) {
        std::cout << "index Invalid\n";
        exit(1);
    }
    return cards[index];
}
ostream& operator<<(ostream& out, const Deck& deck) {
    return deck.print(out);
}

ostream &Deck::print(ostream &out) const {
    out << "[";
    for (int i = 0; i < number_of_cards; i++) {
        out << this->cards[i];
        if (i+1 < number_of_cards) {
            out << ",";
        }
    }
    out << "]\n";
    return out;
}
int Deck::get_number_in_deck()const{return this->number_of_cards;}