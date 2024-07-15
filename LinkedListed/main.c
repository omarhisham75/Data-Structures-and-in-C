#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    unsigned int NodeData ;
    struct Node *NodeLinker;
}node;

unsigned int Get_Lenght(node *List){
    node *TempList = List;
    unsigned int counter=0;
    while (TempList!=NULL){
            counter++;
            TempList = TempList->NodeLinker;
    }
    return counter;
}

void Display_All_Nodes(node *List){
    node *TempList = List;
    printf("Node Values : ");

    if (NULL == TempList){
        printf("List is empty\n");
    }
    else {
        printf("List : ");
        while (NULL!=TempList){
            printf("%i => ",TempList->NodeData);
            TempList = TempList->NodeLinker;
    }
        if(NULL==TempList)
            printf("NULL \n");
    }
}
/*
void Display_All_Nodes(struct Node *List){
    struct Node *TempNode = List;

    printf("Node Values : ");
    if(NULL == TempNode){
        printf("List is empty !! \n");
    }
    else{
        while(TempNode != NULL){
            printf("%i -> ", TempNode->NodeData);
            TempNode = TempNode->NodeLink;
        }
        if(NULL == TempNode){
            printf("NULL \n");
        }
    }
}
*/

void Insert_Node_At_Beginning(node **List){
    node *TempList=NULL;
    TempList = (node *)malloc(sizeof(node));
    if(NULL != TempList){
        printf("Please Enter Node Data : ");
        scanf("%i",&TempList->NodeData);

        if(NULL == *List){
            TempList->NodeLinker = NULL ;
            *List = TempList;
        }
        else {
            TempList->NodeLinker = *List;
            *List = TempList ;
        }
    }
}

void Insert_Node_At_End(node **List){
    node *TempList=NULL;
    node *LastNode=NULL;
    TempList = (node *)malloc(sizeof(node));

    if(NULL != TempList){
        printf("Please Enter Node Data : ");
        scanf("%i",&TempList->NodeData);
        TempList->NodeLinker = NULL;
        if(NULL == *List){
            *List = TempList;
        }
        else {
            LastNode = *List;
            while(NULL != LastNode->NodeLinker){
                LastNode = LastNode->NodeLinker;
            }
            LastNode->NodeLinker = TempList;
        }
    }

}

void Insert_Node_After(node *List){
    node *TempList = NULL;
    node *AfterNode =NULL;
    unsigned int NodePosition = 0 ;
    unsigned int ListLength = 0 ;
    unsigned int NodeCounter = 1 ;

    printf("Please Enter Node Position (First Node -> 1) : ");
    scanf("%i",&NodePosition);
    ListLength = Get_Lenght(List);

    if(NodePosition > ListLength){
        printf("Invalid Node Position, List has (%i) Nodes \n",ListLength);
    }
    else {
        AfterNode = List;
        while (NodeCounter<NodePosition){
            NodeCounter++;
            AfterNode=AfterNode->NodeLinker;
        }
        TempList =(node *)malloc(sizeof(node));
        if (NULL != TempList){
            printf("Please Enter Node Data : ");
            scanf("%i",&TempList->NodeData);
            TempList->NodeLinker = AfterNode->NodeLinker ;
            AfterNode->NodeLinker = TempList;
            }
            else {
                /*Nothing*/
            }
    }
}

void Delete_Node_At_Beginning(node **List){
    node *TempList = *List ;
    unsigned int ListLength = 0;
    ListLength = Get_Lenght(*List);
    if(0 == ListLength){
        printf("List is Empty \n");
    }
    else {
        *List = TempList->NodeLinker;
        TempList->NodeLinker = NULL ;
        free(TempList);
    }
}

void Delete_Node(node *List){
    unsigned int NodeNum = 0, ListLength = 0, NodeCounter = 1;
    node *NodeDel = NULL, *NodeBefore=List ;
    printf("Please Enter Node Position (First Node -> 1) : ");
    scanf("%i",&NodeNum);

    ListLength = Get_Lenght(List);
    if((NodeNum > ListLength) || (0 == ListLength)){
        printf("Please use Delete_Node_At_Beginning \n");
    }
    else{
        while(NodeCounter<(NodeNum-1)){
        NodeCounter++;
        NodeBefore = NodeBefore->NodeLinker;
       }
       NodeDel = NodeBefore->NodeLinker ;
       NodeBefore->NodeLinker = NodeDel->NodeLinker ;
       free(NodeDel);
    }
}


node *ListHead=NULL;








int main()
{
    unsigned int UserChoice = 0;
    unsigned int ListLength = 0;

    printf("-> Hello to Single Linked List \n");
    while(1){
        printf("\n");
        printf("===============================\n");
        printf("-> 1) Insert_Node_At_Beginning \n");
        printf("-> 2) Insert_Node_At_End \n");
        printf("-> 3) Insert_Node_After \n");
        printf("-> 4) Delete_Node_At_Beginning \n");
        printf("-> 5) Delete_Node \n");
        printf("-> 6) Display_All_Nodes \n");
        printf("-> 7) Get_Length \n");
        printf("-> 8) Quit from application \n");
        printf("===============================\n");

        printf("\n");
        printf("UserChoice : ");
        scanf("%i", &UserChoice);

        switch(UserChoice){
            case 1:
                Insert_Node_At_Beginning(&ListHead);
            break;
            case 2:
                Insert_Node_At_End(&ListHead);
            break;
            case 3:
                Insert_Node_After(ListHead);
            break;
            case 4:
                Delete_Node_At_Beginning(&ListHead);
            break;
            case 5:
                Delete_Node(ListHead);
            break;
            case 6:
                Display_All_Nodes(ListHead);
            break;
            case 7:
                ListLength = Get_Lenght(ListHead);
                printf("List Length : << %i >> Nodes\n", ListLength);
            break;
            case 8:
                printf("Quit from application \n");
                exit(1);
            break;
            default:
                printf("User Choice out of range !!\n");
            break;
        }
    }
    return 0;
}























