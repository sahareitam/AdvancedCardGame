#include "Enemy.h"
#ifndef ASSIGNMENT4_TROLL_H
#define ASSIGNMENT4_TROLL_H


class Troll  : public Enemy
{
public:
    Troll();
    void injured_By_Fighter(Set_of_Cards &s) override;
    void injured_By_Sorcerer(Set_of_Cards &s) override;
    void injured_By_Ranger(Set_of_Cards &s) override;
    void attack(Player &p, Set_of_Cards &s) override;
};


#endif //ASSIGNMENT4_TROLL_H
