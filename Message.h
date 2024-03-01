#pragma once

#include "Point2D.h"

#include <stddef.h>
#include <stdbool.h>

#define MSGTGT_GAME_ENGINE -1


typedef enum{
  OT_SNAKE=0,
  OT_FOOD,
  OT_BOARD,
  OT_SCORE,
  OT_COUNT,
  OT_INVALID,

} ObjectType;

typedef enum{
  MT_CREATE_OBJ=0,
  MT_DESTROY_OBJ,
  MT_TICK,
  MT_INPUT,
  MT_COLLISION,
  MT_COUNT,
  MT_INVALID,

} MessageType;



typedef struct msg_Create_Object{
    ObjectType objectType;
    Point2D location;
} msg_Create_Object;

typedef struct msg_DestroyObject{
  char nothing;
} msg_DestroyObject;

typedef struct msg_GameMessage
{
    bool quit;
} msg_GameMessage;

typedef enum{
  IN_UP,
  IN_DOWN,
  IN_LEFT,
  IN_RIGHT,
  IN_EXIT
} msg_Input;

typedef struct Message
{
  MessageType type;
  int targetID;
  bool handled;
  union {
    msg_Create_Object create;
    msg_DestroyObject destroy;
    msg_GameMessage   gameMessage;
    msg_Input         input;
  } c; //for "content"
} Message;


void Message_send(MessageType mt, int targetID,void* data, size_t len);
Message*  Message_receive();
