#include <stdio.h>
#include <stdlib.h>
#include "stack_ds.h"

stack_ds_t Stack1;

int main()
{
    uint32 Value = 0 ;

    Stack_status ret = R_NOK;
    ret = StackIniT(&Stack1);
    printf("ret = %i\n",ret);
    ret = StackPush(&Stack1, 11 );
    printf("ret = %i\n",ret);
    ret = StackPush(&Stack1, 22 );
    printf("ret = %i\n",ret);
    ret = StackPush(&Stack1, 33 );
    printf("ret = %i\n",ret);
    ret = StackPush(&Stack1, 44 );
    printf("ret = %i\n",ret);

    ret = StackTop(&Stack1,&Value);
    printf("ret = %i\n",ret);
    printf("Value = %i\n",Value);

    ret = StackDisplay(&Stack1);
    printf("ret = %i\n",ret);

    ret = StackPop(&Stack1,&Value);
    printf("ret = %i\n",ret);
    printf("Value = %i\n",Value);
     ret = StackPop(&Stack1,&Value);
    printf("ret = %i\n",ret);
    printf("Value = %i\n",Value);
     ret = StackPop(&Stack1,&Value);
    printf("ret = %i\n",ret);
    printf("Value = %i\n",Value);
     ret = StackPop(&Stack1,&Value);
    printf("ret = %i\n",ret);
    printf("Value = %i\n",Value);

    ret = StackTop(&Stack1,&Value);
    printf("ret = %i\n",ret);
    printf("Value = %i\n",Value);

     ret = StackDisplay(&Stack1);
    printf("ret = %i\n",ret);




    return 0;
}
