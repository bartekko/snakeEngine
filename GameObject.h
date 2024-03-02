#pragma once
#include "Message.h"
#define MAX_GAME_OBJECTS 1024

#define OBJID_INVALID -1;
typedef int ObjectID;

struct GameObject;

typedef struct GameObject GameObject;

typedef GameObject* (*creatorFunction)(Message);
typedef int    (*destroyerFunction)();
typedef bool   (*messageHandler)(void* ,Message* );
typedef void   (*rendererFunction)();
typedef bool   (*msgHandlerFunction)(Message*);

typedef struct GameObject {
    ObjectType ot;
    void* objData;
} GameObject;

//bool GameObject_isValid(int n);
GameObject* GameObject_create(Message msg);
void GameObject_delete(Message msg);
bool GameObject_Exists(int ID);
GameObject* GameObject_get(int ID);
