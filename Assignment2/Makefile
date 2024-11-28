Decks_game: Card.o Dragon.o Fighter.o main.o Ranger.o Sorcerer.o Deck.o Enemy.o Ghost.o Player.o Set_of_Cards.o Troll.o
	g++ Card.o Dragon.o Fighter.o main.o Ranger.o Sorcerer.o Deck.o Enemy.o Ghost.o Player.o Set_of_Cards.o Troll.o -o Decks_game
	
Card.o: Card.cpp Card.h
	g++ -c Card.cpp
	
Deck.o: Deck.cpp Deck.h Card.h
	g++ -c Deck.cpp
	
Dragon.o: Dragon.cpp Dragon.h Enemy.h Player.h Deck.h Card.h Set_of_Cards.h
	g++ -c Dragon.cpp
	
Enemy.o: Enemy.cpp Enemy.h
	g++ -c Enemy.cpp
	
Fighter.o: Fighter.cpp Fighter.h Player.h Deck.h Card.h Enemy.h
	g++ -c Fighter.cpp
	
Ghost.o: Ghost.cpp Ghost.h Enemy.h Player.h Deck.h Card.h Set_of_Cards.h
	g++ -c Ghost.cpp
	
main.o: main.cpp Card.h Dragon.h Fighter.h Ranger.h Sorcerer.h Deck.h Enemy.h Ghost.h Player.h Set_of_Cards.h Troll.h
	g++ -c main.cpp
	
Player.o: Player.cpp Player.h Deck.h Card.h Enemy.h
	g++ -c Player.cpp
	
Ranger.o: Ranger.cpp Ranger.h Player.h Deck.h Card.h Enemy.h
	g++ -c Ranger.cpp
	
Sorcerer.o: Sorcerer.cpp Sorcerer.h Player.h Deck.h Card.h Enemy.h
	g++ -c Sorcerer.cpp
	
Troll.o: Troll.cpp Troll.h Enemy.h Player.h Deck.h Card.h
	g++ -c Troll.cpp
	
clean:
	rm -f *.o Decks_games
