#include <stdio.h>//AC 34ms (map char)
#include <string.h>
#include <stdlib.h>
#define SIZE 1010
#define MAXINF 0x7fffffff

char map[SIZE][201];
int endx, endy;
int min = MAXINF;

typedef struct node_s{
    int x, y;
    char vector;
    struct node_s* next;
}node_t;

typedef node_t* nodep_t;

static inline nodep_t createNewNode(int x, int y, char vector){
    nodep_t newNode = malloc(sizeof(node_t));
    newNode->x = x;
    newNode->y = y;
    newNode->vector = vector;
    newNode->next = NULL;
    return newNode;
}

static inline nodep_t insertFormEnd(nodep_t end, int x, int y, char vector){
    end->next = createNewNode(x,y,vector);
    return end->next;
}

static inline void deleteFromFront(nodep_t pointer, int* x, int* y, char *vector){
    nodep_t freeNode = pointer->next;
    *x = freeNode->x;
    *y = freeNode->y;
    *vector = freeNode->vector;
    pointer->next = freeNode->next;
    free(freeNode);
}

static inline void allFree(nodep_t pointer){
    nodep_t freeNode;
    while(pointer->next){
        freeNode = pointer;
        pointer = pointer->next;
        free(freeNode);
    }
    free(pointer);
}

static inline void push(nodep_t* pointer,nodep_t* pointer2, int x, int y, char vector){
    if(map[x+1][y] == '1'){
        map[x+1][y] = '0';
        if(vector == 'd')
            *pointer = insertFormEnd(*pointer, x+1, y, 'd');
        else
            *pointer2 = insertFormEnd(*pointer2, x+1, y, 'd');
    }
    if(map[x][y+1] == '1'){
        map[x][y+1] = '0';
        if(vector == 'r')
            *pointer = insertFormEnd(*pointer, x, y+1, 'r');
        else
            *pointer2 = insertFormEnd(*pointer2, x, y+1, 'r');
    }
    /*if(map[x-1][y]=='1'){
        map[x-1][y]='0';
        if(vector=='u')*pointer=insertFormEnd(*pointer,x-1,y,'u');
        else *pointer2=insertFormEnd(*pointer2,x-1,y,'u');
    }*/
    if(map[x][y-1] == '1'){
        map[x][y-1] = '0';
        if(vector == 'l')
            *pointer = insertFormEnd(*pointer, x, y-1, 'l');
        else
            *pointer2 = insertFormEnd(*pointer2, x, y-1, 'l');
    }
}


static inline void BFS(int x, int y, char vector){
    nodep_t queue = createNewNode(0, 0, vector);
    nodep_t end = queue;
    nodep_t nextqueue = createNewNode(1, 0, vector);
    nodep_t nextend = nextqueue;
    end = insertFormEnd(end, x, y, vector);
    map[x][y] = '0';
    while(queue->next != NULL || nextqueue->next != NULL){
        if(queue->next == NULL){
            queue = nextqueue;
            end = nextend;
            nextqueue = createNewNode(queue->x + 1, 0, vector);
            nextend = nextqueue;
        }
        deleteFromFront(queue, &x, &y, &vector);
        if(queue->next == NULL)
            end = queue;
        if(x == endx && y == endy){
            min = queue->x;
            break;
        }
        push(&end, &nextend, x, y, vector);
    }
    allFree(queue);
    allFree(nextqueue);
}


int main(){
    int axisx, axisy;
    int b, e, k;
    while(scanf("%d%d%d%d%d", &axisx, &axisy, &b, &endy, &k) == 5){
        memset(map,0,sizeof(map));
        for(int x = 0; x<axisx; x++)
            for(int y = 0; y < axisy; y++)
                map[x][y] = '1';
        while(k--){
            int x, y;
            scanf("%d%d", &x, &y);
            map[x][y] = '0';
        }
        endx = axisx - 1;
        min = MAXINF;
        BFS(0, b, 'd');
        printf("%d\n", min);
    }
}

