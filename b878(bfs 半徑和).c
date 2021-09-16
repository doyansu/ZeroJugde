#include <stdio.h>
#include <stdlib.h>

typedef struct node_s{
    int value,radius;
    struct node_s *left;
    struct node_s *right;
}node_t;

typedef node_t* nodep_t;

nodep_t createNode(int value){
    nodep_t newNode=malloc(sizeof(node_t));
    newNode->value=value;
    newNode->left=NULL;
    newNode->right=NULL;
    newNode->radius=0;
    return newNode;
}

nodep_t getData(int n){
    nodep_t nowNode,lastNode=createNode(-1);
    for(int i=0;i<n;++i){
        int value;
        scanf("%d",&value);
        nowNode=createNode(value);
        nowNode->left=lastNode;
        lastNode->right=nowNode;
        lastNode=nowNode;
    }
    lastNode=createNode(-1);
    nowNode->right=lastNode;
    return nowNode;
}

int getRadius(nodep_t firstNode,int n){
    nodep_t leftNode=malloc(sizeof(node_t)),righNode=malloc(sizeof(node_t));
    int sum=0;
    while(n--){
        int radius=0,value=firstNode->value;
        leftNode=righNode=firstNode;
        do{
            leftNode=leftNode->left;
            righNode=righNode->right;
            ++radius;
        }while((value<=leftNode->value) && (value<=righNode->value));
        sum+=radius;
        firstNode=firstNode->left;
    }
    printf("%d\n",sum);
    return sum;
}

int main(){
    int n;
    nodep_t firstNode;
    scanf("%d",&n);
    firstNode=getData(n);
    getRadius(firstNode,n);
}
