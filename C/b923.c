#include<stdio.h>//AC 1ms
#include<stdlib.h>

typedef struct node_s{
    int data;
    struct node_s* next;
}node_t;

typedef node_t* nodep_t;

nodep_t createNewNode(int data){
    nodep_t newNode=malloc(sizeof(node_t));
    newNode->data=data;
    newNode->next=NULL;
    return newNode;
}

void insertFromFront(nodep_t pointer,int data){
    nodep_t newNode=createNewNode(data);
    if(pointer->next==NULL)pointer->next=newNode;
    else{
        newNode->next=pointer->next;
        pointer->next=newNode;
    }
}

int deleteFromFront(nodep_t pointer){
    int data;
    nodep_t freeNode=pointer->next;
    data=freeNode->data;
    pointer->next=freeNode->next;
    free(freeNode);
    return data;
}

int read(nodep_t pointer){
    return pointer->next->data;
}

int main(){
    int n;
    scanf("%d",&n);
    nodep_t pointer=createNewNode(-1);
    while(n--){
        int oper;
        scanf("%d",&oper);
        switch(oper){
        case 1:
            deleteFromFront(pointer);
            break;
        case 2:
            printf("%d\n",read(pointer));
            break;
        case 3:
            scanf("%d",&oper);
            insertFromFront(pointer,oper);
            break;
        }
    }
}
