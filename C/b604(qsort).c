#include <stdio.h>
#define SIZE 101
#define MAXINF 0x7fffffff

typedef struct node_s{
    int x,y;
}node_t;

void SWAP(node_t *a,node_t *b){
    node_t t=*a;
    *a=*b;
    *b=t;
}

int cmp(node_t a,node_t b){
    if(a.x>b.x)return 1;
    else if(a.x==b.x){
        if(a.y>b.y)return 1;
        else if(a.y==b.y)return 0;
        else return -1;
    }
    else return -1;
}

int part(node_t *list,int left,int right,int mid){
    node_t cmpvalue=list[mid];
    SWAP(&list[mid],&list[right]);
    for(int i=left;i<right;++i){
        if(cmp(list[i],cmpvalue)==-1){
            SWAP(&list[left++],&list[i]);
        }
    }
    SWAP(&list[left],&list[right]);
    return left;
}

void myqsort(node_t *list,int left,int right){
    if(right>left){
        int mid=part(list,left,right,(left+right)/2);
        myqsort(list,left,mid-1);
        myqsort(list,mid+1,right);
    }
}

int main(){
    int n;
    while(scanf("%d",&n)){
        if(n==0)break;
        node_t list[n];
        int x,y;
        for(int i=0;i<n;++i){
            scanf("%d%d",&x,&y);
            list[i].x=x;
            list[i].y=y;
        }
        myqsort(list,0,n-1);
        int jugde=1;
        if(n%2)jugde=0;
        else{
            int tempx=list[0].x+list[n-1].x;
            int tempy=list[0].y+list[n-1].y;
            for(int i=1;i<(n/2);++i){
                if((list[i].x+list[n-i-1].x!=tempx) || (list[i].y+list[n-i-1].y!=tempy)){
                    jugde=0;
                    break;
                }
            }
        }
        if(jugde)puts("yes");
        else puts("no");
        /*for(int i=0;i<n;++i){
            printf("x%d y%d\n",list[i].x,list[i].y);
        }*/
    }
}
