//
// Created by ise on 3/8/24.
//

#include "Dragon.h"

Dragon::Dragon()
{
    points = 75;
    damage = 10;
}
void Dragon::attack(Player &p, Set_of_Cards &s)
{
    p.injured_By_Dragon(s);
}

void Dragon::injured_By_Fighter(Set_of_Cards &s) {
    if (s.checkfor_C_S()) {
        int damage = 2*s.get_set_val();
        cout << "Player dealt" << damage <<  "points of damage";
        this->decrease_points(s);
        this->decrease_points(s);
    } else {
        cout << "Player dealt" << s.get_set_val() <<  "points of damage";
        this->decrease_points(s);
    }
}

void Dragon::injured_By_Sorcerer(Set_of_Cards &s)
    {
    //here the C + S deasnt worked
        cout << "Player dealt " << s.get_set_val() <<  " points of damage\n";
        this->decrease_points(s);
    }


void Dragon::injured_By_Ranger(Set_of_Cards &s) {
    if (s.checkfor_C_S()) {
        int damage = 2*s.get_set_val();
        cout << "Player dealt" << damage <<  "points of damage";
        this->decrease_points(s);
        this->decrease_points(s);

    } else {
        cout << "Player dealt " << s.get_set_val() <<  " points of damage\n";
        this->decrease_points(s);
    }
}