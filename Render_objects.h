#pragma once

#include <ncurses.h>

#include "Snake.h"
#include "Food.h"
#include "Board.h"

void Render_Snake(Snake* snake);
void Render_Food(Food* food);
void Render_Board(Board* board);