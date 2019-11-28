#include "../includes/board.hpp"

Board::Board()
{
    for (int i = 0; i < GAME_SIZE; i++)
    {
        for (int j = 0; j < GAME_SIZE; j++)
        {
            std::cin >> this->matrix[i][j];
            if (this->matrix[i][j] == 0)
                empty_position = std::make_pair(i, j);
        }
    }
}

Board::Board(Board *fathers_board)
{
    this->empty_position = fathers_board->empty_position;

    for (int i = 0; i < GAME_SIZE; i++)
    {
        for (int j = 0; j < GAME_SIZE; j++)
        {
            this->matrix[i][j] = fathers_board->matrix[i][j];
        }
    }
}

void Board::update_board(std::pair<int, int> new_position)
{
    int aux = this->matrix[empty_position.first][empty_position.second];
    this->matrix[empty_position.first][empty_position.second] = this->matrix[new_position.first][new_position.second];
    this->matrix[new_position.first][new_position.second] = aux;

    this->empty_position = new_position;
}

int Board::final_matrix[GAME_SIZE][GAME_SIZE] = {1, 2, 3, 4,
                                                 5, 6, 7, 8,
                                                 9, 10, 11, 12,
                                                 13, 14, 15, 0};