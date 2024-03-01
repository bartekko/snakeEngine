#pragma once
#include "GameObject.h"

typedef struct InputMapping
{
    Message msg;
    int key;
} InputMapping;

void Input_registerObject(int ObjectID, InputMapping map);