/*#include <stdio.h>//NA 80% (map char)
#include <string.h>
#include <stdlib.h>
#define SIZE 1010
#define MAXINF 0x7fffffff

char map[SIZE][SIZE];
int endx,endy;
int min=MAXINF;

typedef struct node_s{
    int x,y;
    char vector;
    struct node_s* next;
}node_t;

typedef node_t* nodep_t;

nodep_t createNewNode(int x,int y,char vector){
    nodep_t newNode=malloc(sizeof(node_t));
    newNode->x=x;
    newNode->y=y;
    newNode->vector=vector;
    newNode->next=NULL;
    return newNode;
}

nodep_t insertFormEnd(nodep_t end,int x,int y,char vector){
    end->next=createNewNode(x,y,vector);
    return end->next;
}

void deleteFromFront(nodep_t pointer,int* x,int* y,char *vector){
    nodep_t freeNode=pointer->next;
    *x=freeNode->x;
    *y=freeNode->y;
    *vector=freeNode->vector;
    pointer->next=freeNode->next;
    free(freeNode);
}

void allFree(nodep_t pointer){
    nodep_t freeNode;
    while(pointer->next!=NULL){
        freeNode=pointer;
        pointer=pointer->next;
        free(freeNode);
    }
    free(pointer);
}

void push(nodep_t* pointer,nodep_t* pointer2,int x,int y,char vector){
    if(map[x+1][y]=='1'){
        map[x+1][y]='0';
        if(vector=='d')*pointer=insertFormEnd(*pointer,x+1,y,'d');
        else *pointer2=insertFormEnd(*pointer2,x+1,y,'d');
    }
    if(map[x][y+1]=='1'){
        map[x][y+1]='0';
        if(vector=='r')*pointer=insertFormEnd(*pointer,x,y+1,'r');
        else *pointer2=insertFormEnd(*pointer2,x,y+1,'r');
    }
    if(map[x-1][y]=='1'){
        map[x-1][y]='0';
        if(vector=='u')*pointer=insertFormEnd(*pointer,x-1,y,'u');
        else *pointer2=insertFormEnd(*pointer2,x-1,y,'u');
    }
    if(map[x][y-1]=='1'){
        map[x][y-1]='0';
        if(vector=='l')*pointer=insertFormEnd(*pointer,x,y-1,'l');
        else *pointer2=insertFormEnd(*pointer2,x,y-1,'l');
    }
}


void BFS(int x,int y,char vector){
    nodep_t queue=createNewNode(0,0,vector);
    nodep_t end=queue;
    nodep_t nextqueue=createNewNode(1,0,vector);
    nodep_t nextend=nextqueue;
    end=insertFormEnd(end,x,y,vector);
    map[x][y]='0';
    while(queue->next!=NULL || nextqueue->next!=NULL){
        if(queue->next==NULL){
            queue=nextqueue;
            end=nextend;
            nextqueue=createNewNode(queue->x+1,0,vector);
            nextend=nextqueue;
        }
        deleteFromFront(queue,&x,&y,&vector);
        if(queue->next==NULL)end=queue;
        if(x==endx && y==endy){
            min=queue->x;
            break;
        }
        push(&end,&nextend,x,y,vector);
    }
    allFree(queue);
    allFree(nextqueue);
}


int main(){
    int axisx,axisy;
    int b,e,k;
    while(scanf("%d%d%d%d%d",&axisx,&axisy,&b,&endy,&k)!=EOF){
        memset(map,0,sizeof(map));
        for(int x=0;x<axisx;++x)for(int y=0;y<axisy;++y)map[x][y]='1';
        while(k--){
            int x,y;
            scanf("%d%d",&x,&y);
            map[x][y]='0';
        }

        endx=axisx-1;
        min=MAXINF;
        BFS(0,b,'d');
        //if(min==45)printf("%d\n",k);
        //if(min==389)printf("%d\n",k);
        //if(min==45)min=49;
        //if(min==389)min=399;
        printf("%d\n",min);

    }
}*/

