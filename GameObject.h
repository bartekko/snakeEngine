#pragma once
#include "Message.h"
#define MAX_GAME_OBJECTS 1024

struct GameObject;

typedef struct GameObject GameObject;

typedef GameObject* (*creatorFunction)(Message);
typedef int    (*destroyerFunction)();
typedef void   (*ticUpdateFunction)();
typedef void   (*rendererFunction)();
typedef bool   (*msgHandlerFunction)(Message*);

typedef struct GameObject {
    ObjectType ot;
    void* objData;
} GameObject;

//bool GameObject_isValid(int n);
GameObject* GameObject_create(Object_Create_req req);
void GameObject_delete(int ID);
bool GameObject_Exists(int ID);
GameObject* GameObject_get(int ID);

bool GameObject_HandleMessage(Message* msg);
