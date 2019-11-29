#pragma once

#include "board.hpp"

float out_of_place(Board &);
float out_of_order(Board &);
float manhattan_distance(Board &);
float heuristic_4(Board &);
float heuristic_5(Board &);