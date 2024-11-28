#include "Sorcerer.h"

Sorcerer::Sorcerer(Deck &Main_Deck)
{
    Initial_points = 40;
    max_of_cards = 8;
    cur_points = 40;
    int num_in_main_deck = (int)Main_Deck.get_number_in_deck();
    if (8 > num_in_main_deck)
    {
        cout << "Deck ran out";
        flag = 1;
        return;
    }
    for (int i = 0; i < 8 ; ++i)
    {
        cards_in_hand += Main_Deck[i];
    }
    Main_Deck -= 8;
}

void Sorcerer::attack(Enemy &e,Set_of_Cards &s) {
    e.injured_By_Sorcerer(s);
}

void Sorcerer::injured_By_Troll(Set_of_Cards &s)
{
    if(s.checkfor_H()) {
        this->add_to_Health(s.get_set_val());
    }
    cout << "Player took 5 points of damage\n";
    this->remove_to_Health(5);
}

void Sorcerer::injured_By_Ghost(Set_of_Cards &s)
{
    if(s.checkfor_D()){
        if (s.get_set_val() > 15){
            cout << "Player took 0 points of damage\n";
            this->remove_to_Health(0);

        }else{
        int amount = 15 - s.get_set_val();
        cout << "Player took " << amount <<  " points of damage\n";
        this->remove_to_Health(amount);
        }
    }else{
    cout << "Player took 15 points of damage\n";
    remove_to_Health(15);
    }
}

void Sorcerer::injured_By_Dragon(Set_of_Cards &s)
{
    {
        if(s.checkfor_H()) {
            this->add_to_Health(s.get_set_val());
        }
        if(s.checkfor_D()){
            if (s.get_set_val() > 10){
                cout << "Player took 0 points of damage\n";
                this->remove_to_Health(0);
            }else{
                int amount = 10 - s.get_set_val();
                cout << "Player took " << amount <<  " points of damage\n";
                this->remove_to_Health(amount);
            }
        }else{
            cout << "Player took 10 points of damage\n";
            remove_to_Health(10);
        }
    }
}