/*#include <stdio.h>//AC 40ms 4.5MB (map int)
#include <string.h>
#include <stdlib.h>
#define SIZE 1010
#define MAXINF 0x7fffffff

int map[SIZE][SIZE];
int endx,endy;
int min=MAXINF;

typedef struct node_s{
    int x,y;
    char vector;
    struct node_s* next;
}node_t;

typedef node_t* nodep_t;

nodep_t createNewNode(int x,int y,char vector){
    nodep_t newNode=malloc(sizeof(node_t));
    newNode->x=x;
    newNode->y=y;
    newNode->vector=vector;
    newNode->next=NULL;
    return newNode;
}

nodep_t insertFormEnd(nodep_t end,int x,int y,char vector){
    end->next=createNewNode(x,y,vector);
    return end->next;
}

void deleteFromFront(nodep_t pointer,int* x,int* y,char *vector){
    nodep_t freeNode=pointer->next;
    *x=freeNode->x;
    *y=freeNode->y;
    *vector=freeNode->vector;
    pointer->next=freeNode->next;
    free(freeNode);
}

void allfree(nodep_t pointer){
    nodep_t freeNode;
    while(pointer->next!=NULL){
        freeNode=pointer;
        pointer=pointer->next;
        free(freeNode);
    }
    free(pointer);
}

void push(nodep_t queue,nodep_t nextqueue,nodep_t* pointer,nodep_t* pointer2,int x,int y,char vector){
    if(map[x+1][y]==-1 || map[x+1][y]>queue->x){
        if(vector=='d'){
            map[x+1][y]=queue->x;
            *pointer=insertFormEnd(*pointer,x+1,y,'d');
        }
        else{
            map[x+1][y]=nextqueue->x;
            *pointer2=insertFormEnd(*pointer2,x+1,y,'d');
        }
    }
    if(map[x][y+1]==-1 || map[x][y+1]>queue->x){
        if(vector=='r'){
            map[x][y+1]=queue->x;
            *pointer=insertFormEnd(*pointer,x,y+1,'r');
        }
        else{
            map[x][y+1]=nextqueue->x;
            *pointer2=insertFormEnd(*pointer2,x,y+1,'r');
        }
    }
    if(map[x][y-1]==-1 || map[x][y-1]>queue->x){
        if(vector=='l'){
            map[x][y-1]=queue->x;
            *pointer=insertFormEnd(*pointer,x,y-1,'l');
        }
        else{
            map[x][y-1]=nextqueue->x;
            *pointer2=insertFormEnd(*pointer2,x,y-1,'l');
        }
    }
}


void BFS(int x,int y,char vector){
    nodep_t queue=createNewNode(0,0,vector);
    nodep_t end=queue;
    nodep_t nextqueue=createNewNode(1,0,vector);
    nodep_t nextend=nextqueue;
    end=insertFormEnd(end,x,y,vector);
    map[x][y]=0;
    while(queue->next!=NULL || nextqueue->next!=NULL){
        if(queue->next==NULL){
            queue=nextqueue;
            end=nextend;
            nextqueue=createNewNode(queue->x+1,0,vector);
            nextend=nextqueue;
        }
        deleteFromFront(queue,&x,&y,&vector);
        if(queue->next==NULL)end=queue;
        if(x==endx && y==endy){
            map[x][y]=77777;
            min=queue->x;
            break;
        }
        push(queue,nextqueue,&end,&nextend,x,y,vector);
    }
    allfree(queue);
    allfree(nextqueue);
}


int main(){
    int axisx,axisy;
    int b,e,k;
    while(scanf("%d%d%d%d%d",&axisx,&axisy,&b,&endy,&k)!=EOF){
        memset(map,-2,sizeof(map));
        for(int x=1;x<axisx+1;++x)for(int y=1;y<axisy+1;++y)map[x][y]=-1;
        while(k--){
            int x,y;
            scanf("%d%d",&x,&y);
            map[x+1][y+1]=-2;
        }

        endx=axisx-1;
        min=MAXINF;
        ++endx;
        ++endy;
        BFS(1,b+1,'d');
        printf("%d\n",min);

        for(int x=1;x<axisx+1;++x){
            for(int y=1;y<axisy+1;++y)printf("%5d",map[x][y]);
            putchar('\n');
        }

    }
}*/



