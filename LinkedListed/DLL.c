#include <stdio.h>
#include <stdlib.h>

/*

void Insert_Node_At_Beginning(struct Node **List, uint32 Data);
void Insert_Node_At_End(struct Node *List, uint32 Data);
void Insert_Node_After(struct Node *List, uint32 Data, uint32 position);
void Insert_Node_Before(struct Node **List, uint32 Data, uint32 position);
void Delete_Node_At_Beginning(struct Node **List);
void Delete_Node_At_End(struct Node *List);
void Delete_Node_At_Intermediate(struct Node *List, uint32 position);
void Display_All_Nodes_Forward(struct Node *List);
void Display_All_Nodes_Reverse(struct Node *List);


*/

#define First_Solution

typedef struct Node {
    unsigned int NodeData ;
    struct Node *LeftLink;
    struct Node *RightLink;
}node;

node *ListHead = NULL ;

void Insert_Node_At_Beginning(node **List,unsigned int Data){
    node *TempNode = NULL ;
    TempNode = (node *)malloc(sizeof(node));
    if(NULL != TempNode){
        TempNode->NodeData = Data ;
        if(NULL == *List){
            TempNode->LeftLink = NULL ;
            TempNode->RightLink = NULL ;
            *List = TempNode ;
        }
        else{
            TempNode->LeftLink = NULL;
            TempNode->RightLink = *List ;
            (*List)->LeftLink = TempNode;
            (*List) = TempNode;
        }
    }
    else {
        printf("Can't allocate the new node \n");
    }
}

void Insert_Node_At_End(node **List,unsigned int Data){
    node *TempNode = NULL ;
    node *LastNode = *List ;
    TempNode = (node *)malloc(sizeof(node));
    if(NULL != TempNode){
        TempNode->NodeData = Data ;
        if(NULL == *List){
            TempNode->LeftLink = NULL ;
            TempNode->RightLink = NULL ;
            *List = TempNode ;
        }
        else{
            while (NULL != LastNode->RightLink){
                LastNode = LastNode->RightLink;
            }
            TempNode->RightLink = NULL ;
            TempNode->LeftLink = LastNode;
            LastNode->RightLink = TempNode ;
        }
    }
    else {
        printf("Can't allocate the new node \n");
    }
}

void Insert_Node_After(node *List , unsigned int Data , unsigned int NodePosition){
    node *TempNode = NULL ;
    node *NodeOne = List ;
    node *NodeTwo = NULL ;
    unsigned int NodeCounter = 1 ;

    while(NodeCounter<NodePosition){
        NodeCounter++;
        NodeOne = NodeOne->RightLink ;
    }

    TempNode = (node *)malloc(sizeof(node));
    if (NULL != TempNode){
        TempNode->NodeData = Data ;
        if(NULL == NodeOne->RightLink){
            TempNode->RightLink = NULL ;
            TempNode->LeftLink = NodeOne ;
            NodeOne->RightLink = TempNode ;
        }
        else {
            NodeTwo = NodeOne->RightLink;
            TempNode->LeftLink = NodeOne ;
            TempNode->RightLink = NodeTwo ;
            NodeOne->RightLink = TempNode ;
            NodeTwo->LeftLink = TempNode ;
        }

    }
    else {
        printf("Can't allocate the new node \n");
    }
}

void Insert_Node_Before(node **List , unsigned int Data , unsigned int NodePosition){
    node *TempNode = NULL ;
    node *NodeOne = NULL ;
    node *NodeTwo = *List ;

    while(1 != NodePosition){
        NodePosition--;
        NodeTwo = NodeTwo->RightLink;
    }
    TempNode = (node *)malloc(sizeof(node));
    if(NULL != TempNode){
        TempNode->NodeData = Data ;
        if(NULL == NodeTwo->LeftLink){
            TempNode->RightLink = NodeTwo ;
            TempNode->LeftLink = NULL ;
            NodeTwo->LeftLink = TempNode ;
            *List = TempNode ;
        }
        else {
            NodeOne = NodeTwo->LeftLink ;
            TempNode->LeftLink = NodeOne ;
            TempNode->RightLink = NodeTwo ;
            NodeOne->RightLink = TempNode ;
            NodeTwo->LeftLink = TempNode ;
        }
    }
    else {
        printf("Can't allocate the new node \n");
    }

}

void Display_All_Nodes_Forward(node *List){
    node *TempNode = List ;
    printf("Nodes in Forward Direction : ");
    if(NULL == TempNode){
        printf("List is Empty \n");
    }
    else{
        while(NULL != TempNode){
            printf("%i => ",TempNode->NodeData);
            TempNode = TempNode->RightLink ;
        }
    printf("NULL \n");
    }
}

void Display_All_Nodes_Reverse(node *List){
    node *TempNode = List ;
    printf("Nodes in Reverse Direction : ");
    if(NULL == TempNode){
        printf("List is Empty \n");
    }
    else{
        while(NULL != TempNode->RightLink){
            TempNode = TempNode->RightLink ;
        }
        while(NULL != TempNode){
            printf("%i => ",TempNode->NodeData);
            TempNode = TempNode->LeftLink;
        }
    printf("NULL \n");
    }
}

void Delete_Node_At_Beginning(node **List){
    #ifdef First_Solution
    node *TempNode = *List ;
    *List = TempNode->RightLink ;
    TempNode = NULL ;
    free(TempNode);
    #else
    *List = (*List)->RightLink;
    free((*List)->LeftLink);
    (*List)->LeftLink = NULL ;
    #endif // First_Solution
}

void Delete_Node_At_End(node *List){
    node *LastNode = List ;
    while(NULL != LastNode->RightLink){
        LastNode = LastNode->RightLink;
    }
    LastNode->LeftLink->RightLink = NULL ;
    LastNode = NULL;
    free(LastNode);
}

void Delete_Node_At_Intermediate(node *List , unsigned int NodePosition){
    node *NodeDEl = List ;
    if(1 == NodePosition){
        printf("Please use Delete_Node_At_Beginning\n");
    }
    else{
        while(1 < NodePosition){
            NodePosition--;
            NodeDEl = NodeDEl->RightLink;
        }
        if(NULL == NodeDEl->RightLink){
            printf("Please use Delete_Node_At_End\n");
        }
        else{
            NodeDEl->LeftLink->RightLink = NodeDEl->RightLink;
            NodeDEl->RightLink->LeftLink = NodeDEl->LeftLink;
            NodeDEl = NULL ;
            free(NodeDEl);
        }

    }
}
















int main(){




    Insert_Node_At_End(&ListHead,11);
    Insert_Node_At_End(&ListHead,22);
    Display_All_Nodes_Forward(ListHead);

    Insert_Node_After(ListHead,33,2);
    Insert_Node_After(ListHead,44,3);
    Display_All_Nodes_Forward(ListHead);
    Display_All_Nodes_Reverse(ListHead);

    Delete_Node_At_Intermediate(ListHead,3);
    Delete_Node_At_Intermediate(ListHead,2);
    Display_All_Nodes_Forward(ListHead);









    return 0;
}




