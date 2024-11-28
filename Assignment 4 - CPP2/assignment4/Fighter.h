
#ifndef ASSIGNMENT4_FIGHTER_H
#define ASSIGNMENT4_FIGHTER_H
#include "Player.h"

class Fighter : public Player
{
public:
    explicit Fighter(Deck &Main_Deck);
    void attack(Enemy &e,Set_of_Cards &s)override;
    void injured_By_Troll(Set_of_Cards &s) override;
    void injured_By_Ghost(Set_of_Cards &s) override;
    void injured_By_Dragon(Set_of_Cards &s) override;
};
#endif //ASSIGNMENT4_FIGHTER_H
