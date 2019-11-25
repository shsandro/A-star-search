#include <algorithm>
#include "./includes/game.hpp"

bool compare(const Node *i, const Node *j) { return (i->f < j->f); }

int main(int argc, char const *argv[])
{
    Game game = Game();

    while (!game.open_list.empty())
    {
        std::sort(game.open_list.begin(), game.open_list.end(), compare); // orneda o conjunto A
        Node *first_element = game.open_list[0];                          // obtém o primeiro elemento
        std::vector<Node *>::iterator element_to_be_removed = game.open_list.begin();
        game.open_list.erase(element_to_be_removed); // remove o primeiro elemento

        if (first_element->check_success())
        {
            // print_board(first_element->board);
            std::cout << first_element->g << std::endl;
            return 0;
        }

        game.closed_list.push_back(first_element); // adiciona o elemento no conjunto F
        game.make_nexts(first_element);            // gera os descendentes e os adiciona no conjunto correto
    }

    return 0;
}
