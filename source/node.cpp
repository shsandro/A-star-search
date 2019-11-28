#include "../includes/node.hpp"

bool Node::check_success()
{
    return this->h == 0 ? true : false;
}

void print_board(Board &b)
{
    for (int row = 0; row < GAME_SIZE; row++)
    {
        for (int columns = 0; columns < GAME_SIZE; columns++)
        {
            std::cout << b.matrix[row][columns] << "   ";
        }
        printf("\n");
    }
}

Node::Node(Board *b)
{
    this->board = new Board(b);
    this->g = 0;
    this->father = NULL;
    this->f = this->h;
    this->h = this->board->make_heuristic();
}

Node::Node(Node &father, Board *b)
{
    this->board = new Board(b);
    this->g = father.g + 1;
    this->father = &father;
}