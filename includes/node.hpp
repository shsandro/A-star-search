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

public:
    float make_heuristic(Node &);
    bool check_success();
    Node();
    Node(Node &);
};

void print_board(Board &);