#include <stdio.h>
#include <stdlib.h>
#define SIZE 100002//AC 0.3S SIZE=1000002

int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    int list[SIZE];
    int kill[SIZE]={0};
    for(int i=1;i<n+1;++i)list[i]=i+1;
    while(m--){
        int id;
        scanf("%d",&id);
        if(kill[id]==1 || list[id]>n)puts("0u0 ...... ?");
        else{
            int killed=list[id];
            printf("%d\n",killed);
            kill[killed]=1;
            list[id]=list[killed];
        }
    }
}

/*#include <stdio.h>
#include <stdlib.h>
#define SIZE 100002//AC 0.3S SIZE=1000002

typedef struct person_s{
    int next;
    int kill;
}person_t;

void kill(person_t list[SIZE],int killer,int n){
    if(list[killer].next>n){
        puts("0u0 ...... ?");
        return;
    }
    printf("%d\n",list[killer].next);
    list[list[killer].next].kill=1;
    list[killer].next=list[list[killer].next].next;
}

int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    person_t list[SIZE];
    for(int i=1;i<n+1;++i){
        list[i].kill=0;
        list[i].next=i+1;
    }
    while(m--){
        int id;
        scanf("%d",&id);
        if(list[id].kill==1)puts("0u0 ...... ?");
        else kill(list,id,n);
    }
}*/

/*#include <stdio.h>
#include <stdlib.h>
#define SIZE 100001//AC 0.4S SIZE=1000001

typedef struct person_s{
    int id;
    int kill;
    struct person_s* next;
}person_t;

typedef person_t* personp_t;

personp_t createPeople(int id){
    personp_t newPeople=malloc(sizeof(person_t));
    newPeople->id=id;
    newPeople->kill=0;
    newPeople->next=NULL;
    return newPeople;
}

void lineup(personp_t list[SIZE],int size){
    personp_t pointer=createPeople(0);
    list[0]=pointer;
    for(int i=1;i<size+1;++i){
        pointer->next=createPeople(i);
        pointer=pointer->next;
        list[i]=pointer;
    }
}

void kill(personp_t pointer){
    if(pointer->next==NULL){
        puts("0u0 ...... ?");
        return;
    }
    personp_t killedPerson=pointer->next;
    printf("%d\n",killedPerson->id);
    killedPerson->kill=1;
    pointer->next=killedPerson->next;
}

int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    personp_t list[SIZE];
    lineup(list,n);
    while(m--){
        int id;
        scanf("%d",&id);
        if(list[id]->kill==1)puts("0u0 ...... ?");
        else kill(list[id]);
    }
}*/