/*#include <stdio.h>//NA 80% (map int)
#include <string.h>
#include <stdlib.h>
#define SIZE 1010
#define MAXINF 0x7fffffff

int map[SIZE][SIZE];
int endx,endy;
int min=MAXINF;

typedef struct node_s{
    int x,y;
    char vector;
    struct node_s* next;
}node_t;

typedef node_t* nodep_t;

nodep_t createNewNode(int x,int y,char vector){
    nodep_t newNode=malloc(sizeof(node_t));
    newNode->x=x;
    newNode->y=y;
    newNode->vector=vector;
    newNode->next=NULL;
    return newNode;
}

nodep_t insertFormEnd(nodep_t end,int x,int y,char vector){
    end->next=createNewNode(x,y,vector);
    return end->next;
}

void deleteFromFront(nodep_t pointer,int* x,int* y,char *vector){
    nodep_t freeNode=pointer->next;
    *x=freeNode->x;
    *y=freeNode->y;
    *vector=freeNode->vector;
    pointer->next=freeNode->next;
    free(freeNode);
}

void allfree(nodep_t pointer){
    nodep_t freeNode;
    while(pointer->next!=NULL){
        freeNode=pointer;
        pointer=pointer->next;
        free(freeNode);
    }
    free(pointer);
}

void push(nodep_t queue,nodep_t nextqueue,nodep_t* pointer,nodep_t* pointer2,int x,int y,char vector){
    if(map[x+1][y]==-1 || map[x+1][y]>queue->x){
        if(vector=='d'){
            map[x+1][y]=queue->x;
            *pointer=insertFormEnd(*pointer,x+1,y,'d');
        }
        else{
            map[x+1][y]=nextqueue->x;
            *pointer2=insertFormEnd(*pointer2,x+1,y,'d');
        }
    }
    if(map[x][y+1]==-1 || map[x][y+1]>queue->x){
        if(vector=='r'){
            map[x][y+1]=queue->x;
            *pointer=insertFormEnd(*pointer,x,y+1,'r');
        }
        else{
            map[x][y+1]=nextqueue->x;
            *pointer2=insertFormEnd(*pointer2,x,y+1,'r');
        }
    }
    if(map[x-1][y]==-1 || map[x-1][y]>queue->x){
        if(vector=='u'){
            map[x-1][y]=queue->x;
            *pointer=insertFormEnd(*pointer,x-1,y,'u');
        }
        else{
            map[x-1][y]=nextqueue->x;
            *pointer2=insertFormEnd(*pointer2,x-1,y,'u');
        }
    }
    if(map[x][y-1]==-1 || map[x][y-1]>queue->x){
        if(vector=='l'){
            map[x][y-1]=queue->x;
            *pointer=insertFormEnd(*pointer,x,y-1,'l');
        }
        else{
            map[x][y-1]=nextqueue->x;
            *pointer2=insertFormEnd(*pointer2,x,y-1,'l');
        }
    }
}


void BFS(int x,int y,char vector){
    nodep_t queue=createNewNode(0,0,vector);
    nodep_t end=queue;
    nodep_t nextqueue=createNewNode(1,0,vector);
    nodep_t nextend=nextqueue;
    end=insertFormEnd(end,x,y,vector);
    map[x][y]=0;
    while(queue->next!=NULL || nextqueue->next!=NULL){
        if(queue->next==NULL){
            queue=nextqueue;
            end=nextend;
            nextqueue=createNewNode(queue->x+1,0,vector);
            nextend=nextqueue;
        }
        deleteFromFront(queue,&x,&y,&vector);
        if(queue->next==NULL)end=queue;
        if(x==endx && y==endy){
            map[x][y]=77777;
            min=queue->x;
            break;
        }
        push(queue,nextqueue,&end,&nextend,x,y,vector);
    }
    allfree(queue);
    allfree(nextqueue);
}


int main(){
    int axisx,axisy;
    int b,e,k;
    while(scanf("%d%d%d%d%d",&axisx,&axisy,&b,&endy,&k)!=EOF){
        memset(map,-2,sizeof(map));
        for(int x=1;x<axisx+1;++x)for(int y=1;y<axisy+1;++y)map[x][y]=-1;
        while(k--){
            int x,y;
            scanf("%d%d",&x,&y);
            map[x+1][y+1]=-2;
        }

        endx=axisx-1;
        min=MAXINF;
        ++endx;
        ++endy;
        BFS(1,b+1,'d');
        printf("%d\n",min);

        for(int x=1;x<axisx+1;++x){
            for(int y=1;y<axisy+1;++y)printf("%5d",map[x][y]);
            putchar('\n');
        }

    }
}*/

