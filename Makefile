CC=g++
INCLUDES=includes
SRC=source

all:
	$(CC) -Wall -std=c++0x main.cpp $(SRC)/game.cpp $(SRC)/node.cpp $(SRC)/board.cpp $(SRC)/heuristics.cpp -o a-star.out