
#ifndef ASSIGNMENT4_RANGER_H
#define ASSIGNMENT4_RANGER_H
#include "Player.h"


class Ranger : public Player
{
public:
    explicit Ranger(Deck &Main_Deck);
    void attack(Enemy &e, Set_of_Cards &s) override;
    void injured_By_Troll(Set_of_Cards &s) override;
    void injured_By_Ghost(Set_of_Cards &s) override;
    void injured_By_Dragon(Set_of_Cards &s) override;
};


#endif //ASSIGNMENT4_RANGER_H
