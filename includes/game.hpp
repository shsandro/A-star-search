#pragma once

#include <iostream>
#include <set>
#include "board.hpp"
#include "node.hpp"

class Game
{
public:
    std::set<Node *, classcomp> A;
    std::set<Node *, classcomp> F;
    Game();
    void make_nexts(Node &father);
};

Game::Game()
{
    Node *head = new Node();
    A.insert(head);
}

void Game::make_nexts(Node &father)
{
    Node *child_1 = new Node(father);
    Node *child_2 = new Node(father);
    Node *child_3 = new Node(father);
    Node *child_4 = new Node(father);
    std::pair<int, int> position = father.board.empty_position;

    if (position.first != 0)
    {
        child_1->board.update_board(std::make_pair(position.first - 1, position.second));
        child_1->f = child_1->board.make_heuristic() + child_1->g;

        A.insert(child_1);

        print_board(child_1->board);
    }
    if (position.first != 3)
    {
        child_2->board.update_board(std::make_pair(position.first + 1, position.second));
        child_2->f = child_2->board.make_heuristic() + child_2->g;

        A.insert(child_2);

        print_board(child_2->board);
    }
    if (position.second != 0)
    {
        child_3->board.update_board(std::make_pair(position.first, position.second - 1));
        child_3->f = child_3->board.make_heuristic() + child_3->g;

        A.insert(child_3);

        print_board(child_3->board);
    }
    if (position.second != 3)
    {
        child_4->board.update_board(std::make_pair(position.first, position.second + 1));
        child_4->f = child_4->board.make_heuristic() + child_4->g;

        A.insert(child_4);

        print_board(child_4->board);
    }
}
