#pragma once

#include "Point2D.h"
#include "Snake.h"

#include <stdbool.h>

typedef struct{
    Point2D size;
} Board;

void* Board_create(Point2D size);
void Board_delete(Board* board);
bool Board_SnakeCollision(Board* board, Snake* snake);