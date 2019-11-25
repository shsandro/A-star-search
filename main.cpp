#include <algorithm>
#include "./includes/game.hpp"

bool compare(const Node *i, const Node *j) { return (i->f < j->f); }

int main(int argc, char const *argv[])
{
    Game moa = Game();

    while (!moa.open_list.empty())
    {
        std::sort(moa.open_list.begin(), moa.open_list.end(), compare);
        Node *first_element = moa.open_list[0];
        std::vector<Node *>::iterator element_to_be_removed = moa.open_list.begin();
        moa.open_list.erase(element_to_be_removed);

        std::cout << first_element << std::endl;

        std::cout << std::endl
                  << "------------- Iniciei ---------------" << std::endl;
        std::cout << "f(x) = " << first_element->f << std::endl;
        std::cout << "g(x) = " << first_element->g << std::endl;
        std::cout << "h(x) = " << first_element->h << std::endl;
        print_board(first_element->board);
        std::cout << std::endl;

        if (first_element->check_success())
        {
            print_board(first_element->board);
            std::cout << first_element->g << std::endl;
            return true;
        }

        std::cout << "Tamnho conjunto A antes = " << moa.open_list.size() << std::endl;

        moa.closed_list.push_back(first_element);
        moa.make_nexts(first_element);

        std::cout << "Tamnho conjunto A depois = " << moa.open_list.size() << std::endl;
    }

    // for (int i = 0; i < 9; i++)
    // {
    //     std::sort(moa.open_list.begin(), moa.open_list.end(), compare);
    //     Node *first_element = moa.open_list[0];
    //     std::vector<Node *>::iterator element_to_be_removed = moa.open_list.begin();
    //     moa.open_list.erase(element_to_be_removed);

    //     std::cout << first_element << std::endl;

    //     std::cout << std::endl
    //               << "------------- Iniciei ---------------" << std::endl;
    //     std::cout << "f(x) = " << first_element->f << std::endl;
    //     std::cout << "g(x) = " << first_element->g << std::endl;
    //     std::cout << "h(x) = " << first_element->h << std::endl;
    //     print_board(first_element->board);
    //     std::cout << std::endl;

    //     if (first_element->check_success())
    //     {
    //         print_board(first_element->board);
    //         std::cout << first_element->g << std::endl;
    //         return true;
    //     }

    //     std::cout << "Tamnho conjunto A antes = " << moa.open_list.size() << std::endl;

    //     moa.closed_list.push_back(first_element);
    //     moa.make_nexts(first_element);

    //     std::cout << "Tamnho conjunto A depois = " << moa.open_list.size() << std::endl;
    // }

    // auto first_element = moa.A.begin();
    // moa.make_nexts(*first_element);
    // moa.open_list.erase(first_element);

    // std::cout << std::endl
    //           << std::endl
    //           << "Começando segunda iteração" << std::endl
    //           << std::endl;

    // first_element = moa.open_list.begin();
    // moa.make_nexts(*first_element);
    // moa.open_list.erase(first_element);
    return 0;
}
