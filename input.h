#pragma once
#include "GameObject.h"
#include "Message.h"
typedef struct InputMapping
{
    int key;
    msg_Input ev;
    int ObjectID;
} InputMapping;

void Input_registerObject(int ObjectID, int key, msg_Input input);
