#include <stdio.h>// 	AC (1.4s, 212KB)
#include <string.h>
#define MAXSIZE 100001

int list[MAXSIZE] = {0};

int main(){
    int n;
    while(scanf("%d", &n) == 1){
        int temp;
        for(int i = 0; i < n; i++){
            scanf("%d", &temp);
            list[temp]++;
        }
        temp = 0;
        long long coeff = 1 - n, diff = 0;
        for(int i = 0; i < n; i++, coeff += 2){
            while(list[temp] == 0)
                temp++;
            diff += coeff * temp;
            list[temp]--;
        }
        printf("%lld\n", diff);

    }
}


/*#include <stdio.h>//io	AC (0.2s, 276KB)
#include <string.h>
#define MAXSIZE 100001
#define BUFSIZE 65536

int list[MAXSIZE] = {0};

static inline char readChar(){
    static char buf[BUFSIZE], *p = buf + BUFSIZE, *end = buf + BUFSIZE;
    if(p == end){
        if(end < buf + BUFSIZE)
            return EOF;
        end = buf + fread(buf, 1, BUFSIZE, stdin);
        p = buf;
    }
    return *p++;
}

static inline char readUint(register int *read){
    register char ch;
    while((ch = readChar()) < '0')
        if(ch == EOF)
            return 0;
    *read = ch ^ '0';
    while((ch = readChar()) >= '0')
        *read = (*read << 3) + (*read << 1) + (ch ^ '0');
    return 1;
}

int main(){
    int n;
    while(readUint(&n)){
        int temp;
        for(int i = 0; i < n; i++){
            readUint(&temp);
            list[temp]++;
        }
        temp = 0;
        long long coeff = 1 - n, diff = 0;
        for(int i = 0; i < n; i++, coeff += 2){
            while(list[temp] == 0)
                temp++;
            diff += coeff * temp;
            list[temp]--;
        }
        printf("%lld\n", diff);

    }
}*/


/*#include <stdio.h>//qsort  AC (1s, 520KB)
#define MAXSIZE 100000
#define BUFSIZE 65536

int list[MAXSIZE];

static inline char readChar(){
    static char buf[BUFSIZE], *p = buf + BUFSIZE, *end = buf + BUFSIZE;
    if(p == end){
        if(end < buf + BUFSIZE)
            return EOF;
        end = buf + fread(buf, 1, BUFSIZE, stdin);
        p = buf;
    }
    return *p++;
}

static inline char readUint(register int *read){
    register char ch;
    while((ch = readChar()) < '0')
        if(ch == EOF)
            return 0;
    *read = ch ^ '0';
    while((ch = readChar()) >= '0')
        *read = (*read << 3) + (*read << 1) + (ch ^ '0');
    return 1;
}

void SWAP(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int getMid(int left, int right){
    SWAP(list + ((left + right) >> 1), list + right);
    int cmpValue = list[right];
    for(int i = left; i < right; i++)
        if(list[i] < cmpValue)
            SWAP(list + left++, list + i);
    SWAP(list + left, list + right);
    return left;
}

void myqsort(int left, int right){
    if(left < right){
        int mid = getMid(left, right);
        myqsort(left, mid - 1);
        myqsort(mid + 1, right);
    }
}

int main(){
    int n;
    while(readUint(&n)){
        for(int i = 0; i < n; i++)
            readUint(list + i);
        myqsort(0, n - 1);
        long long index = 3 - n, diff = (1 - n) * list[0];
        for(int i = 1; i < n; i++, index += 2)
            diff += index * list[i];
        printf("%lld\n", diff);
    }
}*/
