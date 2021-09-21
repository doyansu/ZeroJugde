/*
hash table
*/

#include <stdio.h>// AC (34ms, 7.8MB)
#include <stdlib.h>
#include <string.h>
#define TABLESIZE 47777

typedef struct hash_s{
    int len;
    long long int Key;
    char values[40][11];
    struct hash_s *next;
}hash_t;

typedef hash_t* hashp_t;

hashp_t hashTable[TABLESIZE], *pointer;
long long int key;
char valueTemp[11];

static inline long long int hashFunction(char *src){
    char code[10] = {0};
    long long int temp = 0;
    while(*src)
        code[('0' ^ *src++)]++;
    for(int i = 1; i < 10; i++)
        temp = (temp << 3) + (temp << 1) + code[i];
    return temp;
}

static inline void insertHash(long long int num){
    sprintf(valueTemp, "%lld", num);
    key = hashFunction(valueTemp);
    pointer = hashTable + (key % TABLESIZE);
    while(*pointer){
        if((*pointer)->Key == key){
            strcpy((*pointer)->values[(*pointer)->len++], valueTemp);
            return;
        }
        pointer = &(*pointer)->next;
    }
    *pointer = malloc(sizeof(hash_t));
    (*pointer)->Key = key;
    (*pointer)->len = 1;
    (*pointer)->next = NULL;
    strcpy((*pointer)->values[0], valueTemp);
}

static inline void getAns(char *src){
    key = hashFunction(src);
    pointer = hashTable + (key % TABLESIZE);
    while(*pointer){
        if((*pointer)->Key == key){
            for(int i = 0; i < (*pointer)->len; i++)
                printf("%s ", (*pointer)->values[i]);
            putchar('\n');
            return;
        }
        pointer = &(*pointer)->next;
    }
    puts("0");
}

int main(){
    for(long long int i = 34, temp; i < 100000; i++){
        temp = i * i;
        while(temp % 10)
            temp /= 10;
        if(temp == 0)
            insertHash(i * i);
    }
    char input[11];
    while(scanf("%s", input) == 1)
        getAns(input);
    return 0;
}

/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Hash
{
    unsigned int Key, vLen;
    char Values[40][11];
    struct Hash* Next;
}Hash;

Hash* pList[32768];
Hash** now;
long long tmp;
unsigned int key, pLen;
char value[11];

static inline unsigned int APHash(char src[])
{
    unsigned int hash = 0;
    char str[10] = { 0 };
    for (int i = 0; src[i]; i++)
        str[src[i] - '0']++;
    for (int i = 9; i; i--)
    {
        if (i & 1)
            hash ^= (~((hash << 11) ^ (str[i]) ^ (hash >> 5)));
        else
            hash ^= ((hash << 7) ^ (str[i]) ^ (hash >> 3));
    }
    return (hash & 0x7FFFFFFF);
}

static inline void addHash(long long square)
{
    sprintf(value, "%lld", square);
    key = APHash(value);
    now = &pList[key & 32767];
    while (*now)
    {
        if ((*now)->Key == key)
        {
            strcpy((*now)->Values[(*now)->vLen++], value);
            return;
        }
        now = &(*now)->Next;
    }
    (*now) = malloc(sizeof(Hash));
    (*now)->Key = key;
    (*now)->vLen = 1;
    strcpy((*now)->Values[0], value);
    (*now)->Next = NULL;
}

static inline void getAns(char src[])
{
    key = APHash(src);
    now = &pList[key & 32767];
    while (*now)
    {
        if ((*now)->Key == key)
        {
            for (int i = 0; i < (*now)->vLen; i++)
                printf("%s ", (*now)->Values[i]);
            putchar('\n');
            return;
        }
        now = &(*now)->Next;
    }
    puts("0");
}

int main()
{
    for (long long i = 34; i < 100000; i++)
    {
        tmp = i * i;
        while (tmp % 10)
            tmp /= 10;
        if (!tmp)
            addHash(i * i);
    }
    while (scanf(" %s", value) == 1)
    {
        getAns(value);
    }
    return 0;
}*/
