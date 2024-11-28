
#include "Enemy.h"

void Enemy::print_Enemy_health()
{
    cout<< "Enemy health: "<< points << std::endl;
}

void Enemy::decrease_points(const Set_of_Cards &s)
{
    this->points = points - s.get_set_val();
    if(0 > points)
    {
        cout << "Player won\n";
        Player::flag = 1;
        return;
    }
}






