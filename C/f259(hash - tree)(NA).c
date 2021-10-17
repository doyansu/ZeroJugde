#include <stdio.h>// 	AC (0.4s, 50.2MB)
#include <string.h>
#include <stdlib.h>
#define HASHSIZE 313131
#define STRSIZE 50
#define MAXINF 0x7fffffff

typedef struct hash_s{
    unsigned int key;
    char str[STRSIZE];
    struct hash_s *next;
}hash_t;

typedef hash_t* hashp_t;

hashp_t hashTable[HASHSIZE], *p;

static inline hashp_t createNewNode(unsigned int key, char *src){
    hashp_t newNode = malloc(sizeof(hash_t));
    newNode->key = key;
    newNode->next = NULL;
    strcpy(newNode->str, src);
    return newNode;
}

static inline unsigned int getKey(char *src){// BKDR
    unsigned int key = 0;
    while(*src)
        key = 31 * key + (*src++);// 31, 131, 1313, 13131, 131313 ...
    return key & MAXINF;
}

/*static inline unsigned int getKey(char *src){// APH
    unsigned int key = 0;
    for(int i = 0; *src; i++){
        if(i & 1)
            key ^= (key << 7) ^ (key >> 3) ^ (*src++);
        else
            key ^= (key << 11) ^ (key >> 5) ^ (*src++);
    }
    return key & MAXINF;
}*/

static inline void getAns(char *src){
    unsigned int key = getKey(src);
    p = hashTable + key % HASHSIZE;
    while(*p){
        if((*p)->key == key && strcmp(src, (*p)->str) == 0){
            puts("1");
            return ;
        }
        p = &(*p)->next;
    }
    puts("0");
    *p = createNewNode(key, src);
}

int main(){
    int n;
    char input[STRSIZE];
    while(gets(input))
        getAns(input);
    return 0;
}

/*#include <stdio.h>// 	AC (2.2s, 45.6MB)
#include <string.h>
#include <stdlib.h>
#define HASHSIZE 13131
#define STRSIZE 50
#define MAXINF 0x7fffffff

typedef struct hash_s{
    unsigned int key;
    char str[STRSIZE];
    struct hash_s *next;
}hash_t;

typedef hash_t* hashp_t;

hashp_t hashTable[HASHSIZE], *p;

static inline hashp_t createNewNode(unsigned int key, char *src){
    hashp_t newNode = malloc(sizeof(hash_t));
    newNode->key = key;
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

static inline void getAns(char *src){
    unsigned int key = getKey(src);
    p = hashTable + key % HASHSIZE;
    while(*p){
        if((*p)->key == key && strcmp(src, (*p)->str) == 0){
            puts("1");
            return ;
        }
        p = &(*p)->next;
    }
    puts("0");
    *p = createNewNode(key, src);
}

int main(){
    int n;
    char input[STRSIZE];
    while(gets(input))
        getAns(input);
    return 0;
}
*/

/*#include <stdio.h>// na60%
#include <stdlib.h>
#include <string.h>
#define INPUTSIZE 50
#define TABLESIZE 47777

typedef struct hash_s{
    long long int Key;
    char STR[INPUTSIZE];
    struct hash_s *next;
}hash_t;

typedef hash_t* hashp_t;

hashp_t hashTable[TABLESIZE], *p;
long long int key;

hashp_t createNewNode(char *src, long long int key){
    hashp_t newNode = malloc(sizeof(hash_t));
    strcpy(newNode->STR, src);
    newNode->Key = key;
    newNode->next = NULL;
    return newNode;
}

char mystrcmp(char *s1, char *s2){
    while(*s1 || *s2)
        if(*s1++ != *s2++)
            return 0;
    return 1;
}

long long int getKey(char *src){
     long long int temp = 0;
     while(*src)
        temp = (*src++);
     return temp & 0x7fffffffffffffff;
}

long long int searchStr(char *src){
    key = getKey(src);
    p = hashTable + (key % TABLESIZE);
    while(*p){
        if(key == (*p)->Key && mystrcmp(src, (*p)->STR))
            return 0;
        p = &(*p)->next;
    }
    return key;
}

void insertHashTable(char *src){
    p = hashTable + (key % TABLESIZE);
    while(*p)
        p = &(*p)->next;
    *p = createNewNode(src, key);
}

int main(){
    char input[INPUTSIZE];
    while(gets(input)){
        if(searchStr(input)){
            puts("0");
            insertHashTable(input);
        }
        else
            puts("1");
    }
}*/

/*#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define INPUTSIZE 40
#define TABLESIZE 47777

typedef struct hash_s{
    long long int Key;
    char STR[INPUTSIZE];
    struct hash_s *next;
}hash_t;

typedef hash_t* hashp_t;

hashp_t hashTable[TABLESIZE], *p;
long long int key;

hashp_t createNewNode(char *src, long long int key){
    hashp_t newNode = malloc(sizeof(hash_t));
    strcpy(newNode->STR, src);
    newNode->Key = key;
    newNode->next = NULL;
    return newNode;
}

char mystrcmp(char *s1, char *s2){
    while(*s1 || *s2)
        if(*s1++ != *s2++)
            return 0;
    return 1;
}

long long int getKey(char *src){
     long long int temp = 0;
     while(*src)
        temp = (temp << 4) + (temp << 3) + (temp << 2) + ((*src--) - '@');
     return temp & 0x7fffffffffffffff;
}

long long int searchStr(char *src){
    key = getKey(src);
    p = hashTable + (key % TABLESIZE);
    while(*p){
        if(key == (*p)->Key && mystrcmp(src, (*p)->STR))
            return 0;
        p = &(*p)->next;
    }
    return key;
}

void insertHashTable(char *src){
    p = hashTable + (key % TABLESIZE);
    while(*p)
        p = &(*p)->next;
    *p = createNewNode(src, key);
}

int main(){
    char input[INPUTSIZE];
    while(fgets(input, INPUTSIZE, stdin)){
        if(searchStr(input)){
            puts("0");
            insertHashTable(input);
        }
        else
            puts("1");
    }
}*/

