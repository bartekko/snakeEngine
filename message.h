#include "GameObject.h"
typedef struct
{
  GameObject* target;
  bool handled;
  char data[];
} Message;

void Message_send(GameObject,char[]);