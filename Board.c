
#include "Board.h"

Board globoard;

void* Board_create(Point2D size)
{
    globoard.size=size;
    return &globoard;
}
void Board_delete(Board* board)
{
    //Do nothing, Board is currently statically allocated
}

bool Board_SnakeCollision(Board* board, Snake* snake)
{
    Point2D* head = Snake_getHead(snake);
    if (head->x <= 0 ||
        head->y <= 0 ||
        head->x >= board->size.x ||
        head->y >= board->size.y)
    {
        return true;
    }
    return false;

}