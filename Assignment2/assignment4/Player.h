#ifndef ASSIGNMENT4_PLAYER_H
#define ASSIGNMENT4_PLAYER_H
#include "Card.h"
#include <list>
#include "Deck.h"
#include "Enemy.h"
#include "Set_of_Cards.h"

class Enemy;

class Player
{
protected:
    Deck cards_in_hand;
    int Initial_points;
    int max_of_cards;
    int cur_points;
public:
    Player();
    virtual void print_player_health();
    virtual void print_player_hand();
    void remove_to_Health(int amount);
    void add_to_Health(int amount);
    virtual void attack(Enemy &e,Set_of_Cards &s) = 0;
    virtual void injured_By_Troll(Set_of_Cards &s) = 0;
    virtual void injured_By_Ghost(Set_of_Cards &s) = 0;
    virtual void injured_By_Dragon(Set_of_Cards &s) = 0;
    virtual void add_to_hand(Deck &Main_Deck);
    virtual void remove_from_hand(const Set_of_Cards& otherSet);
    virtual ~Player() = default;
    static int flag;
};


#endif //ASSIGNMENT4_PLAYER_H
