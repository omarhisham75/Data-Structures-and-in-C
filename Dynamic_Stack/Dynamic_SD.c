#include <stdio.h>
#include "Dynamic_SD.h"

static Stack_status StackFull(D_S *StackObj){
    if(StackObj->ElemntCount == StackObj->StackMaxSize)
        return StackIsFull;
    else
        return StackIsNotFull;
}

static Stack_status StackEmpty(D_S *StackObj){
    if(StackObj->ElemntCount == 0)
        return StackIsEmpty;
    else
        return StackIsNotEmpty;
}

D_S *StackCreate(uint32 MaxSize , Stack_status *ret){
    D_S *my_stack_ptr = NULL;
    if (NULL == ret){
        *ret = Stack_NULL_Pointer;
        my_stack_ptr = NULL;
    }
    else {
        my_stack_ptr = (D_S *)malloc(sizeof(D_S));
        if (!my_stack_ptr){
            *ret = Stack_NOK;
            my_stack_ptr=NULL;
        }
        else{
            my_stack_ptr->StackTop = -1;
            my_stack_ptr->ElemntCount = 0;
            my_stack_ptr->StackMaxSize = MaxSize ;
            my_stack_ptr->StackArray = (void **)calloc(sizeof(my_stack_ptr->StackMaxSize),sizeof(void *));
            if(!my_stack_ptr->StackArray){
                free(my_stack_ptr);
                my_stack_ptr=NULL;
                *ret = Stack_NOK;
            }
            else {
                *ret = Stack_OK;
            }
        }
        }
    return my_stack_ptr;
}

D_S *StackDestroy(D_S *stackObj , Stack_status *ret){
    if ((NULL == ret) || (NULL == stackObj)){
        *ret = Stack_NULL_Pointer;
    }
    else {
        free(stackObj->StackArray);
        free(stackObj);
        *ret = Stack_OK;
    }
    return NULL;
}

Stack_status StackPuch(D_S *stackObj , void *ValuePtr){
    Stack_status ret = Stack_NOK;
    if((NULL == ValuePtr) || (NULL == stackObj))
        ret = Stack_NULL_Pointer;
    else{
        if (StackIsFull == StackFull(stackObj))
            ret = StackIsFull;
        else{
            (stackObj->ElemntCount)++;
            (stackObj->StackTop)++;
            (stackObj->StackArray[stackObj->StackTop])=ValuePtr;
            ret = Stack_OK;
        }
    }
    return ret;
}

void *StackPop(D_S *stackObj , Stack_status *ret){
    void *DataPtr = NULL;
    if((NULL == ret) || (NULL == stackObj)){
        ret = Stack_NULL_Pointer;
        DataPtr = NULL;
    }
    else {
        if(StackIsEmpty == StackEmpty(stackObj)){
            *ret = StackIsEmpty;
            DataPtr = NULL;
        }
        else {
            DataPtr=stackObj->StackArray[stackObj->StackTop];
            (stackObj->ElemntCount)--;
            (stackObj->StackTop)--;
            *ret=Stack_OK;
        }
    }
    return DataPtr;
}


void *StackTop(D_S *stackObj , Stack_status *ret){
    void *DataPtr = NULL;
    if((NULL == ret) || (NULL == stackObj)){
        ret = Stack_NULL_Pointer;
        DataPtr = NULL;
    }
    else {
        if(StackIsEmpty == StackEmpty(stackObj)){
            *ret = StackIsEmpty;
            DataPtr = NULL;
        }
        else {
            DataPtr=stackObj->StackArray[stackObj->StackTop];
            *ret=Stack_OK;
        }
    }
    return DataPtr;
}


Stack_status StackCount(D_S *stackObj,uint32 *StackCounter){
   Stack_status ret = Stack_NOK;
    if ((NULL == stackObj)||(NULL == StackCounter)){
        ret = Stack_NULL_Pointer;
    }
    else{
        *StackCounter=stackObj->ElemntCount;
        ret=Stack_OK;
    }
    return ret;
}



