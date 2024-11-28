#include "Card.h"


//distructor
Card::Card(char Rank,char Shape){
    int Rank_int = Rank - '0';

    if (Rank_int > 1 && Rank_int < 10){
        this->Rank = Rank;
        this->Rank_number_val = Rank - '0';
        this->Shape = Shape;
        this->Value = Rank - '0';
    }else if(Rank == 'T') {
        this->Rank = Rank;
        this->Rank_number_val = 10;
        this->Shape = Shape;
        this->Value = 10;
    }else if(Rank == 'J'){
        this->Rank = Rank;
        this->Rank_number_val = 11;
        this->Shape = Shape;
        this->Value = 10;
    } else if (Rank == 'Q'){
        this->Rank = Rank;
        this->Rank_number_val = 12;
        this->Shape = Shape;
        this->Value = 15;
    } else if (Rank == 'K'){
        this->Rank = Rank;
        this->Rank_number_val = 13;
        this->Shape = Shape;
        this->Value = 20;
    } else if (Rank == 'A'){
        this->Rank = Rank;
        this->Rank_number_val = 1;
        this->Shape = Shape;
        this->Value = 1;
    }
}

// Default constructor
Card::Card() : Rank('2'), Rank_number_val(2), Shape('c'), Value(2) {}


//copy constructor
Card::Card(const Card &Source) {
        this->Rank = Source.Rank;
        this->Rank_number_val = Source.Rank - '0';
        this->Shape = Source.Shape;
        this->Value = Source.Value;
    }

bool Card::operator==(const Card &other)const {
    return (this->Rank == other.Rank) && (this->Shape == other.Shape);
}

bool Card::operator!=(const Card& other) const {
    return !(*this == other);
}

bool Card::operator<(const Card& other) const {
    int me_int,other_int;
    if (this->Rank_number_val == other.Rank_number_val) {
        if(this->Shape == 'C'){
            me_int = 4;
        }
        if(this->Shape == 'S'){
            me_int = 3;
        }
        if(this->Shape == 'H'){
            me_int = 2;
        }
        if(this->Shape == 'D'){
            me_int = 1;
        }
        if(other.Shape == 'C'){
            other_int = 4;
        }
        if(other.Shape == 'S'){
            other_int = 3;
        }
        if(other.Shape == 'H'){
            other_int = 2;
        }
        if(other.Shape == 'D'){
            other_int = 1;
        }
        return (me_int < other_int);
    }
    return this->Rank_number_val < other.Rank_number_val;
}

bool Card::operator<=(const Card& other) const {
    return (*this < other) || (*this == other);
}

bool Card::operator>(const Card& other) const {
    return !(*this <= other);
}

bool Card::operator>=(const Card& other) const {
    return !(*this < other);
}

Card& Card::operator=(const Card& other){
    if (this != &other) {
        this->Rank = other.Rank;
        this->Rank_number_val = other.Rank - '0';
        this->Shape = other.Shape;
        this->Value = other.Value;
    }
    return *this;
}

ostream& operator<<(ostream& out, const Card& card) {
    return card.show(out);
}

ostream &Card::show(ostream &out) const {
    out << this->Rank << this->Shape ;
    return out;
}

Card::~Card() = default;




