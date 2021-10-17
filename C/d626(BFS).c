#include <stdio.h>
#include <stdlib.h>
#define SIZE 102

typedef struct node_s{
    int x, y;
    struct node_s* next;
}node_t;

typedef node_t* nodep_t;

nodep_t createNewNode(int x, int y){
    nodep_t newnode = malloc(sizeof(node_t));
    newnode->x = x;
    newnode->y = y;
    newnode->next = NULL;
    return newnode;
}

void deleteFormFront(nodep_t pointer, int *x, int *y){
    nodep_t freeNode = pointer->next;
    *x = freeNode->x;
    *y = freeNode->y;
    pointer->next = freeNode->next;
    free(freeNode);
}

nodep_t insertFromTail(nodep_t tail, int x, int y){
    tail->next = createNewNode(x, y);
    return tail->next;
}

void BFS(char* map[SIZE], int size, int x, int y){
    int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    nodep_t queue = createNewNode(-1, -1), tail = queue;
    insertFromTail(tail, x, y);
    map[x][y] = '+';
    while(queue->next != NULL){
        deleteFormFront(queue, &x, &y);
        if(queue->next == NULL)tail = queue;
        for(int i = 0; i < 4; i++){
            int nextx = x + dir[i][0], nexty = y + dir[i][1];
            if(nextx < 0 || nexty < 0 || nextx >= size || nexty >= size)continue;
            if(map[nextx][nexty] == '-'){
                map[nextx][nexty] = '+';
                tail = insertFromTail(tail, nextx, nexty);
            }
        }
    }
}

int main(){
    int n, orgx, orgy;
    char* map[SIZE];
    scanf("%d", &n);
    getchar();
    for(int i = 0; i < n; i++){
        char *p = malloc((n+1) * sizeof(char));
        fgets(p, SIZE, stdin);
        map[i] = p;
    }
    scanf("%d%d", &orgx, &orgy);
    BFS(map, n, orgx, orgy);
    for(int i = 0; i < n; i++){
        fputs(map[i], stdout);
        free(map[i]);
    }
}
