#pragma once

#include "Point2D.h"

#include <stddef.h>
#include <stdbool.h>

typedef enum{
  OT_SNAKE=0,
  OT_FOOD,
  OT_BOARD,
  OT_SCORE,
  OT_COUNT,
  OT_INVALID,

} ObjectType;

typedef struct Message
{
  int targetID;
  bool handled;
  char data[];
} Message;

typedef struct Object_Create_req{
    ObjectType objectType;
    Point2D location;
} Object_Create_req;


void Message_send(int targetID,void* data, size_t len);
Message*  Message_receive();
