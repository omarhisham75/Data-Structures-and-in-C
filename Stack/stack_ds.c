#include <stdio.h>
#include <stdlib.h>

#include "stack_ds.h"

static Stack_status StackFull(stack_ds_t *my_stack){
    if(my_stack->stackPtr==(Max_Stack_size-1))
        return StackIsFull;
    else {
        return StackIsNotFull;
    }

}
static Stack_status StackEmpty(stack_ds_t*my_stack){
    if(my_stack->stackPtr==-1)
        return StackIsEmpty;
    else {
        return StackIsNotEmpty;
    }

}

Stack_status StackPush(stack_ds_t*my_stack,uint32 Value){
    Stack_status ret = R_NOK;
    if ((NULL == my_stack) || (StackIsFull == StackFull(my_stack))){
        ret = R_NOK;
        #ifdef StackDebug
        printf("Stack is Full Can't push (%i) \n",Value);
        #endif // StackDebug
    }
    else{
        (my_stack->stackPtr)++;
        (my_stack->data[my_stack->stackPtr]) = Value;
        #ifdef StackDebug
        printf("Value (%i) Pushed to the stack \n",Value);
        #endif // StackDebug
        ret = R_OK;

    }
    return ret;
}
Stack_status StackPop(stack_ds_t*my_stack,uint32 *Value){
    Stack_status ret = R_NOK;
    if ((NULL == my_stack) || (StackIsEmpty == StackEmpty(my_stack))){
        ret = R_NOK;
        #ifdef StackDebug
        printf("Stack is Empty Can't Pop (%i) \n",*Value);
        #endif // StackDebug
    }
    else {
        *Value = (my_stack->data[my_stack->stackPtr]);
        (my_stack->stackPtr)--;
        #ifdef StackDebug
        printf("Value (%i) Popped to the stack \n",*Value);
        #endif // StackDebug
        ret = R_OK;
    }
    return ret;
}
Stack_status StackTop(stack_ds_t*my_stack,uint32 *Value){
     Stack_status ret = R_NOK;
    if ((NULL == my_stack) || (StackIsEmpty == StackEmpty(my_stack))){
        ret = R_NOK;
        #ifdef StackDebug
        printf("Stack is Empty Can't Top (%i) \n",*Value);
        #endif // StackDebug
    }
    else {
        *Value = (my_stack->data[my_stack->stackPtr]);
        #ifdef StackDebug
        printf("The Top Value is (%i) \n",*Value);
        #endif // StackDebug
        ret = R_OK;
    }
    return ret;
}
Stack_status StackSize(stack_ds_t*my_stack,uint32 *stack_size){
    Stack_status ret = R_NOK;
    if ((NULL == my_stack) || (NULL == stack_size))
        ret = R_NOK;
    else {
        *stack_size = (my_stack->stackPtr)+1;
        ret = R_OK ;
    }
    return ret;
}
Stack_status StackDisplay(stack_ds_t*my_stack){
    Stack_status ret = R_NOK;
    if (NULL == my_stack || (StackIsEmpty == StackEmpty(my_stack))){
         ret = R_NOK;
        #ifdef StackDebug
        printf("Stack is Empty\n");
        #endif // StackDebug
    }

    else {
        printf("Stack Data : ");
        for(uint32 i = 0 ; i <= (my_stack->stackPtr) ; i++){
            printf("%i  ",my_stack->data[i]);
        }
        printf("\n");
        ret = R_OK;
    }
    return ret;
}
Stack_status StackIniT(stack_ds_t*my_stack){
    Stack_status ret = R_NOK;
    if (NULL == my_stack)
        ret = R_NOK;
    else {
        my_stack->stackPtr = -1;
        #ifdef StackDebug
        printf("Stack is Initialized\n");
        #endif // StackDebug
        ret = R_OK;
    }
    return ret;
}

