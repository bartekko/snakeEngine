#include <stdbool.h>
#include <stdint.h>

#include "Point2D.h"

bool Point2D_isValid(Point2D point)
{
  return !(point.x==INT16_MAX);
}