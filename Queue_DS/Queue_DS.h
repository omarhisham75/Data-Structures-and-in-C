#ifndef QUEUE_DS_H
#define QUEUE_DS_H

#include <stdlib.h>
#include "Platform_Types.h"

typedef struct {
    void **QueueArray ;
    uint32 QueueMaxSize ;
    uint32 ElementCount ;
    sint32 QueueFront ;
    sint32 QueueRear ;
}Queue ;

typedef enum {
    Queue_NOK,
    Queue_OK,
    QueueIsFull,
    QueueIsEmpty,
    QueueNULLPtr,
}QueueStatus ;

void *QueueCreate(uint32 maxSize,QueueStatus *ret);
QueueStatus Enqueue(Queue *QueueObj,void *ItemPtr);
void *Dequeue(Queue *QueueObj,QueueStatus *ret);
void *QueueFront(Queue *QueueObj,QueueStatus *ret);
void *QueueRear(Queue *QueueObj,QueueStatus *ret);
QueueStatus QueueCount(Queue *QueueObj,uint32 *QueueCount);

#endif // QUEUE_DS_H
