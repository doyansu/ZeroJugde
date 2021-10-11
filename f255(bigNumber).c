#include <stdio.h>//#0: 1% AC (1.3s, 13.4MB) #1: 99% TLE (0.8s)
#include <string.h>
#define MAXINPUT 10001
#define MOD 1000000000000000000
#define NUMDIGIT 18
#define BIGSIZE 170
#define BUFSIZE 1048576


typedef struct bigNum_s{
    int len;
    unsigned long long int num[BIGSIZE];
}bigNum_t;

bigNum_t list[MAXINPUT], tmp, *t = list;
char buf[NUMDIGIT + 1], out[65536], *op = out, *end = out + 62436;

static inline char readChar(){
    static char buf[BUFSIZE], *temp = buf + BUFSIZE, *end = buf + BUFSIZE;
    if(temp == end){
        if(end < buf + BUFSIZE)
            return EOF;
        end = buf + fread(buf, 1, BUFSIZE, stdin);
        temp = buf;
    }
    return *temp++;
}

static inline char readUint(register int *input){
    register char ch;
    while((ch = readChar()) < '0')
        if(ch == EOF) return 0;
    *input = ch ^ '0';
    while((ch = readChar()) >= '0')
        *input = (*input << 3) + (*input << 1) + (ch ^ '0');
    return 1;
}

static inline void initial(){
    buf[NUMDIGIT] = '\0';
    memset(list, 0, sizeof(bigNum_t));
    t = list;
    t->len = 1;
    t->num[0] = 1;
    t = &tmp;
    tmp = *list;
    unsigned long long int carry;
    for(int x = 1; x < MAXINPUT; x++){
        for(int i = 0; i < t->len; i++)
            t->num[i] <<= 1;
        for(int i = 0; i < t->len; i++){
            if(t->num[i] >= MOD){
                carry = t->num[i] / MOD;
                t->num[i] -= carry * MOD;
                t->num[i + 1] += carry;
                if(i + 1 == t->len)
                    t->len++;
            }
        }
        list[x] = tmp;
    }
}

static inline void putLLUint(register unsigned long long int src){
    register char *p = buf + NUMDIGIT - 1;
    while(src){
        *p-- = '0' ^ (src % 10);
        src /= 10;
    }
    while(*++p)
        *op++ = *p;
}

static inline void putDLLUint(register unsigned long long int src){
    register unsigned long long int div = MOD / 10;
    for(; div; div /= 10){
        *op++ = '0' | (src / div);
        src %= div;
    }
}

int main() {
    initial();
    int power;
    while(readUint(&power), power){
        t = list + power;
        int len = t->len;
        putLLUint(t->num[--len]);
        while(len)
            putDLLUint(t->num[--len]);
        *op++ = '\n';
        if(op > end){
            *op = '\0';
            fputs(out, stdout);
            op = out;
        }
    }
    *op = '\0';
    fputs(out, stdout);
    return 0;
}

/*

#include <stdio.h>
#include <string.h>
#define MOD 1000000000000000000
#define BIGSIZE 170
#define MAXINPUT 10001
#define BUFSIZE 1048576

typedef struct bigNum_s{
    int len;
    unsigned long long int num[BIGSIZE];
}bigNum_t;

bigNum_t list[MAXINPUT], tmp, *t = list;
char buf[19], out[65536], *op = out, *end = out + 65436;

static inline char readChar(){
    static char buf[BUFSIZE], *temp = buf + BUFSIZE, *end = buf + BUFSIZE;
    if(temp == end){
        if(end < buf + BUFSIZE)
            return EOF;
        end = buf + fread(buf, 1, BUFSIZE, stdin);
        temp = buf;
    }
    return *temp++;
}

static inline char readUint(register int *input){
    register char ch;
    while((ch = readChar()) < '0')
        if(ch == EOF) return 0;
    *input = ch ^ '0';
    while((ch = readChar()) >= '0')
        *input = (*input << 3) + (*input << 1) + (ch ^ '0');
    return 1;
}

static inline void initial(){
    buf[18] = '\0';
    memset(list, 0, sizeof(bigNum_t));
    t = list;
    t->len = 1;
    t->num[0] = 1;
    t = &tmp;
    tmp = *list;
    unsigned long long int carry;
    for(int x = 1; x < MAXINPUT; x++){
        for(int i = 0; i < t->len; i++)
            t->num[i] <<= 1;
        for(int i = 0; i < t->len; i++){
            if(t->num[i] >= MOD){
                carry = t->num[i] / MOD;
                t->num[i] -= carry * MOD;
                t->num[i + 1] += carry;
                if(i + 1 == t->len)
                    t->len++;
            }
        }
        list[x] = tmp;
    }
}

static inline void putLLUint(register unsigned long long int src){
    register char *p = buf + 17;
    while(src){
        *p-- = '0' ^ (src % 10);
        src /= 10;
    }
    while(*++p)
        *op++ = *p;
}

static inline void put18LLUint(register unsigned long long int src){
    register unsigned long long int div = MOD / 10;
    for(; div; div /= 10){
        *op++ = '0' ^ (src / div);
        src %= div;
    }
    if(op > end){
        *op = '\0';
        fputs(out, stdout);
        op = out;
    }
}

int main() {
    initial();
    int power;
    while(readUint(&power) && power){
        t = list + power;
        int len = t->len;
        putLLUint(t->num[--len]);
        while(len)
            put18LLUint(t->num[--len]);
        *op++ = '\n';
    }
    *op = '\0';
    fputs(out, stdout);
    return 0;
}*/

