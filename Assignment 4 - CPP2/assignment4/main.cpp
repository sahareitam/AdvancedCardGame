#include <iostream>
#include <string>
#include <sstream>
#include "Player.h"
#include "Enemy.h"
#include "Deck.h"
#include "Card.h"
#include "Fighter.h"
#include "Sorcerer.h"
#include "Ranger.h"
#include "Set_of_Cards.h"
#include "Dragon.h"
#include "Troll.h"
#include "Ghost.h"
using namespace std;

// Function to split a string
Deck splitString(const std::string& str) {
    Deck cards_from_input;
    std::stringstream ss(str);
    std::string the_card;
    while (ss >> the_card) {
        if (the_card.length() >= 2) { // Ensure the substring has at least two characters
            char rank = the_card[0]; // First character is the rank
            char suit = the_card[1]; // Second character is the suit
            Card real_card(rank, suit); // Create a Card object
            cards_from_input += real_card; // Add the Card object to the Deck
        }
    }
    return cards_from_input;
}

int main() {
    //Loading a deck of cards
    Deck deck;
    std::string input;
    std::cout << "Initialize deck\n";
    while (std::cin >> input && input != "00") {
        Card card_to_add(input[0], input[1]);
        deck += card_to_add;
    }
    //Choosing a character and enemy
    int playerChoice;
    int enemyChoice;

    // Draw a number of cards as the maximum number of cards that can be in the hand
    std::cout << "Choose player character:\n(1) Fighter (2) Sorcerer (3) Ranger\n";
    std::cin >> playerChoice;
    std::cout << "Choose enemy character:\n(1) Troll (2) Ghost (3) Dragon\n";
    std::cin >> enemyChoice;
    Player *The_player;
    try {
        switch (playerChoice) {
            case 1: {
                The_player = new Fighter(deck);
                if (Player::flag == 1) {
                    delete The_player;
                    exit(1);
                }
                break;
            }
            case 2: {
                The_player = new Sorcerer(deck);
                if (Player::flag == 1) {
                    delete The_player;
                    exit(1);
                }
                break;
            }
            case 3: {
                The_player = new Ranger(deck);
                if (Player::flag == 1) {
                    delete The_player;
                    exit(1);
                }
                break;
            }
            default:exit(1);
        }
    }
    catch (const std::bad_alloc& e) {
        std::cerr << "Memory Error" << e.what() << std::endl;
        delete The_player;
        return 0;
    }

    Enemy *The_Enemy;
    try {
        switch (enemyChoice) {
            case 1: {
                The_Enemy = new Troll();
                break;
            }
            case 2: {
                The_Enemy = new Ghost();
                break;
            }
            case 3: {
                The_Enemy = new Dragon();
                break;
            }
            default: exit(1);
        }
    }
    catch (const std::bad_alloc& e) {
        std::cerr << "Memory Error" << e.what() << std::endl;
        delete The_Enemy;
        return 0;
    }


    std::cin.ignore();
    std::string the_set;
    Set_of_Cards *The_set;

    while (true) {
        The_player->print_player_health();
        The_Enemy->print_Enemy_health();
        cout << "Player hand\n";
        The_player->print_player_hand();
        bool is_valid = false;
        while (!is_valid){
            cout << "Insert card set to play\n";
            std::getline(std::cin, the_set);
            if("exit" == the_set)
            {
                exit(1);
            }
            Deck cards_from_input = splitString(the_set);
            try
            {
                The_set = new Set_of_Cards(cards_from_input);
                if (Set_of_Cards::flag_of_set == 1) {
                    delete The_set;
                    continue;
                }
                is_valid = true;
            }
            catch (const std::bad_alloc& e) {
                std::cerr << "Memory Error" << e.what() << std::endl;
                delete The_set;
                return 0;
            }

            try {
                The_player->attack(*The_Enemy, *The_set);
                if(Player::flag == 1) {
                    delete The_player;
                    delete The_Enemy;
                    exit(1);
                }
                The_Enemy->attack(*The_player, *The_set);
                    if(Player::flag == 1){
                        delete The_player;
                        delete The_Enemy;
                        exit(1);
                        }
                The_player->remove_from_hand(*The_set);
                The_player->add_to_hand(deck);
                if(Player::flag == 1){
                    delete The_player;
                    delete The_Enemy;
                    exit(1);
                }

            }
            catch (const std::bad_alloc& e) {
                std::cerr << "Memory Error" << e.what() << std::endl;
                delete The_set;
                return 0;
            }
        }
    }
}

