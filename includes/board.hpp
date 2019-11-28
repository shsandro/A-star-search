#pragma once

#include <utility>
#include <iostream>

#define GAME_SIZE 4

class Board
{
public:
    static int final_matrix[GAME_SIZE][GAME_SIZE];
    int matrix[GAME_SIZE][GAME_SIZE];
    std::pair<int, int> empty_position;

public:
    void update_board(std::pair<int, int>);
    // float make_heuristic();
    Board();
    Board(Board *);
};