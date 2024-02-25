#include <stdbool.h>
#include <stdint.h>

#include "Point2D.h"

bool Point2D_isValid(Point2D point)
{
  return !(point.x==INT16_MAX);
}
int Point2D_cmp(Point2D* a,Point2D* b)
{
  if (a->x==b->x && a->y==b->y) return 0;
  return -1;
}