#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 10001
#define MAXINF 0x7fffffff

double weights[SIZE][SIZE];
double distance[SIZE];
int visit[SIZE];
double fw[SIZE][SIZE];
int temp[SIZE];

typedef struct node_s{
    int number;
    double d;
    struct node_s *next;
}node_t;

typedef node_t* nodep_t;

nodep_t createNode(int number, double d){
    nodep_t newNode=malloc(sizeof(node_t));
    newNode->number=number;
    newNode->d=d;
    newNode->next=NULL;
    return newNode;
}

void insertFromMin(nodep_t pointer, int number, double d){
    nodep_t newNode=createNode(number,d);
    while(pointer->next!=NULL && pointer->next->d<d)
        pointer = pointer->next;
    newNode->next = pointer->next;
    pointer->next = newNode;
}

int deleteFromFront(nodep_t pointer){
    nodep_t freeNode=pointer->next;
    int temp = freeNode->number;
    pointer->next = freeNode->next;
    free(freeNode);
    return temp;
}

void allfree(nodep_t pointer){
    nodep_t freeNode;
    while(pointer!=NULL){
        freeNode = pointer;
        pointer = pointer->next;
        free(freeNode);
    }
}

int dijkstra_with_priority_queue(double w[SIZE][SIZE], int size, int start, int end){
    nodep_t queue=createNode(0,-1);
    distance[start] = 0;
    temp[start]=0;
    insertFromMin(queue,start,0);
    for(int i = 1; i < size; i++){
        int a = -1;
        if(queue == NULL)return -1;
        a = deleteFromFront(queue);
        visit[a] = 1;
        for(int b = 1; b < size; b++)
            if(!visit[b] && w[a][b] != MAXINF && distance[a] + w[a][b] < distance[b]){
                temp[b] = temp[a] + weights[a][b];
                insertFromMin(queue, b, distance[b] = distance[a] + w[a][b]);
            }
    }
    allfree(queue);
    return 1;
}

int main(){
    int t;
    scanf("%d", &t);
    while (t--){
        int size, data, start, end;
        scanf("%d%d%d%d", &size, &data, &start, &end);
        size++;
        for(int i = 0; i < size; i++){
            distance[i] = MAXINF;
            visit[i] = 0;
            for(int j = 0; j < size; j++){
                weights[i][j] = MAXINF;
                fw[i][j] = MAXINF;
            }
        }
        while (data--){
            int a, b;
            double d,v;
            scanf("%d%d%lf%lf", &a, &b, &d, &v);
            weights[a][b] = weights[b][a] = d;
            fw[a][b] = fw[b][a] = d / v;
        }
        dijkstra_with_priority_queue(weights, size, start, end);
        printf("%.0f ", distance[end]);
        for(int i = 0; i < size; i++){
            visit[i] = 0;
            distance[i] = temp[i] = MAXINF;
        }
        dijkstra_with_priority_queue(fw, size, start, end);
        printf("%d\n", temp[end]);
    }
    return 0;
}

