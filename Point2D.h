#pragma once

#include <stdbool.h>
#include <stdint.h>

typedef struct
{
  uint16_t x;
  uint16_t y; 
} Point2D;
#define Vector2D Point2D

bool Point2D_isValid(Point2D point);
