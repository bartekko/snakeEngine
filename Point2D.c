#include <stdbool.h>
#include <stdint.h>

#include "Point2D.h"

bool Point2D_isValid(Point2D point)
{
  return !(point.x==UINT16_MAX);
}