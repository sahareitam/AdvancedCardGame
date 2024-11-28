#include "Set_of_Cards.h"
#include "Deck.h"
#include <set>
#include <algorithm>


int Set_of_Cards::flag_of_set = 0;

Set_of_Cards::Set_of_Cards(const Deck& deck){
    if (!isValidSet(deck, shapes)) {
        cout << "Card set is not valid\n";
        flag_of_set = 1;
        return;
    }else{
        opt_set = deck;
        // Sort the vector to bring duplicates together
        std::sort(shapes.begin(), shapes.end());

        // Use std::unique to remove consecutive duplicates
        auto last = std::unique(shapes.begin(), shapes.end());

        // Resize the vector to remove the extra elements
        shapes.erase(last, shapes.end());

    }
}

bool Set_of_Cards::isValidSet(const Deck& deck,std::vector<char>& shapes) {
    // A set is valid if it contains a single card
    if (deck.get_number_in_deck() == 1) {
        shapes.push_back(deck.get_cards()[0].get_shape());
        return true;
    }

    // A set is valid if it contains several occurrences of cards, 2, 3, 4 or 5
    // as long as all the cards in the set have the same get_rank and the sum of their value is equal to or less than 10
    char get_rank_set;
    int sum = 0;
    int aceCount = 0;
    if(deck[0].get_rank() == 'A')
    {
        get_rank_set = deck[1].get_rank();
    } else
    {
        get_rank_set = deck[0].get_rank();
    }
    for (int i = 0; i < deck.get_number_in_deck(); i++) {
        //checkhing that first in set != A and if it is we dont take this rank to comare
        //there is an option of set with only 2 Aces so we need to check  it too
        if (deck[i].get_rank() == 'A' && aceCount <= 2)
        {
            aceCount++;
        }
        if(aceCount == 2 && deck.get_number_in_deck() > 2 ) {
            return false;
        }
        shapes.push_back(deck.get_cards()[i].get_shape());
        if (deck[i].get_rank() != get_rank_set && deck[i].get_rank() != 'A') {
            return false;
        }
        else
        {
            sum += deck[i].get_val() - '0';
        }
    }
    // Check if there is only one Ace in the set
    if (aceCount > 2) {
        return false;
    }
    return sum <= 10;
}

int Set_of_Cards::get_set_val() const {
    int sum = 0;
    for (int i = 0; i < opt_set.get_number_in_deck(); i++) {
        if (opt_set[i].get_rank() == 'A') {
            sum += 1;
        } else {
            sum += opt_set[i].get_val();
        }
    }
    return (int)sum;
}

bool Set_of_Cards::checkfor_C_S()const{
    int sum = 0;
    // Check if 'C' is in the vector
    if (std::find(shapes.begin(), shapes.end(), 'C') != shapes.end()) {
        sum += 1;
    }
    // Check if 'S' is in the vector
    if (std::find(shapes.begin(), shapes.end(), 'S') != shapes.end()) {
        sum += 1;
    }
        return sum == 2;
}

bool Set_of_Cards::checkfor_D() const {
    if (std::find(shapes.begin(), shapes.end(), 'D') != shapes.end()) {
        return true;
    }
    return false;
}

bool Set_of_Cards::checkfor_H() const {
    if (std::find(shapes.begin(), shapes.end(), 'H') != shapes.end()) {
        return true;
    }
    return false;
}

Deck Set_of_Cards::get_set() const{
    return opt_set;
}
