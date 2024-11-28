#include "Enemy.h"
#ifndef ASSIGNMENT4_DRAGON_H
#define ASSIGNMENT4_DRAGON_H


class Dragon : public Enemy
{
public:
    Dragon();
    void attack(Player &p, Set_of_Cards &s) override;
    void injured_By_Fighter(Set_of_Cards &s) override;
    void injured_By_Sorcerer(Set_of_Cards &s) override;
    void injured_By_Ranger(Set_of_Cards &s) override;
};
#endif //ASSIGNMENT4_DRAGON_H
