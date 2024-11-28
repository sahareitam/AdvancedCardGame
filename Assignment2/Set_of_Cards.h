#ifndef ASSIGNMENT4_SET_OF_CARDS_H
#define ASSIGNMENT4_SET_OF_CARDS_H
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <list>
#include "Card.h"
#include "Deck.h"
using namespace std;

class Set_of_Cards {
    Deck opt_set;
    std::vector<char> shapes;
public:
    explicit Set_of_Cards(const Deck& deck);
    static bool isValidSet(const Deck& deck,std::vector<char>& shapes) ;
    ~Set_of_Cards()=default;
    [[nodiscard]] int get_set_val()const;
    [[nodiscard]] Deck get_set()const;
    [[nodiscard]] bool checkfor_C_S() const;
    [[nodiscard]] bool checkfor_D() const;
    [[nodiscard]] bool checkfor_H() const;
    static int flag_of_set;
};
#endif //ASSIGNMENT4_SET_OF_CARDS_H
