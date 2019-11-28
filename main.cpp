#include "./includes/game.hpp"

int main(int argc, char const *argv[])
{
    Board *initial_board = new Board();
    Game game = Game(initial_board);

    std::pair<std::string, Node *> min_element;
    std::unordered_map<std::string, Node *>::iterator it;

    while (!game.open_list.empty())
    {
        min_element = std::make_pair(game.heap.top().first, game.heap.top().second);
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