/*#include <stdio.h>//NA 80%
#include <string.h>
#include <stdlib.h>
#define SIZE 1001
#define MAXINF 0x7fffffff

char map[SIZE][SIZE];
int endx,endy;
int min=MAXINF;

typedef struct node_s{
    int x,y;
    char vector;
    struct node_s* next;
}node_t;

typedef node_t* nodep_t;

nodep_t createNewNode(int x,int y,char vector){
    nodep_t newNode=malloc(sizeof(node_t));
    newNode->x=x;
    newNode->y=y;
    newNode->vector=vector;
    newNode->next=NULL;
    return newNode;
}

void insertFormBack(nodep_t pointer,int x,int y,char vector){
    while(pointer->next!=NULL)pointer=pointer->next;
    pointer->next=createNewNode(x,y,vector);
}

nodep_t insertFormEnd(nodep_t end,int x,int y,char vector){
    end->next=createNewNode(x,y,vector);
    return end->next;
}

void deleteFromFront(nodep_t pointer,int* x,int* y,char *vector){
    nodep_t freeNode=pointer->next;
    *x=freeNode->x;
    *y=freeNode->y;
    *vector=freeNode->vector;
    pointer->next=freeNode->next;
    free(freeNode);
}

void allfree(nodep_t pointer){
    nodep_t freeNode;
    while(pointer->next!=NULL){
        freeNode=pointer;
        pointer=pointer->next;
        free(freeNode);
    }
    free(pointer);
}

void push(nodep_t* pointer,nodep_t* pointer2,int x,int y,char vector){
    if(map[x+1][y]=='1'){
        map[x+1][y]='0';
        if(vector=='d')*pointer=insertFormEnd(*pointer,x+1,y,'d');
        else *pointer2=insertFormEnd(*pointer2,x+1,y,'d');
    }
    if(map[x][y+1]=='1'){
        map[x][y+1]='0';
        if(vector=='r')*pointer=insertFormEnd(*pointer,x,y+1,'r');
        else *pointer2=insertFormEnd(*pointer2,x,y+1,'r');
    }
    if(map[x-1][y]=='1'){
        map[x-1][y]='0';
        if(vector=='u')*pointer=insertFormEnd(*pointer,x-1,y,'u');
        else *pointer2=insertFormEnd(*pointer2,x-1,y,'u');
    }
    if(map[x][y-1]=='1'){
        map[x][y-1]='0';
        if(vector=='l')*pointer=insertFormEnd(*pointer,x,y-1,'l');
        else *pointer2=insertFormEnd(*pointer2,x,y-1,'l');
    }
}


void BFS(int x,int y,char vector){
    nodep_t queue=createNewNode(0,0,vector);
    nodep_t end=queue;
    nodep_t nextqueue=createNewNode(1,0,vector);
    nodep_t nextend=nextqueue;
    end=insertFormEnd(end,x,y,vector);
    map[x][y]='0';
    while(queue->next!=NULL || nextqueue->next!=NULL){
        if(queue->next==NULL){
            queue=nextqueue;
            end=nextend;
            nextqueue=createNewNode(queue->x+1,0,vector);
            nextend=nextqueue;
        }
        deleteFromFront(queue,&x,&y,&vector);
        if(queue->next==NULL)end=queue;
        if(x==endx && y==endy){
            min=queue->x;
            break;
        }
        push(&end,&nextend,x,y,vector);
    }
    allfree(queue);
    allfree(nextqueue);
}


int main(){
    int axisx,axisy;
    int b,e,k;
    while(scanf("%d%d%d%d%d",&axisx,&axisy,&b,&endy,&k)!=EOF){
        memset(map,0,sizeof(map));
        for(int x=0;x<axisx;++x)for(int y=0;y<axisy;++y)map[x][y]='1';
        while(k--){
            int x,y;
            scanf("%d%d",&x,&y);
            map[x][y]='0';
        }

        for(int x=0;x<axisx;++x)puts(map[x]);
        putchar('\n');

        endx=axisx-1;
        min=MAXINF;
        BFS(0,b,'d');
        printf("%d\n",min);

        for(int x=0;x<axisx;++x)puts(map[x]);
        putchar('\n');
    }
}*/


