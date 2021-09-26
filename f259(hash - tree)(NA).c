#include <stdio.h>
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
        temp += ((*src--) ^ '@');
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
}

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

