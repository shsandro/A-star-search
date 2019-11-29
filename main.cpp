#include <map>
#include "./includes/game.hpp"
#include "./includes/heuristics.hpp"

typedef float (*MyHeuristic)(Board &);

bool read_command_line(int argc, char const *argv[])
{
    std::map<std::string, MyHeuristic> heuristics;
    bool valid;

    heuristics["out_of_place"] = &out_of_place;
    heuristics["out_of_order"] = &out_of_order;
    heuristics["manhattan_distance"] = &manhattan_distance;
    heuristics["heuristic_4"] = &heuristic_4;
    heuristics["heuristic_5"] = &heuristic_5;

    if (argc >= 3)
    {
        for (int i = 1; i < argc; ++i)
        {
            if (std::string(argv[i]) == std::string("-h") || std::string(argv[i]) == std::string("--help"))
            {
                std::cout << "-h | --help: Help" << std::endl
                          << "-i: Heuristic to be used" << std::endl
                          << std::endl
                          << "Run 'make' to compile" << std::endl
                          << "Run './a-star -i <heuristic name> [-h]'" << std::endl
                          << std::endl
                          << "Default heuristics:" << std::endl
                          << "out_of_place: number of pieces of out place compared to final configuration." << std::endl
                          << "out_of_order: number of pieces out of order in the numerical sequence, following the order of positions on the board." << std::endl
                          << "manhattan_distance: standart Manhattan Distance." << std::endl
                          << "heuristic_4: linear combination of the three previous heuristics, where the sum of the coefficients must be equal one." << std::endl
                          << "heuristic_5: max value between out_of_place, out_of_order and manhattan_distance." << std::endl;
            }
            else if (std::string(argv[i]) == std::string("-i") && (argc - i) > 1)
            {
                std::map<std::string, MyHeuristic>::iterator it;
                it = heuristics.find(argv[i + 1]);
                if (it != heuristics.end())
                    Game::make_heuristic = heuristics[argv[i + 1]];
                else
                {
                    std::cout << std::endl
                              << "Invalid heuristic" << std::endl;
                    return false;
                }
                ++i;
                valid = true;
            }
            else
            {
                std::cout << "Invalid argument: '" << argv[i] << "'" << std::endl;
                return false;
            }
        }
    }
    else
    {
        std::cout << "Require at least two arguments." << std::endl;
        return false;
    }
    return valid ? true : false;
}

int main(int argc, char const *argv[])
{
    if (!read_command_line(argc, argv))
        return false;

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
