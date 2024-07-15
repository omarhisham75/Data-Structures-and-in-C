#ifndef DYNAMIC_SD_H
#define DYNAMIC_SD_H
#include "Platform_Types.h"

typedef struct {
    void **StackArray;
    uint32 ElemntCount;
    uint32 StackMaxSize;
    sint32 StackTop;
}D_S ;

typedef enum {
    Stack_NOK,
    Stack_OK,
    StackIsFull,
    StackIsEmpty,
    StackIsNotFull,
    StackIsNotEmpty,
    Stack_NULL_Pointer
}Stack_status;

D_S *StackCreate(uint32 MaxSize , Stack_status *ret);
D_S *StackDestroy(D_S *stackObj , Stack_status *ret);
Stack_status StackPuch(D_S *stackObj , void *ValuePtr);
void *StackPop(D_S *stackObj , Stack_status *ret);
void *StackTop(D_S *stackObj , Stack_status *ret);
Stack_status StackCount(D_S *stackObj,uint32 *StackCounter);




#endif // DYNAMIC_SD_H