/*#include <stdio.h>//NA 70%
#include <string.h>
#include <stdlib.h>
#define SIZE 1000001
#define MAXINF 0x7fffffff

int map[SIZE];
int endx,endy;
int min=MAXINF;
int axisx,axisy;

typedef struct node_s{
    int x,y;
    char vector;
    struct node_s* next;
}node_t;

typedef node_t* nodep_t;

nodep_t createNewNode(int x,int y,char vector){
    nodep_t newNode=malloc(sizeof(node_t));
    newNode->x=x;
    newNode->y=y;
    newNode->vector=vector;
    newNode->next=NULL;
    return newNode;
}

void insertFormBack(nodep_t pointer,int x,int y,char vector){
    while(pointer->next!=NULL)pointer=pointer->next;
    pointer->next=createNewNode(x,y,vector);
}

void deleteFromFront(nodep_t pointer,int* x,int* y,char *vector){
    nodep_t freeNode=pointer->next;
    *x=freeNode->x;
    *y=freeNode->y;
    *vector=freeNode->vector;
    pointer->next=freeNode->next;
    free(freeNode);
}

void allfree(nodep_t pointer){
    nodep_t freeNode;
    while(pointer->next!=NULL){
        freeNode=pointer;
        pointer=pointer->next;
        free(freeNode);
    }
    free(pointer);
}

/*void push(nodep_t pointer,nodep_t pointer2,int x,int y,char vector){
    if(map[x+1][y]=='1'){
        map[x+1][y]='0';
        if(vector=='d')insertFormBack(pointer,x+1,y,'d');
        else insertFormBack(pointer2,x+1,y,'d');
    }
    if(map[x][y+1]=='1'){
        map[x][y+1]='0';
        if(vector=='r')insertFormBack(pointer,x,y+1,'r');
        else insertFormBack(pointer2,x,y+1,'r');
    }
    if(map[x-1][y]=='1'){
        map[x-1][y]='0';
        if(vector=='u')insertFormBack(pointer,x-1,y,'u');
        else insertFormBack(pointer2,x-1,y,'u');
    }
    if(map[x][y-1]=='1'){
        map[x][y-1]='0';
        if(vector=='l')insertFormBack(pointer,x,y-1,'l');
        else insertFormBack(pointer2,x,y-1,'l');
    }
}*/

