#include "./includes/game.hpp"

int main(int argc, char const *argv[])
{
    Board *initial_board = new Board();
    Game moa = Game(initial_board);

    std::pair<std::string, Node *> min_element;
    std::unordered_map<std::string, Node *>::iterator it;

    while (!moa.open_list.empty())
    {
        do
        {
            min_element = std::make_pair(moa.heap.top().first, moa.heap.top().second);
            moa.heap.pop();
            it = moa.open_list.find(min_element.first);

        } while (it == moa.open_list.end());

        moa.open_list.erase(min_element.first);
        moa.closed_list.insert(min_element);

        if (min_element.second->check_success())
        {
            std::cout << min_element.second->g << std::endl;
            return 0;
        }

        moa.make_nexts(min_element.second);
    }
    return 0;
}
