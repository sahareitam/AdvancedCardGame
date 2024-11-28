#ifndef ASSIGNMENT4_ENEMY_H
#define ASSIGNMENT4_ENEMY_H
#include "Player.h"
#include "Set_of_Cards.h"

class Player;

class Enemy
{
protected:
    int points;
    int damage;
public:
    Enemy():points(0),damage(0){};
    virtual ~Enemy() = default;
    virtual void attack(Player &p,Set_of_Cards &s)=0;
    virtual void print_Enemy_health();
    virtual void injured_By_Fighter(Set_of_Cards &s) = 0;
    virtual void injured_By_Sorcerer(Set_of_Cards &s) = 0;
    virtual void injured_By_Ranger(Set_of_Cards &s) = 0;
    void decrease_points(const Set_of_Cards &s);
};


#endif //ASSIGNMENT4_ENEMY_H
