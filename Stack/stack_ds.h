#ifndef STACK_DS_H
#define STACK_DS_H
#include "Platform_Types.h"

#define Max_Stack_size 3
#define StackDebug

typedef struct {
    sint32 stackPtr;
    uint32 data[Max_Stack_size];
}stack_ds_t ;

typedef enum {
    R_NOK,
    R_OK,
    StackIsFull,
    StackIsEmpty,
    StackIsNotFull,
    StackIsNotEmpty
}Stack_status;

#endif // STACK_DS_H

Stack_status StackPush(stack_ds_t*my_stack,uint32 Value);
Stack_status StackPop(stack_ds_t*my_stack,uint32 *Value);
Stack_status StackTop(stack_ds_t*my_stack,uint32 *Value);
Stack_status StackSize(stack_ds_t*my_stack,uint32 *stack_size);
Stack_status StackDisplay(stack_ds_t*my_stack);
Stack_status StackIniT(stack_ds_t*my_stack);

