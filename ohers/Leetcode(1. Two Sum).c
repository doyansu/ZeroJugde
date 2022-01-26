#include <stdio.h>
#include <stdlib.h>
#define SIZE 13131

typedef struct hash_s{
    int data, index;
    struct hash_s *next;
}hash_t;

typedef hash_t * hashp_t;

hashp_t hashTable[SIZE], *now;

int myabs(int a){
    return a < 0 ? -a : a;
}

void insertHashTable(int key, int index){
    now = hashTable + myabs(key) % SIZE;
    while(*now)
        now = &(*now)->next;
    *now = malloc(sizeof(hash_t));
    (*now)->data = key;
    (*now)->index = index;
    (*now)->next = NULL;
}

void freeHashTable(){
    hashp_t freeNode;
    for(int i = 0; i < SIZE; i++){
        now = hashTable + i;
        while(*now){
            freeNode = *now;
            now = &(*now)->next;
            free(freeNode);
        }
        hashTable[i] = NULL;
    }
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    *returnSize = 2;
    int *output = malloc(2 * sizeof(int));
    for(int i = 0; i < numsSize; i++){
        int diff = target - nums[i];
        now = hashTable + (myabs(diff) % SIZE);
        while(*now){
            if((*now)->data == diff){
                output[0] = (*now)->index;
                output[1] = i;
                freeHashTable();
                return output;
            }
            now = &(*now)->next;
        }
        insertHashTable(nums[i], i);
    }
    return output;
}

int main(){
    int nums[SIZE], size, target, *out, outsize;
    while(scanf("%d", &size) == 1){
        for(int i = 0; i < size; i++)
            scanf("%d", nums + i);
        scanf("%d", &target);
        out = twoSum(nums, size, target, &outsize);
        for(int i = 0; i < outsize; i++)
            printf("%d ", out[i]);
        putchar('\n');
    }
}

/*#define SIZE 13131// 4ms 6.6 MB

typedef struct hash_s{
    int data, index;
    struct hash_s *next;
}hash_t;

typedef hash_t* hashp_t;

hashp_t hashTable[SIZE] = {0}, *now;

int myabs(int a){
    return a < 0 ? -a : a;
}

void insertHashTable(int key, int index){
    now = hashTable + myabs(key) % SIZE;
    while(*now)
        now = &(*now)->next;
    *now = malloc(sizeof(hash_t));
    (*now)->data = key;
    (*now)->index = index;
    (*now)->next = NULL;
}

void freeHashTable(){
    hashp_t freeNode;
    for(int i = 0; i < SIZE; i++){
        //now = hashTable + i;
        //while(*now){
            //freeNode = *now;
            //now = &(*now)->next;
            //free(freeNode);
        //}
        hashTable[i] = NULL;
    }
    //now = NULL;
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    *returnSize = 2;
    int *output = malloc(sizeof(int) << 1);
    for(int i = 0; i < numsSize; i++){
        int diff = target - nums[i];
        now = hashTable + myabs(diff) % SIZE;
        while(*now){
            if((*now)->data == diff){
                output[0] = (*now)->index;
                output[1] = i;
                freeHashTable();
                return output;
            }
            now = &(*now)->next;
        }
        insertHashTable(nums[i], i);
    }
    return output;
}*/


/*int* twoSum(int* nums, int numsSize, int target, int* returnSize){//76 ms	6.3 MB
    *returnSize = 2;.
    int * output = malloc(2 * sizeof(int));
    for(int i = 0; i < numsSize; i++){
        for(int j = i + 1; j < numsSize; j++){
            if(nums[j] + nums[i]== target){
                output[0] = i;
                output[1] = j;
                return output;
            }
        }
    }
    return output;
}
*/