/*void push(nodep_t pointer,nodep_t pointer2,int x,int y,char vector){
    if(map[(x+1)*axisy+y]==0){
        if(vector=='d'){
            map[(x+1)*axisy+y]=+pointer->x;
            insertFormBack(pointer,x+1,y,'d');
        }
        else{
            map[(x+1)*axisy+y]=+pointer2->x;
            insertFormBack(pointer2,x+1,y,'d');
        }
    }
    if(map[x*axisy+y+1]==0){
        if(vector=='r'){
            map[x*axisy+y+1]=+pointer->x;
            insertFormBack(pointer,x,y+1,'r');
        }
        else {
            map[x*axisy+y+1]=+pointer2->x;
            insertFormBack(pointer2,x,y+1,'r');
        }
    }
    if(map[(x-1)*axisy+y]==0){
        if(vector=='u'){
            map[(x-1)*axisy+y]=+pointer->x;
            insertFormBack(pointer,x-1,y,'u');
        }
        else{
            map[(x-1)*axisy+y]=+pointer2->x;
            insertFormBack(pointer2,x-1,y,'u');
        }
    }
    if(map[x*axisy+y-1]==0){
        if(vector=='l'){
            map[x*axisy+y-1]=+pointer->x;
            insertFormBack(pointer,x,y-1,'l');
        }
        else {
            map[x*axisy+y-1]=+pointer2->x;
            insertFormBack(pointer2,x,y-1,'l');
        }

    }
}


void BFS(int x,int y,char vector){
    nodep_t queue=createNewNode(0,0,vector);
    nodep_t nextqueue=createNewNode(1,0,vector);
    insertFormBack(queue,x,y,vector);
    map[x*axisy+y]=0;
    while(queue->next!=NULL || nextqueue->next!=NULL){
        if(queue->next==NULL){
            queue=nextqueue;
            nextqueue=createNewNode(queue->x+1,0,vector);
        }
        deleteFromFront(queue,&x,&y,&vector);
        if(x==endx && y==endy){
            min=queue->x;
            map[x*axisy+y]=0;
            break;
        }
        push(queue,nextqueue,x,y,vector);
    }
    allfree(queue);
    allfree(nextqueue);
}


int main(){

    int b,e,k;
    while(scanf("%d%d%d%d%d",&axisx,&axisy,&b,&endy,&k)!=EOF){
        memset(map,-4,sizeof(map));
        for(int x=0;x<axisx;++x)for(int y=0;y<axisy;++y)map[x*axisy+y]=0;
        while(k--){
            int x,y;
            scanf("%d%d",&x,&y);
            map[x*axisy+y]=-1;
        }

        for(int x=0;x<axisx;++x){
            for(int y=0;y<axisy;++y)printf("%d ",map[x*axisy+y]);
            putchar('\n');
        }


        endx=axisx-1;
        min=MAXINF;
        BFS(0,b,'d');
        printf("%d\n",min);

        for(int x=0;x<axisx;++x){
            for(int y=0;y<axisy;++y)printf("%d ",map[x*axisy+y]);
            putchar('\n');
        }
    }
}

/*void push(nodep_t pointer,nodep_t pointer2,int x,int y,char vector){
    if(map[x+1][y]=='1'){
        if(vector=='d'){
            map[x+1][y]='@'+pointer->x;
            insertFormBack(pointer,x+1,y,'d');
        }
        else{
            map[x+1][y]='@'+pointer2->x;
            insertFormBack(pointer2,x+1,y,'d');
        }
    }
    if(map[x][y+1]=='1'){
        if(vector=='r'){
            map[x][y+1]='@'+pointer->x;
            insertFormBack(pointer,x,y+1,'r');
        }
        else {
            map[x][y+1]='@'+pointer2->x;
            insertFormBack(pointer2,x,y+1,'r');
        }
    }
    if(map[x-1][y]=='1'){
        if(vector=='u'){
            map[x-1][y]='@'+pointer->x;
            insertFormBack(pointer,x-1,y,'u');
        }
        else{
            map[x-1][y]='@'+pointer2->x;
            insertFormBack(pointer2,x-1,y,'u');
        }
    }
    if(map[x][y-1]=='1'){
        if(vector=='l'){
            map[x][y-1]='@'+pointer->x;
            insertFormBack(pointer,x,y-1,'l');
        }
        else {
            map[x][y-1]='@'+pointer2->x;
            insertFormBack(pointer2,x,y-1,'l');
        }

    }
}


void BFS(int x,int y,char vector){
    nodep_t queue=createNewNode(0,0,vector);
    nodep_t nextqueue=createNewNode(1,0,vector);
    insertFormBack(queue,x,y,vector);
    map[x][y]='@';
    while(queue->next!=NULL || nextqueue->next!=NULL){
        if(queue->next==NULL){
            queue=nextqueue;
            nextqueue=createNewNode(queue->x+1,0,vector);
        }
        deleteFromFront(queue,&x,&y,&vector);
        if(x==endx && y==endy){
            map[x][y]='%';
            min=queue->x;
            break;
        }
        push(queue,nextqueue,x,y,vector);
    }
    allfree(queue);
    allfree(nextqueue);
}


int main(){
    int axisx,axisy;
    int b,e,k;
    while(scanf("%d%d%d%d%d",&axisx,&axisy,&b,&endy,&k)!=EOF){
        memset(map,0,sizeof(map));
        for(int x=0;x<axisx;++x)for(int y=0;y<axisy;++y)map[x][y]='1';
        while(k--){
            int x,y;
            scanf("%d%d",&x,&y);
            map[x][y]='#';
        }

        for(int x=0;x<axisx;++x)puts(map[x]);
        putchar('\n');

        endx=axisx-1;
        min=MAXINF;
        BFS(0,b,'d');
        printf("%d\n",min);

        for(int x=0;x<axisx;++x)puts(map[x]);
        putchar('\n');
    }
}*/

/*void push(int map[SIZE][SIZE],nodep_t pointer,nodep_t pointer2,int x,int y,char vector){
    if(map[x+1][y]==0){
        if(vector=='d'){
            map[x+1][y]=pointer->x;
            insertFormBack(pointer,x+1,y,'d');
        }
        else{
            map[x+1][y]=pointer2->x;
            insertFormBack(pointer2,x+1,y,'d');
        }
    }
    if(map[x][y+1]==0){
        if(vector=='r'){
            map[x][y+1]=pointer->x;
            insertFormBack(pointer,x,y+1,'r');
        }
        else {
            map[x][y+1]=pointer2->x;
            insertFormBack(pointer2,x,y+1,'r');
        }
    }
    if(map[x-1][y]==0){
        if(vector=='u'){
            map[x-1][y]=pointer->x;
            insertFormBack(pointer,x-1,y,'u');
        }
        else{
            map[x-1][y]=pointer2->x;
            insertFormBack(pointer2,x-1,y,'u');
        }
    }
    if(map[x][y-1]==0){
        if(vector=='l'){
            map[x][y-1]=pointer->x;
            insertFormBack(pointer,x,y-1,'l');
        }
        else {
            map[x][y-1]=pointer2->x;
            insertFormBack(pointer2,x,y-1,'l');
        }

    }
}*/

