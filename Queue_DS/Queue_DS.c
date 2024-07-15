#include "Queue_DS.h"

static QueueStatus QueueFull(Queue *QueueObj){
    return (QueueObj->ElementCount == QueueObj->QueueMaxSize);
}


static QueueStatus QueueEmpty(Queue *QueueObj){
    return (0 == QueueObj->ElementCount);
}


void *QueueCreate(uint32 maxSize,QueueStatus *ret){
    Queue *MyQueuePtr = NULL;
    MyQueuePtr = (Queue *)malloc(sizeof(Queue));
    if (NULL == MyQueuePtr){
        *ret = QueueNULLPtr;
        MyQueuePtr = NULL;
    }
    else {
        MyQueuePtr->QueueArray = (void **)calloc(maxSize,sizeof(void*));
        if(NULL == MyQueuePtr->QueueArray){
            free(MyQueuePtr);
            *ret = QueueNULLPtr;
            MyQueuePtr = NULL;
        }
        else {
            MyQueuePtr->ElementCount = 0;
            MyQueuePtr->QueueFront = -1;
            MyQueuePtr->QueueRear = -1;
            MyQueuePtr->QueueMaxSize = maxSize ;
            *ret=Queue_OK;
        }
    }
    return MyQueuePtr;
}


QueueStatus Enqueue(Queue *QueueObj,void *ItemPtr){
    QueueStatus ret = Queue_OK ;
    if((NULL == QueueObj) || (NULL == ItemPtr)){
        ret = QueueNULLPtr;
    }
    else{
        if(QueueObj->ElementCount==QueueObj->QueueMaxSize){
            ret = QueueIsFull;
        }
        else{
            (QueueObj->QueueRear)++;
            if(QueueObj->QueueRear==QueueObj->QueueMaxSize){
                QueueObj->QueueRear=0;
            }
            else {/* Nothing */}
            QueueObj->QueueArray[QueueObj->QueueRear]=ItemPtr;
            if(0 == QueueObj->ElementCount){
                QueueObj->QueueFront = 0;
                (QueueObj->ElementCount)++;
            }
            else{
                (QueueObj->ElementCount)++;
            }
            ret = Queue_OK;
        }
    }
    return ret;
}


void *Dequeue(Queue *QueueObj,QueueStatus *ret){
    void *RetElment = NULL;
    if((NULL == QueueObj) || (NULL == ret)){
        *ret = QueueNULLPtr ;
    }
    else {
        if(QueueEmpty(QueueObj)){
            *ret = QueueIsEmpty ;
            RetElment=NULL;
        }
        else{
            RetElment = QueueObj->QueueArray[QueueObj->QueueFront];
            (QueueObj->QueueFront)++;
            if(QueueObj->QueueFront == QueueObj->QueueMaxSize){
                QueueObj->QueueFront = 0;
            }
            else {/* Nothing */}
            if(1 == QueueObj->ElementCount){
                QueueObj->QueueFront = -1;
                QueueObj->QueueRear = -1;
            }
            else{/* Nothing*/}
            (QueueObj->ElementCount)--;
            *ret = Queue_OK;
        }
    }
    return RetElment;
}


void *QueueFront(Queue *QueueObj,QueueStatus *ret){
    void *RetElement = NULL;
    if((NULL == QueueObj) || (NULL == ret)){
        *ret = QueueNULLPtr ;
        RetElement = NULL;
    }
    else {
        if(QueueEmpty(QueueObj)){
                *ret = QueueIsEmpty;
                RetElement = NULL;
            }
        else{
        RetElement = QueueObj->QueueArray[QueueObj->QueueFront];
        *ret = Queue_OK;
        }
    }
    return RetElement;
}


void *QueueRear(Queue *QueueObj,QueueStatus *ret){
    void *RetElement = NULL;
    if((NULL == QueueObj) || (NULL == ret)){
        *ret = QueueNULLPtr ;
        RetElement = NULL;
    }
    else {
        if(QueueEmpty(QueueObj)){
                *ret = QueueIsEmpty;
                RetElement = NULL;
            }
        else{
        RetElement = QueueObj->QueueArray[QueueObj->QueueRear];
        *ret = Queue_OK;
        }
    }
    return RetElement;

}


QueueStatus QueueCount(Queue *QueueObj,uint32 *QueueCount){
    QueueStatus ret = Queue_NOK;
    if((NULL == QueueObj) || (NULL == QueueCount)){
        ret = QueueNULLPtr ;
    }
    else {
        *QueueCount=QueueObj->ElementCount ;
        ret = Queue_OK;
        }
    return ret;

}




