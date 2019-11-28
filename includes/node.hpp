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
    Board *board;
    Node *father;

public:
    bool check_success();
    Node(Board *);
    Node(Node &, Board *);
};

void print_board(Board &);