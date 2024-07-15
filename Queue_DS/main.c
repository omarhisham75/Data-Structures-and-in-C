#include <stdio.h>
#include <stdlib.h>

#include "Queue_DS.h"

QueueStatus ret=Queue_NOK;

Queue *QueuePtr;

void *Item  ;

uint32 var1=11;
uint32 var2=12;
uint32 var3=13;

uint32 QC;



int main()
{
    QueuePtr=QueueCreate(3,&ret);

   ret= Enqueue(QueuePtr,&var1); printf("ret = %i\n",ret);

   Item =QueueFront(QueuePtr,&ret);printf("ret = %i  % Item = 0x%X \n",ret,Item);
   Item =QueueRear(QueuePtr,&ret);printf("ret = %i  % Item = 0x%X \n",ret,Item);

   ret= Enqueue(QueuePtr,&var2); printf("ret = %i\n",ret);
   ret= Enqueue(QueuePtr,&var3); printf("ret = %i\n",ret);
   ret= Enqueue(QueuePtr,&var1); printf("ret = %i\n",ret);

   ret = QueueCount(QueuePtr,&QC); printf("ret = %i & QC = %i\n",ret,QC);

   Item=Dequeue(QueuePtr,&ret);printf("ret = %i  % Item = %i \n",ret,*(uint32*)Item);
   Item=Dequeue(QueuePtr,&ret);printf("ret = %i  % Item = %i \n",ret,*(uint32*)Item);
   Item=Dequeue(QueuePtr,&ret);printf("ret = %i  % Item = %i \n",ret,*(uint32*)Item);
   Item=Dequeue(QueuePtr,&ret);printf("ret = %i  % Item = %i \n",ret,Item);

   ret = QueueCount(QueuePtr,&QC); printf("ret = %i & QC = %i\n",ret,QC);





    return 0;
}
