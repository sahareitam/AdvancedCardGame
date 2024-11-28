#ifndef ASSIGNMENT3_CARD_H
#define ASSIGNMENT3_CARD_H

#include <iostream>
using namespace std;


class Card {
private:
    char Rank;
    char Shape;
    int Value;

    int Rank_number_val;
    ostream& show(ostream& out)const;

public:
    //constractur
    Card(char Rank,char Shape);

    // Default constructor
    Card();
    //copy constructor
    Card(const Card &Source);

    //distructor
    ~Card();

    //get rank
    [[nodiscard]] char get_rank() const;

    //get value
    [[nodiscard]] int get_val() const;

    //get shape
    [[nodiscard]] char get_shape() const;
    // Comparison operators
    bool operator==(const Card& other)const;
    bool operator!=(const Card& other) const;
    bool operator<(const Card& other) const;
    bool operator<=(const Card& other) const;
    bool operator>(const Card& other) const;
    bool operator>=(const Card& other) const;

    Card& operator=(const Card& other);

    friend ostream& operator<<(ostream& out, const Card& card);
    };


#endif //ASSIGNMENT3_CARD_H
