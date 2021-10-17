#include <stdio.h>
#include <stdlib.h>
#define SIZE 513

char map[SIZE][SIZE];

typedef struct node_s{
    int x,y;
    struct node_s* next;
}node_t;

typedef node_t* nodep_t;

nodep_t createNewNode(int x,int y){
    nodep_t newNode=malloc(sizeof(node_t));
    newNode->x=x;
    newNode->y=y;
    newNode->next=NULL;
    return newNode;
}

void insertFormBack(nodep_t pointer,int x,int y){
    while(pointer->next!=NULL)pointer=pointer->next;
    pointer->next=createNewNode(x,y);
}

void deleteFromFront(nodep_t pointer,int* x,int* y){
    nodep_t freeNode=pointer->next;
    *x=freeNode->x;
    *y=freeNode->y;
    pointer->next=freeNode->next;
    free(freeNode);
}

void push(nodep_t pointer,int x,int y){
    if(map[y+1][x]=='1'){
        map[y+1][x]='0';
        insertFormBack(pointer,x,y+1);
    }
    if(map[y][x+1]=='1'){
        map[y][x+1]='0';
        insertFormBack(pointer,x+1,y);
    }
    if(map[y][x-1]=='1'){
        map[y][x-1]='0';
        insertFormBack(pointer,x-1,y);
    }
    if(map[y-1][x]=='1'){
        map[y-1][x]='0';
        insertFormBack(pointer,x,y-1);
    }
}


void BFS(int x,int y){
    int w=SIZE,n=SIZE,e=0,s=0,area=0;
    nodep_t queue=createNewNode(-1,-1);
    insertFormBack(queue,x,y);
    map[y][x]='0';
    while(queue->next!=NULL){
        deleteFromFront(queue,&x,&y);
        ++area;
        if(x<w)w=x;
        if(x>e)e=x;
        if(y<n)n=y;
        if(y>s)s=y;
        push(queue,x,y);
    }
    printf("%d %d %d %d %d\n",w,n,e,s,area);
    free(queue);
}


int main(){
    int axisx,axisy;
    scanf("%d%d",&axisx,&axisy);
    for(int y=0;y<axisy;++y)for(int x=0;x<axisx;++x)scanf(" %c",&map[y][x]);

    for(int y=0;y<axisy;++y){
        for(int x=0;x<axisx;++x){
            if(map[y][x]=='1'){
                BFS(x,y);
            }
        }
    }

    /*for(int y=0;y<axisy;++y){
        for(int x=0;x<axisx;++x){
            printf("%c ",map[y][x]);
        }
        printf("\n");
    }*/


}
