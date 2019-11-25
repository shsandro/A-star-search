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

Board::Board(const Board &fathers_board)
{
    this->empty_position = fathers_board.empty_position;

    for (int i = 0; i < GAME_SIZE; i++)
    {
        for (int j = 0; j < GAME_SIZE; j++)
        {
            this->matrix[i][j] = fathers_board.matrix[i][j];
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

float Board::make_heuristic()
{
    int h;
    for (int i = 0; i < GAME_SIZE; i++)
    {
        for (int j = 0; j < GAME_SIZE; j++)
        {
            if (this->matrix[i][j] != this->final_matrix[i][j])
                ++h;
        }
    }
    std::cout << "Calculando heurística: " << h << std::endl;
    return h;
}

bool Board::check_board(Board &board_1, Board &board_2)
{
    for (int i = 0; i < GAME_SIZE; i++)
    {
        for (int j = 0; j < GAME_SIZE; j++)
        {
            if (board_1.matrix[i][j] != board_2.matrix[i][j])
                return false;
        }
    }

    return true;
}

int Board::final_matrix[GAME_SIZE][GAME_SIZE] = {1, 2, 3, 4,
                                                 5, 6, 7, 8,
                                                 9, 10, 11, 12,
                                                 13, 14, 15, 0};