/*#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 10001
#define MAXINF 0x7fffffff

double weights[SIZE][SIZE];
double distance[SIZE];
int visit[SIZE];
double fw[SIZE][SIZE];

typedef struct node_s{
    int number;
    double d;
    struct node_s *next;
}node_t;

typedef node_t* nodep_t;

nodep_t createNode(int number, double d){
    nodep_t newNode=malloc(sizeof(node_t));
    newNode->number=number;
    newNode->d=d;
    newNode->next=NULL;
    return newNode;
}

void insertFromMin(nodep_t pointer, int number, double d){
    nodep_t newNode=createNode(number,d);
    while(pointer->next!=NULL && pointer->next->d<d)
        pointer = pointer->next;
    newNode->next = pointer->next;
    pointer->next = newNode;
}

int deleteFromFront(nodep_t pointer){
    nodep_t freeNode=pointer->next;
    int temp = freeNode->number;
    pointer->next = freeNode->next;
    free(freeNode);
    return temp;
}

void allfree(nodep_t pointer){
    nodep_t freeNode;
    while(pointer!=NULL){
        freeNode = pointer;
        pointer = pointer->next;
        free(freeNode);
    }
}

int dijkstra_with_priority_queue(double w[SIZE][SIZE], int size, int start, int end){
    nodep_t queue=createNode(0,-1);
    distance[start] = 0;
    insertFromMin(queue,start,0);
    for(int i = 1; i < size; i++){
        int a = -1;
        if(queue == NULL)return -1;
        a = deleteFromFront(queue);
        visit[a] = 1;
        for(int b = 1; b < size; b++)
            if(!visit[b] && w[a][b] != MAXINF && distance[a] + w[a][b] < distance[b])
                insertFromMin(queue, b, distance[b] = distance[a] + w[a][b]);
    }
    allfree(queue);
    return 1;
}

int main(){
    int t;
    scanf("%d", &t);
    while (t--){
        int size, data, start, end;
        scanf("%d%d%d%d", &size, &data, &start, &end);
        size++;
        for(int i = 0; i < size; i++){
            distance[i] = MAXINF;
            visit[i] = 0;
            for(int j = 0; j < size; j++){
                weights[i][j] = MAXINF;
                fw[i][j] = MAXINF;
            }
        }
        while (data--){
            int a, b;
            double d,v;
            scanf("%d%d%lf%lf", &a, &b, &d, &v);
            weights[a][b] = weights[b][a] = d;
            fw[a][b] = fw[b][a] = d / v;
        }
        dijkstra_with_priority_queue(weights, size, start, end);
        printf("%.0f ", distance[end]);
        for(int i = 0; i < size; i++){
            visit[i] = 0;
            distance[i] = MAXINF;
        }
        dijkstra_with_priority_queue(fw, size, start, end);
        printf("%.3f\n", distance[end]);
    }
    return 0;
}*/

/*#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 10001
#define MAXINF 0x7fffffff

int weights[SIZE][SIZE];
int distance[SIZE];
int visit[SIZE];
double fw[SIZE][SIZE];
double fd[SIZE];

typedef struct node_s{
    int number,d;
    struct node_s *next;
}node_t;

typedef node_t* nodep_t;

nodep_t createNode(int number, int d){
    nodep_t newNode=malloc(sizeof(node_t));
    newNode->number=number;
    newNode->d=d;
    newNode->next=NULL;
    return newNode;
}

void insertFromMin(nodep_t pointer, int number, int d){
    nodep_t newNode=createNode(number,d);
    while(pointer->next!=NULL && pointer->next->d<d)
        pointer = pointer->next;
    newNode->next = pointer->next;
    pointer->next = newNode;
}

int deleteFromFront(nodep_t pointer){
    nodep_t freeNode=pointer->next;
    int temp = freeNode->number;
    pointer->next = freeNode->next;
    free(freeNode);
    return temp;
}

int dijkstra_with_priority_queue(int size, int start, int end){
    nodep_t queue=createNode(0,-1);
    distance[start] = 0;
    insertFromMin(queue,start,0);
    for(int i = 0; i < size; i++){
        int a = -1;
        if(queue == NULL)return -1;
        a = deleteFromFront(queue);
        visit[a] = 1;
        for(int b = 0; b < size; b++)
            if(!visit[b] && weights[a][b] != MAXINF && distance[a] + weights[a][b] < distance[b])
                insertFromMin(queue, b, distance[b] = distance[a] + weights[a][b]);
    }
    return 1;
}

int main(){
    int t;
    scanf("%d", &t);
    while (t--){
        int size, data, start, end;
        scanf("%d%d%d%d", &size, &data, &start, &end);
        for(int i = 0; i < size; i++){
            distance[i] = MAXINF;
            visit[i] = 0;
            for(int j = 0; j < size; j++)
                weights[i][j] = MAXINF;
        }
        while (data--){
            int a, b, d ,v;
            scanf("%d%d%d%d", &a, &b, &d, &v);
            weights[a][b] = weights[b][a] = d;
            fw[a][b] = fw[b][a] = d / v;
        }
        dijkstra_with_priority_queue(size,start,end);
        printf("%d ",distance[end]);
        for(int i = 0; i < size; i++)
            visit[i] = 0;

        printf("%d\n",distance[end]);
    }
    return 0;
}*/