/*#include <stdio.h>
#include <string.h>
#define MOD 1000000000000000000
#define BIGSIZE 170
#define MAXINPUT 10001

typedef struct bigNum_s{
    int len;
    unsigned long long int num[BIGSIZE];
}bigNum_t;

bigNum_t list[MAXINPUT], tmp, *t = list;
char buf[19];

static inline void initial(){
    buf[18] = '\0';
    memset(list, 0, sizeof(bigNum_t));
    t = list;
    t->len = 1;
    t->num[0] = 1;
    t = &tmp;
    tmp = *list;
    unsigned long long int carry;
    for(int x = 1; x < MAXINPUT; x++){
        for(int i = 0; i < t->len; i++)
            t->num[i] <<= 1;
        for(int i = 0; i < t->len; i++){
            if(t->num[i] >= MOD){
                carry = t->num[i] / MOD;
                t->num[i] -= carry * MOD;
                t->num[i + 1] += carry;
                if(i + 1 == t->len)
                    t->len++;
            }
        }
        list[x] = tmp;
    }
}

static inline void put18LLUint(register unsigned long long int src){
    register char *p = buf;
    register unsigned long long int div = MOD / 10;
    for(; div; div /= 10){
        *p++ = '0' ^ (src / div);
        src %= div;
    }
    fputs(buf, stdout);
}

int main() {
    initial();
    int power;
    while(scanf("%d", &power) == 1 && power){
        t = list + power;
        int len = t->len;
        printf("%llu", t->num[--len]);
        while(len)
            put18LLUint(t->num[--len]);
        putchar('\n');
    }
    return 0;
}*/

/*
#include <stdio.h>
#include <string.h>
#define MOD 1000000000000000000
#define BIGSIZE 170
#define MAXINPUT 10001

typedef struct bigNum_s{
    int len;
    unsigned long long int num[BIGSIZE];
}bigNum_t;

bigNum_t list[MAXINPUT], tmp, *t = list;

static inline void initial(){
    memset(list, 0, sizeof(bigNum_t));
    t = list;
    t->len = 1;
    t->num[0] = 1;
    t = &tmp;
    tmp = *list;
    unsigned long long int carry;
    for(int x = 1; x < MAXINPUT; x++){
        for(int i = 0; i < t->len; i++)
            t->num[i] <<= 1;
        for(int i = 0; i < t->len; i++){
            if(t->num[i] >= MOD){
                carry = t->num[i] / MOD;
                t->num[i] -= carry * MOD;
                t->num[i + 1] += carry;
                if(i + 1 == t->len)
                    t->len++;
            }
        }
        list[x] = tmp;
    }
}

int main() {
    initial();
    int power;
    while(scanf("%d", &power) == 1 && power){
        t = list + power;
        int len = t->len;
        printf("%llu", t->num[--len]);
        while(len)
            printf("%018llu", t->num[--len]);
        putchar('\n');
    }
    return 0;
}
*/

/*
#include <stdio.h>// pow tle
#include <string.h>
#define MOD 100000000
#define BIGSIZE 385

typedef struct bigNum_s{
    int len;
    unsigned long long int num[BIGSIZE];
}bigNum_t;

bigNum_t tmp, *t = &tmp;

static inline bigNum_t bigMul(bigNum_t a, bigNum_t b){
    memset(t, 0, sizeof(bigNum_t));
    t->len = a.len + b.len - 1;
    unsigned long long carry;
    for(int i = 0; i < a.len; i++){
        for(int j = 0; j < b.len; j++){
            t->num[i + j] += a.num[i] * b.num[j];
        }
    }

    for(int i = 0; i < t->len; i++)
        if(t->num[i] >= MOD){
            carry = t->num[i] / MOD;
            t->num[i] -= carry * MOD;
            t->num[i + 1] += carry;
            if(i + 1 == t->len)
                t->len++;
        }

    return tmp;
}

static inline void fastPower(int power){
    bigNum_t ans, base;
    base.num[0] = 2;
    base.len = 1;
    ans.num[0] = 1;
    ans.len = 1;

    for(;; power >>= 1){
        if(power & 1){
            ans = bigMul(ans, base);
            if(power == 1)
                break;
        }
        base = bigMul(base, base);
    }

    int len = ans.len;
    printf("%llu", ans.num[--len]);
    while(len)
        printf("%08llu", ans.num[--len]);
    putchar('\n');
}

int main() {
    int power;
    while(scanf("%d", &power) == 1 && power){
        fastPower(power);
    }
    return 0;
}
*/
