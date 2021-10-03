#include <stdio.h>// AC (0.3s, 660KB)
#include <string.h>
#include <stdlib.h>
#define HASHSIZE 104
#define STRSIZE 30
#define MAXINF 0x7fffffff

typedef struct hash_s{
    unsigned int key, code;
    char str[STRSIZE];
    struct hash_s *next;
}hash_t;

typedef hash_t* hashp_t;

hashp_t hashTable[HASHSIZE], *p;

static inline hashp_t createNewNode(unsigned int key, char *src, unsigned int code){
    hashp_t newNode = malloc(sizeof(hash_t));
    newNode->key = key;
    newNode->code = code;
    newNode->next = NULL;
    strcpy(newNode->str, src);
    return newNode;
}

static inline unsigned int getKey(char *src){// BKDR
    unsigned int key = 0;
    while(*src)
        key = 131 * key + (*src++);
    return key & MAXINF;
}

static inline void getAns(char *src, unsigned int *code){
    unsigned int key = getKey(src);
    p = hashTable + key % HASHSIZE;
    while(*p){
        if((*p)->key == key && strcmp(src, (*p)->str) == 0){
            printf("Old! %d\n", (*p)->code);
            return ;
        }
        p = &(*p)->next;
    }
    *p = createNewNode(key, src, *code);
    printf("New! %d\n", (*code)++);
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
        unsigned int number = 1;
        while(n--){
            scanf("%s", input);
            getAns(input, &number);
        }
        freeHashTable();
    }
    return 0;
}

/*
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define HASHSIZE 104
#define STRSIZE 30
#define MAXINF 0x7fffffff

typedef struct hash_s{
    unsigned int key, code;
    char str[STRSIZE];
    struct hash_s *next;
}hash_t;

typedef hash_t* hashp_t;

hashp_t hashTable[HASHSIZE], *p;

static inline hashp_t createNewNode(unsigned int key, char *src, unsigned int code){
    hashp_t newNode = malloc(sizeof(hash_t));
    newNode->key = key;
    newNode->code = code;
    newNode->next = NULL;
    strcpy(newNode->str, src);
    return newNode;
}

static inline unsigned int getKey(char *src){// APH
    unsigned int key = 0;
    for(int i = 0; *src; i++){
        if(i & 1)
            key ^= (key << 7) ^ (key >> 3) ^ (*src++);
        else
            key ^= (key << 11) ^ (key >> 5) ^ (*src++);
    }
    return key & MAXINF;
}

static inline void getAns(char *src, unsigned int *code){
    unsigned int key = getKey(src);
    p = hashTable + key % HASHSIZE;
    while(*p){
        if((*p)->key == key && strcmp(src, (*p)->str) == 0){
            printf("Old! %d\n", (*p)->code);
            return ;
        }
        p = &(*p)->next;
    }
    *p = createNewNode(key, src, *code);
    printf("New! %d\n", (*code)++);
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
        unsigned int number = 1;
        while(n--){
            scanf("%s", input);
            getAns(input, &number);
        }
        freeHashTable();
    }
    return 0;
}
*/


/*
#include <stdio.h>// 	AC (0.3s, 676KB)
#include <string.h>
#include <stdlib.h>
#define HASHSIZE 104
#define STRSIZE 30
#define MAXINF 0x7fffffff

typedef struct hash_s{
    unsigned int key, code;
    char str[STRSIZE];
    struct hash_s *next;
}hash_t;

typedef hash_t* hashp_t;

hashp_t hashTable[HASHSIZE], *p;

static inline hashp_t createNewNode(unsigned int key, char *src, unsigned int code){
    hashp_t newNode = malloc(sizeof(hash_t));
    newNode->key = key;
    newNode->code = code;
    newNode->next = NULL;
    strcpy(newNode->str, src);
    return newNode;
}

static inline unsigned int getKey(char *src){
    unsigned int key = 0;
    while(*src)
        key = 65599 * key + (*src++);
    return key & MAXINF;
}

static inline void getAns(char *src, unsigned int *code){
    unsigned int key = getKey(src);
    p = hashTable + key % HASHSIZE;
    while(*p){
        if((*p)->key == key && strcmp(src, (*p)->str) == 0){
            printf("Old! %d\n", (*p)->code);
            return ;
        }
        p = &(*p)->next;
    }
    *p = createNewNode(key, src, *code);
    printf("New! %d\n", (*code)++);
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
        unsigned int number = 1;
        while(n--){
            scanf("%s", input);
            getAns(input, &number);
        }
        freeHashTable();
    }
    return 0;
}*/
