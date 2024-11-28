#include <iostream>
#include "Deck.h"
#include "Card.h"


int main() {
    bool deckExists = false; // Variable to track if a deck exists
    Deck deck;
    int choice;
    bool is_true = true;
    while (is_true) {
        // Display the menu options
        std::cout << "Menu:\n"
                     "1. Build Empty Deck\n"
                     "2. Compare Cards\n"
                     "3. Add Cards\n"
                     "4. Remove Cards\n"
                     "5. Look at Top Cards\n"
                     "6. Card at\n"
                     "7. Swap Card\n"
                     "8. Print Deck\n"
                     "9. Delete Deck\n"
                     "10. Exit\n";
        cin >> choice;

        // Perform actions based on the user's choice
        switch (choice) {
            case 1: {
                if (deckExists) {
                    std::cout << "Deck already exists\n";
                } else {
                    deckExists = true;
                }
                break;
            }
            case 2: {
                char first_card[3];
                char second_card[3];
                char the_operator[3];
                cin >> first_card;
                cin >> second_card;
                cin >> the_operator;

                // Convert char arrays to Card objects
                Card card1(first_card[0], first_card[1]);
                Card card2(second_card[0], second_card[1]);
                bool result;
                switch (the_operator[0]) {
                    case '<': {
                        if ('=' == the_operator[1]) {
                            result = card1 <= card2;
                        } else if ('\000' == the_operator[1]) {
                            result = card1 < card2;
                        } else {
                            goto invalid_operator;
                        }
                        break;
                    }
                    case '=': {
                        if ('=' == the_operator[1]) {
                            result = card1 == card2;
                        } else {
                            goto invalid_operator;
                        }
                        break;
                    }
                    case '!': {
                        if ('=' == the_operator[1]) {
                            result = card1 != card2;
                        } else {
                            goto invalid_operator;
                        }
                        break;
                    }
                    case '>': {
                        if ('=' == the_operator[1]) {
                            result = card1 >= card2;
                        } else if ('\000' == the_operator[1]) {
                            result = card1 > card2;
                        } else {
                            goto invalid_operator;
                        }
                        break;
                    }
                    default: {
                        invalid_operator:
                        cout << "Invalid operator.\n";
                        continue; // Restart the loop
                    }
                }
                        if (result)
                        {
                            cout << "True\n";
                        }
                        else
                        {
                            cout << "False\n";
                        }
                        break;
                    }
                case 3:
                {
                    // Implement adding cards to the deck
                    int number_of_cards_to_add;
                    cin >> number_of_cards_to_add;
                    if (number_of_cards_to_add < 0)
                    {
                        cout << "Invalid number\n";
                    } else {
                        char card_to_add_char[3];
                        for (int i = 0; i < number_of_cards_to_add; i++) {
                            cin >> card_to_add_char;
                            Card card_to_add(card_to_add_char[0], card_to_add_char[1]);
                            deck += card_to_add;
                        }
                        break;
                    }
                }
                case 4: {
                    // Implement throwing cards
                    int num_to_remove;
                    cin >> num_to_remove;
                    if (num_to_remove < 0 ) {
                        cout << "Invalid index\n";
                    } else {
                    deck -= num_to_remove;
                    break;
                    }
                }
                case 5: {
                    // Implement looking at cards
                    int num_to_look;
                    cin >> num_to_look;
                    if (num_to_look < 0) {
                        std::cout << "Invalid number\n";
                        break;
                    }
                    if (num_to_look > deck.get_number_in_deck()) {
                        num_to_look = deck.get_number_in_deck();
                    }
                    int deck_size = deck.get_number_in_deck();
                    for (int i = 1; i <= num_to_look && i <= deck_size; i++) {
                        cout << deck[deck_size - i] << endl;
                    }
                    break;
                }
                case 6: {
                    // Implement looking at a card in a certain place
                    int index;
                    cin >> index;
                    if (index < 0 || index >= deck.get_number_in_deck()) {
                        cout << "Invalid index\n";
                    } else {
                        // Print card at the specified index
                        cout << deck[index];
                    }
                    break;
                }
                case 7: {
                    // Implement replacing a card
                    char card_to_replace_char[3];
                    int index_2;
                    cin >> index_2;
                    cin >> card_to_replace_char;

                    if (index_2 < 0 || index_2 >= deck.get_number_in_deck()) {
                        cout << "Invalid index\n";

                    } else {
                        Card card_to_replace(card_to_replace_char[0], card_to_replace_char[1]);
                        deck[index_2] = card_to_replace;
                    }
                    break;
                }
                case 8: {
                    if (deckExists) {
                        cout << deck;
                    } else {
                        std::cout << "No deck exists\n";
                    }
                    break;
                }
                case 9: {
                    if (deckExists) {
                        deckExists = false;
                        deck -= deck.get_number_in_deck();
                    } else {
                        break;
                    }
                    break;
                }
                case 10: {
                    is_true = false;
                    break;
                }
                default: {
                    cout << " Please provide a valid index within the range [0,10] ";
                    break;
                }
            }
        }
        return 0;
    }