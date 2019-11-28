#include "./includes/game.hpp"
#include "./includes/heuristics.hpp"

int main(int argc, char const *argv[])
{
    Game::make_heuristic = &heuristc_5;
    Board *initial_board = new Board();
    Game game = Game(initial_board);

    std::pair<std::string, Node *> min_element;
    std::unordered_map<std::string, Node *>::iterator it;

    while (!game.open_list.empty())
    {
        min_element = game.heap.top();
        game.heap.pop();
        it = game.open_list.find(min_element.first);
        if (it != game.open_list.end())
        {
            game.open_list.erase(min_element.first);
            game.closed_list.insert(min_element);

            if (min_element.second->check_success())
            {
                std::cout << min_element.second->g << std::endl;
                return 0;
            }

            game.make_nexts(min_element.second);
        }
    }

    return 0;
}
