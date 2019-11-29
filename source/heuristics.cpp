#include <stdio.h>
#include <algorithm>
#include <vector>
#include "../includes/heuristics.hpp"

float out_of_place(Board &b)
{
    int h = 0;
    for (int i = 0; i < GAME_SIZE; i++)
    {
        for (int j = 0; j < GAME_SIZE; j++)
        {
            if (b.matrix[i][j] != b.final_matrix[i][j])
                ++h;
        }
    }
    return h;
}

float out_of_order(Board &b)
{
    std::vector<int> array;
    int h = 0;

    for (int i = 0; i < GAME_SIZE; i++)
    {
        for (int j = 0; j < GAME_SIZE; j++)
        {
            array.push_back(b.matrix[i][j]);
        }
    }

    for (unsigned int i = 1; i < array.size() - 1; i++)
    {
        if ((array[i - 1] != (array[i] - 1)) && array[i - 1] != 0)
            h++;
    }
    return h;
}

float manhattan_distance(Board &b)
{
    int h = 0;
    int i_ = 0;
    int j_ = 0;

    for (int i = 0; i < GAME_SIZE; i++)
    {
        for (int j = 0; j < GAME_SIZE; j++)
        {
            if (b.matrix[i][j] == 0)
            {
                h += 3 - i + 3 - j;
            }
            else
            {
                i_ = (b.matrix[i][j] - 1) / 4;
                j_ = (b.matrix[i][j] - 1) % 4;
                h += abs(i_ - i) + abs(j_ - j);
            }
        }
    }
    return h;
}

float heuristic_4(Board &b)
{
    const float p1 = 0.19;
    const float p2 = 0.15;
    const float p3 = 0.66;

    return p1 * out_of_order(b) + p2 * out_of_place(b) + p3 * manhattan_distance(b);
}

float heuristic_5(Board &b)
{
    const float heuristics[3] = {out_of_order(b), out_of_place(b), manhattan_distance(b)};

    return *std::max_element(heuristics, heuristics + 3);
}