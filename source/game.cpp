#include "../includes/game.hpp"

Game::Game()
{
    std::cout << "Construtor Game" << std::endl;
    Node *head = new Node();
    this->open_list.push_back(head);
    std::cout << "Terminei Game -> " << this->open_list.size() << std::endl;
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

        print_board(child_1->board);

        if (this->check_open_list(*child_1))
        {
            this->open_list.push_back(child_1);
            std::cout << "f(x) do filho " << child_1->f << std::endl;
            std::cout << "Inseri no conjunto o filho 1 -> " << this->open_list.size() << std::endl;
        }
        else
            delete child_1;
    }
    if (position.first != 3)
    {
        child_2->board.update_board(std::make_pair(position.first + 1, position.second));
        child_2->h = child_2->board.make_heuristic();
        child_2->f = child_2->h + child_2->g;

        print_board(child_2->board);
        if (this->check_open_list(*child_2))
        {
            this->open_list.push_back(child_2);
            std::cout << "f(x) do filho " << child_2->f << std::endl;
            std::cout << "Inseri no conjunto o filho 2 -> " << this->open_list.size() << std::endl;
        }
        else
            delete child_2;
    }
    if (position.second != 0)
    {
        child_3->board.update_board(std::make_pair(position.first, position.second - 1));
        child_3->h = child_3->board.make_heuristic();
        child_3->f = child_3->h + child_3->g;

        print_board(child_3->board);

        if (this->check_open_list(*child_3))
        {
            this->open_list.push_back(child_3);
            std::cout << "f(x) do filho " << child_3->f << std::endl;
            std::cout << "Inseri no conjunto o filho 3 -> " << this->open_list.size() << std::endl;
        }
        else
            delete child_3;
    }
    if (position.second != 3)
    {
        child_4->board.update_board(std::make_pair(position.first, position.second + 1));
        child_4->h = child_4->board.make_heuristic();
        child_4->f = child_4->h + child_4->g;

        print_board(child_4->board);

        if (this->check_open_list(*child_4))
        {
            this->open_list.push_back(child_4);
            std::cout << "f(x) do filho " << child_4->f << std::endl;
            std::cout << "Inseri no conjunto o filho 4 -> " << this->open_list.size() << std::endl;
        }
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
                    std::cout << "Tamanho antes " << this->open_list.size() << std::endl;
                    this->open_list.erase(it);
                    std::cout << "Tamnho depois " << this->open_list.size() << std::endl;
                    return true;
                }
                return false;
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
                    return true;
                }
                return false;
            }
        }
    }

    return true;
}