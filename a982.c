#include <stdio.h>
#include <stdlib.h>
#define SIZE 100

//AC 2ms

typedef struct node_s{
    int x,y;
    struct node_s *next;
}node_t;

typedef node_t* nodep_t;

nodep_t createNewNode(int x,int y){
    nodep_t newNode=malloc(sizeof(node_t));
    newNode->next=NULL;
    newNode->x=x;
    newNode->y=y;
    return newNode;
}

void insertFormBack(nodep_t pointer,int x,int y){
    //printf("push x=%d y=%d\n",x,y);
    nodep_t newNode=createNewNode(x,y);
    while(pointer->next!=NULL){
        pointer=pointer->next;
    }
    pointer->next=newNode;

}

void deleteFromFront(nodep_t pointer,int *x,int *y){
    nodep_t freeNode=pointer->next;
    *x=freeNode->x;
    *y=freeNode->y;
    pointer->next=freeNode->next;
    free(freeNode);
}

int push(int checkerboard[SIZE][SIZE],nodep_t queue,int size,int x,int y){
    if(x==size-2 && y+1==size-2 || x+1==size-2 && y==size-2 || x-1==size-2 && y==size-2 || x==size-2 && y-1==size-2){
        printf("%d\n",checkerboard[x][y]+1);
        return 1;
    }
    if(checkerboard[x+1][y]==0){
        checkerboard[x+1][y]=checkerboard[x][y]+1;
        insertFormBack(queue,x+1,y);
    }
    if(checkerboard[x][y+1]==0){
        checkerboard[x][y+1]=checkerboard[x][y]+1;
        insertFormBack(queue,x,y+1);
    }
    if(checkerboard[x-1][y]==0){
        checkerboard[x-1][y]=checkerboard[x][y]+1;
        insertFormBack(queue,x-1,y);
    }
    if(checkerboard[x][y-1]==0){
        checkerboard[x][y-1]=checkerboard[x][y]+1;
        insertFormBack(queue,x,y-1);
    }
    return 0;
}

void BFS(int checkerboard[SIZE][SIZE],int size){
    nodep_t queue=createNewNode(-1,-1);
    insertFormBack(queue,1,1);
    checkerboard[1][1]=1;
    while(queue->next!=NULL){
        int x,y;
        deleteFromFront(queue,&x,&y);
        //printf("enter x=%d y=%d\n",x,y);
        if(push(checkerboard,queue,size,x,y))return;
    }
    printf("No solution!\n");
}

int main(){//(1,1)->(n-2,n-2)
    int n;
    int checkerboard[SIZE][SIZE];
    scanf("%d",&n);
    for(int i=0;i<n;++i){
        char str[SIZE];
        scanf("%s",&str);
        for(int j=0;j<n;++j){
            checkerboard[i][j]=str[j]-'.';
        }
    }
    BFS(checkerboard,n);
    /*for(int i=0;i<n;++i){
        for(int j=0;j<n;++j)printf("%5d",checkerboard[i][j]);
        printf("\n");
    }*/
}
