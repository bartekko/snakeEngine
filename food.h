#include "Point2D.h"
typedef struct{
    Point2D position;
} Food;

Food create_food(Point2D _position);
void destroy_food(Food food);

