#include "./includes/board.hpp"
#include "./includes/node.hpp"
#include "./includes/game.hpp"

int main(int argc, char const *argv[])
{
    Game moa = Game();

    Node first_element = (moa.A.begin());

    moa.make_nexts(*first_element);
    return 0;
}
