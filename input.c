#include "input.h"
#include <ncurses.h>
#define MAX_INPUT_MAPPINGS 64


InputMapping inputMapping[MAX_INPUT_MAPPINGS];
void Input_registerObject(int ObjectID, int key, msg_Input input)
{
    static size_t registeredInputs=0;
    InputMapping* map=&inputMapping[registeredInputs];
    map->ObjectID=ObjectID;
    map->key=key;
    map->ev=input;
    registeredInputs++;
}
size_t Input_Registered(int key)
{
    for (size_t i = 0; i < MAX_INPUT_MAPPINGS; i++)
    {
        if(inputMapping[i].key==key)
        {
            return i;
        }
    }
    return -1;
}

int glob_c=0;
int Input_scan()
{
    int c=ERR;
    if(glob_c!=ERR)
    {
        size_t i=Input_Registered(glob_c);
        if(i!=-1)
        {
            Message_send(MT_INPUT,
                         inputMapping[i].ObjectID,
                         &inputMapping[i].ev,
                         sizeof(inputMapping[i].ev));
        }

    }
    glob_c=ERR;
    return c;
}

void Input_waitUntilNextFrame()
{
    halfdelay(2);
    glob_c=getch();
}
