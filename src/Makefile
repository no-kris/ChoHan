# Makefile for ChoHan program
# Run make in terminal to run

OBJS = main.o Dealer.o Dice.o GameMechanics.o Player.o
SOURCE = main.cpp Dealer.cpp Dice.cpp GameMechanics.cpp Player.cpp
HEADER = Dealer.h Dice.h GameMechanics.h Player.h
OUT = ChoHan
CC = g++
FLAGS = -g -c -Wall
LFLAGS = 

all: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS)

main.o: main.cpp
	$(CC) $(FLAGS) main.cpp -std=c++20

Dealer.o: Dealer.cpp
	$(CC) $(FLAGS) Dealer.cpp -std=c++20

GameMechanics.o: GameMechanics.cpp
	$(CC) $(FLAGS) GameMechanics.cpp -std=c++20

Player.o: Player.cpp
	$(CC) $(FLAGS) Player.cpp -std=c++20

clean:
	rm -f $(OBJS) $(OUT)

run: $(OUT)
	./$(OUT)