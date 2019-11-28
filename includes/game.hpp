#pragma once

#include <iostream>
#include <unordered_map>
#include <queue>
#include <deque>
#include <algorithm>
#include "board.hpp"
#include "node.hpp"

struct CompareSecond
{
    bool operator()(const std::pair<std::string, Node *> &left, const std::pair<std::string, Node *> &right) const
    {
        return left.second->f > right.second->f;
    }
};

class Game
{
public:
    std::priority_queue<std::pair<std::string, Node *>, std::deque<std::pair<std::string, Node *>>, CompareSecond> heap;
    std::unordered_map<std::string, Node *> open_list;
    std::unordered_map<std::string, Node *> closed_list;

public:
    void make_nexts(Node *);
    void check_open_list(Node &, std::string);
    bool check_closed_list(Node &, std::string);
    bool check_a_f(Node &, std::string);
    Game(Board *);
};