CC=g++
INCLUDES=includes
SRC=source

all:
	$(CC) main.cpp $(SRC)/node.cpp $(SRC)/board.cpp $(SRC)/game.cpp -o a.out