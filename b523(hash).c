#include <stdio.h>// AC (6ms, 2MB)
#include <string.h>
#include <stdlib.h>
#define HASHSIZE 500
#define STRSIZE 10001

typedef struct hash_s{
    int key;
    char str[STRSIZE];
    struct hash_s *next;
}hash_t;

typedef hash_t* hashp_t;

hashp_t hashTable[HASHSIZE], *p;

static inline hashp_t createNewNode(int key, char *src){
    hashp_t newNode = malloc(sizeof(hash_t));
    newNode->key = key;
    newNode->next = NULL;
    strcpy(newNode->str, src);
    return newNode;
}

static inline int getKey(char *src){
    int key = 0;
    while(*src)
        key += *src++;
    return key;
}

static inline void insertHashTable(int key, char *src){
    p = hashTable + key % HASHSIZE;
    while(*p)
        p = &(*p)->next;
    *p = createNewNode(key, src);
}

static inline void getAns(char *src){
    int key = getKey(src);
    p = hashTable + key % HASHSIZE;
    while(*p){
        if((*p)->key == key && strcmp(src, (*p)->str) == 0){
            puts("YES");
            return ;
        }
        p = &(*p)->next;
    }
    puts("NO");
    insertHashTable(key, src);
}

int main(){
    int n;
    char input[STRSIZE];
    while(gets(input))
        getAns(input);
    return 0;
}
