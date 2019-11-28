#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <stdlib.h>
#include <vector>
#include "../includes/heuristics.hpp"

float heuristc_1(Board &b)
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

float heuristc_2(Board &b)
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

float heuristc_3(Board &b)
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

float heuristc_4(Board &b)
{
    const float p1 = 0.19;
    const float p2 = 0.15;
    const float p3 = 0.66;

    return p1 * heuristc_1(b) + p2 * heuristc_2(b) + p3 * heuristc_3(b);
}

float heuristc_5(Board &b)
{
    const float heuristics[3] = {heuristc_1(b), heuristc_2(b), heuristc_3(b)};

    return *std::max_element(heuristics, heuristics + 3);
}