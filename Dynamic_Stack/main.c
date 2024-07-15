#include <stdio.h>
#include <stdlib.h>

#include "Dynamic_SD.h"
D_S *Stack1 = NULL;
Stack_status retVal=0;
uint32 Var1 = 11;
float32 Var2 = 2.14;
char Var3 = 'a';
int main()
{
    Stack1 = StackCreate(3,&retVal);
    if(Stack1){
        printf("Stack 1 created \n");
        printf("%i\n",retVal);
    }
    retVal = StackPuch(&Stack1,&Var1); printf("retVal = %i\n",retVal);
    retVal = StackPuch(&Stack1,&Var2); printf("retVal = %i\n",retVal);
    retVal = StackPuch(&Stack1,&Var3); printf("retVal = %i\n",retVal);
    retVal = StackPuch(&Stack1,&Var3); printf("retVal = %i\n",retVal);
    retVal = StackPuch(&Stack1,&Var1); printf("retVal = %i\n",retVal);
    retVal = StackPuch(&Stack1,&Var1); printf("retVal = %i\n",retVal);
    retVal = StackPuch(&Stack1,&Var1); printf("retVal = %i\n",retVal);
    retVal = StackPuch(&Stack1,&Var1); printf("retVal = %i\n",retVal);
    return 0;
}
