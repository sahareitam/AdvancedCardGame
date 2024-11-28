Decks_game: main.o Deck.o Card.o
	g++ main.o Deck.o Card.o -o  Decks_game
main.o: main.cpp
	g++ -c main.cpp
Deck.o: Deck.cpp
	g++ -c Deck.cpp
Card.o: Card.cpp
	g++ -c Card.cpp
clean:
	rm  -f *.o Decks_game