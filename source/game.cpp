#include "../includes/game.hpp"

Game::Game()
{
    Node *head = new Node();
    this->open_list.push_back(head);
}

void Game::make_nexts(Node *pai)
{
    Node father = *pai;
    father.g--;

    Node *child_1 = new Node(father);
    Node *child_2 = new Node(father);
    Node *child_3 = new Node(father);
    Node *child_4 = new Node(father);

    std::pair<int, int> position = father.board.empty_position;

    if (position.first != 0)
    {
        child_1->board.update_board(std::make_pair(position.first - 1, position.second));
        child_1->h = child_1->board.make_heuristic();
        child_1->f = child_1->h + child_1->g;

        // print_board(child_1->board);
        check_open_list(*child_1);
        if (!this->check_closed_open(*child_1))
            this->open_list.push_back(child_1);
        else
            delete child_1;
    }
    if (position.first != 3)
    {
        child_2->board.update_board(std::make_pair(position.first + 1, position.second));
        child_2->h = child_2->board.make_heuristic();
        child_2->f = child_2->h + child_2->g;

        // print_board(child_2->board);

        check_open_list(*child_2);
        if (!this->check_closed_open(*child_2))
            this->open_list.push_back(child_2);
        else
            delete child_2;
    }
    if (position.second != 0)
    {
        child_3->board.update_board(std::make_pair(position.first, position.second - 1));
        child_3->h = child_3->board.make_heuristic();
        child_3->f = child_3->h + child_3->g;

        // print_board(child_3->board);

        check_open_list(*child_3);
        if (!this->check_closed_open(*child_3))
            this->open_list.push_back(child_3);
        else
            delete child_3;
    }
    if (position.second != 3)
    {
        child_4->board.update_board(std::make_pair(position.first, position.second + 1));
        child_4->h = child_4->board.make_heuristic();
        child_4->f = child_4->h + child_4->g;

        // print_board(child_4->board);

        check_open_list(*child_4);
        if (!this->check_closed_open(*child_4))
            this->open_list.push_back(child_4);
        else
            delete child_4;
    }
}

bool Game::check_open_list(Node &node)
{
    for (std::vector<Node *>::iterator it = this->open_list.begin(); it != this->open_list.end(); ++it)
    {
        if ((*it)->f == node.f)
        {
            if (Board::check_board((*it)->board, node.board))
            {
                if (node.g <= (*it)->g)
                {
                    this->open_list.erase(it);
                }
            }
        }
    }
    return true;
}

bool Game::check_closed_list(Node &node)
{
    for (std::vector<Node *>::iterator it = this->closed_list.begin(); it != this->closed_list.end(); ++it)
    {
        if ((*it)->f == node.f)
        {
            if (Board::check_board((*it)->board, node.board))
            {
                if (node.g < (*it)->g)
                {
                    this->closed_list.erase(it);
                }
            }
        }
    }
    return true;
}

bool Game::check_closed_open(Node &node)
{
    bool aux1 = false, aux2 = false;

    for (std::vector<Node *>::iterator it = this->open_list.begin(); it != this->open_list.end(); ++it)
    {
        if ((*it)->f == node.f)
        {
            if (Board::check_board((*it)->board, node.board))
            {
                aux1 = true;
            }
        }
    }

    for (std::vector<Node *>::iterator it = this->closed_list.begin(); it != this->closed_list.end(); ++it)
    {
        if ((*it)->f == node.f)
        {
            if (Board::check_board((*it)->board, node.board))
            {
                aux2 = true;
            }
        }
    }
    return aux1 && aux2;
}