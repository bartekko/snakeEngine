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

void Message_send(MessageType mt, int targetID,void* data, size_t len)
{
  msgBuf.messages[msgBuf.writePos].type=mt;
  msgBuf.messages[msgBuf.writePos].targetID=targetID;
  msgBuf.messages[msgBuf.writePos].handled==false;
  if(len && data)
  {
    memcpy(&msgBuf.messages[msgBuf.writePos].c,data,len);
  }
  msgBuf.writePos=(msgBuf.writePos+1)%MESSAGE_BUFFER_SIZE;
}
Message*  Message_receive()
{
  if(msgBuf.readPos>= msgBuf.writePos)
  {
    msgBuf.readPos=0;
    msgBuf.writePos=0;
  }

  if(msgBuf.readPos>=msgBuf.writePos)
  {
    return NULL;
  }
  else return &msgBuf.messages[msgBuf.readPos++];
}
