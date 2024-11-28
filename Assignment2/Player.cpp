#include "Player.h"
#include "Set_of_Cards.h"
#include <vector>
using namespace std;

int Player::flag = 0;

Player::Player() : Initial_points(0), max_of_cards(0), cur_points(0){}


void Player::print_player_health()
{
    cout<< "Player health: "<< cur_points << std::endl;
}

void Player::print_player_hand()
{
    cout << cards_in_hand;
}


void Player::remove_to_Health(int amount)
{
    if (amount >= cur_points)
    {
        cout << "Player lost\n";
        flag = 1;
        return;
    }
    else
    {
        cur_points -= amount;
    }

}

void Player::add_to_Health(int amount)
{
    if (amount + cur_points > Initial_points  ) {
        cur_points = Initial_points;
        if (Initial_points - cur_points > 0) {
            cout << "Player healed " << Initial_points - cur_points << " points of damage\n";
        }
    }
    else
    {
        cur_points += amount;
        cout << "Player healed " << amount << " points of damage\n";
    }
}

void Player::add_to_hand(Deck &Main_Deck) {
    if (Main_Deck.get_number_in_deck() < 2 && max_of_cards - cards_in_hand.get_number_in_deck() > 2) {
        cout << "Deck ran out" << endl;

    }

    int num_to_take;
    if(max_of_cards - cards_in_hand.get_number_in_deck() > 2)
    {
        num_to_take = 2;
    }else if (Main_Deck.get_number_in_deck() < max_of_cards - cards_in_hand.get_number_in_deck()) {
        cout << "Deck ran out";
        flag = 1;
        return;
    }else {
        num_to_take = (int)max_of_cards - (int)cards_in_hand.get_number_in_deck();
    }

    // Take two cards from the top of the deck and add them to the hand
    for (int i = 0; i < num_to_take; ++i) {
        cards_in_hand +=(Main_Deck[i]);
    }

    // Remove the taken cards from the deck
    Main_Deck -= (int) num_to_take;
}

void Player::remove_from_hand(const Set_of_Cards& otherSet) {
    // Get the cards from the player's deck
    std::vector<Card> playerCards = cards_in_hand.get_cards();

    // Get the cards from the other deck
    std::vector<Card> otherCards = otherSet.get_set().get_cards();

    // Subtract the cards in the other deck from the player's deck
    for (const auto& card : otherCards) {
        // Find and remove the card from the player's deck
        auto it = std::find(playerCards.begin(), playerCards.end(), card);
            // If the card is found, remove it from your deck
            if (it != playerCards.end()) {
                playerCards.erase(it);
            }
        }
    // Set the modified cards back to the player's deck
    cards_in_hand.set_cards(playerCards);
}

