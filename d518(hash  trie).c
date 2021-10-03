#include <stdio.h>// TLE
#include <string.h>
#include <stdlib.h>
#define HASHSIZE 104
#define STRSIZE 30
#define MAXINF 0x7fffffff

typedef struct hash_s{
    int key, code;
    char str[STRSIZE];
    struct hash_s *next;
}hash_t;

typedef hash_t* hashp_t;

hashp_t hashTable[HASHSIZE], *p;

static inline hashp_t createNewNode(int key, char *src, int code){
    hashp_t newNode = malloc(sizeof(hash_t));
    newNode->key = key;
    newNode->code = code;
    newNode->next = NULL;
    strcpy(newNode->str, src);
    return newNode;
}

static inline int getKey(char *src){
    int key = 0, p = 1;
    while(*src){
        key = key * 26 + (*src-- ^ 90);
        key &= MAXINF;
    }
    return key;
}

static inline void insertHashTable(int key, char *src, int code){
    p = hashTable + key % HASHSIZE;
    while(*p)
        p = &(*p)->next;
    *p = createNewNode(key, src, code);
}

static inline void getAns(char *src, int *code){
    int key = getKey(src);
    p = hashTable + key % HASHSIZE;
    while(*p){
        if((*p)->key == key && strcmp(src, (*p)->str) == 0){
            printf("Old! %d\n", (*p)->code);
            return ;
        }
        p = &(*p)->next;
    }
    printf("New! %d\n", *code);
    insertHashTable(key, src, (*code)++);
}

static inline void freeHashTable(){
    hashp_t freeNode;
    for(int i = 0; i < HASHSIZE; i++){
        p = hashTable + i;
        while(*p){
            freeNode = *p;
            p = &(*p)->next;
            free(freeNode);
        }
        hashTable[i] = NULL;
    }
}

int main(){
    int n;
    char input[STRSIZE];
    while(scanf("%d ", &n) == 1){
        int number = 1;
        while(n--){
            scanf("%s", input);
            getAns(input, &number);
        }
        freeHashTable();
    }
    return 0;
}
