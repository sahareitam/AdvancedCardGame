#include "Deck.h"
#include "Card.h"


void Deck::operator+=(const Card& card) {

    cards.insert(cards.end(), card);
}


void Deck::operator-=(int num) {
    if (num >= cards.size()) {
        // Clearing the vector if num is greater than or equal to its size
        cards.clear();
    } else {
        cards.erase(cards.begin(), cards.begin() + num);
    }
}

const Card& Deck::operator[](int index) const {
    if (index < 0 || index >= cards.size()) {
        cout << "Invalid_index\n";
        exit(1);
    }
    return cards[index];
}
std::ostream& operator<<(std::ostream& out, const Deck& deck) {
    for (int i = 0; i < deck.cards.size(); i++) {
        out << deck.cards[deck.cards.size() - 1 - i];
        if (i + 1 < deck.cards.size()) {
            out << " ";
        }
    }
    out << " \n";
    return out;
}

std::vector<Card>::size_type Deck::get_number_in_deck()const {
    return cards.size();
}

std::vector<Card> Deck::get_cards()const{
    return cards;
}

// Setter function to modify the cards
void Deck::set_cards(const vector<Card> &new_cards) {
    cards = new_cards;
}




