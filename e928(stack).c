#include <stdio.h>
#include <stdlib.h>
#define SIZE 10001

typedef struct node_s{
    int data;
    struct node_s *next;
}node_t;

typedef node_t* nodep_t;

nodep_t createNode(int data){
    nodep_t newnode=malloc(sizeof(node_t));
    newnode->data=data;
    newnode->next=NULL;
    return newnode;
}

void insertff(nodep_t node,int data){
    nodep_t newnode=createNode(data);
    newnode->next=node->next;
    node->next=newnode;
}

void putint(int out){
    char buf[1000];
    int n = 0;
    if(out < 0){
        putchar('-');
        out *= -1;
    }
    do
    {
        buf[n++] = '0' + (out%10);
        out /= 10;
    }while(out > 0);
    for(--n; n >= 0; --n)putchar(buf[n]);
    putchar(' ');
}

int get_int(){
    int n = 0, si = 1;
    char tc = getchar();
    while((tc<'0'||tc>'9') &&  tc != '-')tc = getchar();
    if(tc == '-'){
        tc = getchar();
        si = -1;
    }
    while(tc >= '0' && tc <= '9'){
        n = (n<<1) + (n<<3) + (tc ^ '0');
        tc = getchar();
    }
    return n * si;
}

void mux(nodep_t p1,nodep_t p2){
    nodep_t t1=p1;
    nodep_t t2=p2;
    int list[SIZE]={0};
    int i=-1,index=0;
    while(t1->next!=NULL){
        t1=t1->next;
        t2=p2;
        i++;
        index=0;
        while(t2->next!=NULL){
            t2=t2->next;
            list[i+index]+=(t1->data)*(t2->data);
            index++;
        }
    }

    int temp = 0;
    for(int x=i+index-1;x>=0;--x){
        if(temp == 0 && list[x]){
            putint(x);
            putchar('\n');
            temp=1;
        }
        if(temp)putint(list[x]);
    }
    putchar('\n');
}

int main(){
    int n;
    nodep_t p1=createNode(0),p2=createNode(0);
    n = get_int();
    n++;
    while(n--)
        insertff(p1,get_int());
    n = get_int();
    n++;
    while(n--)
        insertff(p2,get_int());
    mux(p1,p2);
    return 0;
}

/*#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 10001

typedef struct node_s{
    int data;
    struct node_s *next;
}node_t;

typedef node_t* nodep_t;

nodep_t createNode(int data){
    nodep_t newnode=malloc(sizeof(node_t));
    newnode->data=data;
    newnode->next=NULL;
    return newnode;
}

void insertff(nodep_t node,int data){
    nodep_t newnode=createNode(data);
    if(node->next==NULL)node->next=newnode;
    else{
        newnode->next=node->next;
        node->next=newnode;
    }
}

int strtoint(char *s){
    int n=0,sign=1,start=0;
    if(s[0]=='-'){
        sign=-1;
        start=1;
    }
    for(;start<strlen(s);++start){
        n*=10;
        n+=s[start]-'0';
    }
    return n*sign;
}

void input(nodep_t *node){
    int n;
    scanf("%d ", &n);
    char s[SIZE];
    gets(s);
    char *sp=strtok(s," ");
    while(sp!=NULL){
        insertff(*node,strtoint(sp));
        sp=strtok(NULL," ");
    }
}

void mux(nodep_t p1,nodep_t p2){
    nodep_t t1=p1;
    nodep_t t2=p2;
    int list[SIZE]={0};
    int i=-1,index=0;
    while(t1->next!=NULL){
        t1=t1->next;
        t2=p2;
        i++;
        index=0;
        while(t2->next!=NULL){
            t2=t2->next;
            list[i+index]+=(t1->data)*(t2->data);
            //printf("i=%d index=%d t1=%d t2=%d\n",i,index,t1->data,t2->data);
            index++;
        }
    }

    int temp = 0;
    for(int x=i+index-1;x>=0;--x){
        if(temp == 0 && list[x]){
            printf("%d\n",x);
            temp=1;
        }
        if(temp)printf("%d ",list[x]);
    }
    putchar('\n');
}

int main(){
    nodep_t p1=createNode(0),p2=createNode(0);
    input(&p1);
    input(&p2);
    mux(p1,p2);
    return 0;
}*/
