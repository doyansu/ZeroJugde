#include <stdio.h>
#include <stdlib.h>

typedef struct node_s{
    int x, y;
}node_t;

int cmp(const node_t *a, const node_t *b){
    return a->x == b->x ? a->y - b->y : a->x - b->x;
}

static inline void solve(){
    int n;
    scanf("%d", &n);
    node_t list[n];
    for(int i = 0; i < n; i++)
        scanf("%d%d", &list[i].x, &list[i].y);
    qsort(list, n, sizeof(node_t), cmp);
    for(int i = 0; i < n; i++)
        printf("%d %d\n", list[i].x, list[i].y);
}

int main(){
    solve();
    return 0;
}

/*#include <stdio.h>
#include <stdlib.h>

typedef struct node_s{
    int x,y;
    struct node_s* next;
}node_t;
typedef node_t* nodep_t;

nodep_t createNewNode(int x,int y){
    nodep_t NewNode=malloc(sizeof(node_t));
    NewNode->x=x;
    NewNode->y=y;
    NewNode->next=NULL;
    return NewNode;
}

void insert(nodep_t first,int x,int y){
    nodep_t NewNode=createNewNode(x,y);
    while(first->next!=NULL){
        if(first->next->x>x || (first->next->x==x && first->next->y>y)){
            NewNode->next=first->next;
            first->next=NewNode;
            return;
        }
        first=first->next;
    }
    first->next=NewNode;
}

void print(nodep_t first){
    while(first->next!=NULL){
        first=first->next;
        printf("%d %d\n",first->x,first->y);
    }
}

int main(){
    int n;
    nodep_t first=createNewNode(-1,-1);
    scanf("%d",&n);
    while(n--){
        int x,y;
        scanf("%d %d",&x,&y);
        insert(first,x,y);
    }
    print(first);

}*/
