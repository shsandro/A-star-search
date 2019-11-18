#pragma once

#include <iostream>
#include <memory>
#include "board.hpp"

class Node
{
public:
    int g;
    float h;
    float f;
    Board board;
    Node *father;
    float make_heuristic(Node &node);
    Node();
    Node(Node &father);
};

float Node::make_heuristic(Node &node)
{
    int h;
    for (int i = 0; i < GAME_SIZE; i++)
    {
        for (int j = 0; j < GAME_SIZE; j++)
        {
            if (node.board.matrix[i][j] != node.board.final_matrix[i][j])
                ++h;
        }
    }

    return h;
}

Node::Node()
{
    this->g = 0;
    this->board = Board();
    this->father = nullptr;
    this->h = this->board.make_heuristic;
    this->f = this->h;

    print_board(this->board);
}

Node::Node(Node &father)
{
    this->g = father.g + 1;
    this->father = &father;
    this->board = Board(father.board);
}

void print_board(Board &b)
{
    for (int row = 0; row < GAME_SIZE; row++)
    {
        for (int columns = 0; columns < GAME_SIZE; columns++)
        {
            printf("%d     ", b.matrix[row][columns]);
        }
        printf("\n");
    }
}

struct classcomp
{
    bool operator()(const Node *lhs, const Node *rhs) const
    {
        return lhs->f < rhs->f;
    }
};