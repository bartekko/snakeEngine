#include "Message.h"
#include <stddef.h>
#include <string.h>
#define MESSAGE_BUFFER_SIZE 1024

typedef struct MessageBuffer{
  Message messages[MESSAGE_BUFFER_SIZE];

int writePos;
int readPos;

} MessageBuffer;

MessageBuffer msgBuf;

void Message_send(int targetID,void* data, size_t len)
{
  msgBuf.messages[msgBuf.writePos].targetID=targetID;
  memcpy(&msgBuf.messages->c,data,len);
msgBuf.writePos++;
}
Message*  Message_receive()
{
  if(msgBuf.readPos>=msgBuf.writePos)
  {
    return NULL;
  }
  else return &msgBuf.messages[msgBuf.readPos++];
}
