#include "../includes/game.hpp"

std::string matrix_to_string(Board *b)
{
    std::string str;
    for (int i = 0; i < GAME_SIZE; i++)
    {
        for (int j = 0; j < GAME_SIZE; j++)
        {
            str += std::to_string(b->matrix[i][j]);
        }
    }
    return str;
}

Game::Game(Board *initial_board)
{
    Node *head = new Node(initial_board);
    std::string key = matrix_to_string(head->board);
    this->open_list.insert(std::pair<std::string, Node *>(key, head));
    this->heap.push(std::pair<std::string, Node *>(key, head));
}

void Game::make_nexts(Node *pai)
{
    Node father = *pai;

    Node *child_1 = new Node(father, father.board);
    Node *child_2 = new Node(father, father.board);
    Node *child_3 = new Node(father, father.board);
    Node *child_4 = new Node(father, father.board);

    std::pair<int, int> position = father.board->empty_position;

    if (position.first != 0)
    {
        child_1->board->update_board(std::make_pair(position.first - 1, position.second));
        child_1->h = child_1->board->make_heuristic();
        child_1->f = child_1->h + child_1->g;

        std::string key = matrix_to_string(child_1->board);
        check_open_list(*child_1, key);
        if (this->check_a_f(*child_1, key))
        {
            this->open_list.insert(std::pair<std::string, Node *>(key, child_1));
            this->heap.push(std::pair<std::string, Node *>(key, child_1));
        }
        else
            delete child_1;
    }
    if (position.first != 3)
    {
        child_2->board->update_board(std::make_pair(position.first + 1, position.second));
        child_2->h = child_2->board->make_heuristic();
        child_2->f = child_2->h + child_2->g;

        std::string key = matrix_to_string(child_2->board);
        check_open_list(*child_2, key);
        if (this->check_a_f(*child_2, key))
        {
            this->open_list.insert(std::pair<std::string, Node *>(key, child_2));
            this->heap.push(std::pair<std::string, Node *>(key, child_2));
        }
        else
            delete child_2;
    }
    if (position.second != 0)
    {
        child_3->board->update_board(std::make_pair(position.first, position.second - 1));
        child_3->h = child_3->board->make_heuristic();
        child_3->f = child_3->h + child_3->g;

        std::string key = matrix_to_string(child_3->board);
        check_open_list(*child_3, key);
        if (this->check_a_f(*child_3, key))
        {
            this->open_list.insert(std::pair<std::string, Node *>(key, child_3));
            this->heap.push(std::pair<std::string, Node *>(key, child_3));
        }
        else
            delete child_3;
    }
    if (position.second != 3)
    {
        child_4->board->update_board(std::make_pair(position.first, position.second + 1));
        child_4->h = child_4->board->make_heuristic();
        child_4->f = child_4->h + child_4->g;

        std::string key = matrix_to_string(child_4->board);
        check_open_list(*child_4, key);
        if (this->check_a_f(*child_4, key))
        {
            this->open_list.insert(std::pair<std::string, Node *>(key, child_4));
            this->heap.push(std::pair<std::string, Node *>(key, child_4));
        }
        else
            delete child_4;
    }
}

void Game::check_open_list(Node &node, std::string key)
{
    std::unordered_map<std::string, Node *>::iterator it = this->open_list.find(key);
    if (it != this->open_list.end())
    {
        if (it->second->g > node.g)
        {
            this->open_list.erase(key);
        }
    }
}

// bool Game::check_closed_list(Node &node)
// {
//     for (std::vector<Node *>::iterator it = this->closed_list.begin(); it != this->closed_list.end(); ++it)
//     {
//         if ((*it)->f == node.f)
//         {
//             if (Board::check_board((*it)->board, node.board))
//             {
//                 if (node.g < (*it)->g)
//                 {
//                     this->closed_list.erase(it);
//                 }
//             }
//         }
//     }
//     return true;
// }

bool Game::check_a_f(Node &node, std::string key)
{
    std::unordered_map<std::string, Node *>::iterator it_open = this->open_list.find(key);
    std::unordered_map<std::string, Node *>::iterator it_closed = this->closed_list.find(key);

    return (it_open != this->open_list.end() || it_closed != this->closed_list.end()) ? false : true;
}