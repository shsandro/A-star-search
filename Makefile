CC=g++
INCLUDES=includes
SRC=source

run:
	@./a.out
	
all:
	$(CC) -Wall -std=c++0x main.cpp $(SRC)/node.cpp $(SRC)/board.cpp $(SRC)/game.cpp -o a.out