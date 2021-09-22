#include <stdio.h>//	AC (0.6s, 244KB)
#include <stdlib.h>
#define MAXMOD 200

typedef struct hash_s{
    int data;
    struct hash_s *next;
}hash_t;

typedef hash_t* hashp_t;

int m;
hashp_t hashTable[MAXMOD], *p, *last, temp;

static inline hashp_t createNewNode(int data){
    hashp_t newNode = malloc(sizeof(hash_t));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

static inline void insertHashTable(int data){
    last = p = hashTable + data % m;
    while(*p && (*p)->data < data){
        last = p;
        p = &(*p)->next;
    }
    if(*p){
        if((*p)->data == data)
            return;
        temp = createNewNode(data);
        temp->next = *p;
        if(p == last)
            *p = temp;
        else
            (*last)->next = temp;
    }
    else
        *p = createNewNode(data);
}

static inline void deleteData(int data){
    last = p = hashTable + data % m;
    if(!(*p))
        return;
    while(*p && (*p)->data < data){
        last = p;
        p = &(*p)->next;
    }
    if(*p && (*p)->data == data){
        if(p == last){
            temp = *p;
            *p = (*p)->next;
            *last = *p;
            free(temp);
        }
        else {
            temp = *p;
            (*last)->next = (*p)->next;
            free(temp);
        }
    }
}

static inline void putHashTable(){
    puts("===== s =====");
    for(int i = 0; i < m; i++){
        temp = hashTable[i];
        printf("[%03d]:", i);
        while(temp){
            printf("%d -> ", temp->data);
            temp = temp->next;
        }
        puts("NULL");
    }
    puts("===== e =====");
}

static inline void freeHashTable(){
    hashp_t freeNode;
    for(int i = 0; i < m; i++){
        temp = hashTable[i];
        while(temp){
            freeNode = temp;
            temp = temp->next;
            free(freeNode);
        }
        hashTable[i] = NULL;
    }
}

int main(){
    int k, oper;
    while(scanf("%d%d", &k, &m) == 2){
        while(k--){
            scanf("%d", &oper);
            switch(oper){
            case 1:
                scanf("%d", &oper);
                insertHashTable(oper);
                break;
            case 2:
                scanf("%d", &oper);
                deleteData(oper);
                break;
            case 3:
                putHashTable();
                break;
            }
        }
        freeHashTable();
    }
}
