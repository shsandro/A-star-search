#pragma once

#include <iostream>
#include <vector>
#include "board.hpp"
#include "node.hpp"

class Game
{
public:
    std::vector<Node *> open_list;
    std::vector<Node *> closed_list;

public:
    void make_nexts(Node *);
    bool check_open_list(Node &);
    bool check_closed_list(Node &);
    bool check_closed_open(Node &);
    Game();
};