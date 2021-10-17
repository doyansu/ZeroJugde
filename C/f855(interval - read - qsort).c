#include <stdio.h>//	AC (2ms, 284KB)
#define SIZE 10000
#define BUFSIZE 2097152

typedef struct interval_s{
    int start, end;
}interval_t;

static inline char readChar(){
    static char buf[BUFSIZE], *temp = buf + BUFSIZE, *end = buf + BUFSIZE;
    if(temp == end){
        if(end < buf + BUFSIZE)
            return EOF;
        end = (buf + fread(buf, 1, BUFSIZE, stdin));
        temp = buf;
    }
    return *temp++;
}

static inline char readUint(int *input){
    register char ch;
    while((ch = readChar()) < '0')
        if(ch == EOF) return 0;
    *input = ch ^ '0';
    while((ch = readChar()) >= '0')
        *input = (*input << 3) + (*input << 1) + (ch ^ '0');
    return 1;
}

static inline void putint(register int output){
    if(output == 0)putchar('0');
    char buf[13];
    char *p = &buf[11];
    if(output < 0){
        putchar('-');
        output *= -1;
    }
    while(output){
        *p-- = '0' ^ (output % 10);
        output /= 10;
    }
    fputs(++p, stdout);
    putchar('\n');
}

int cmp(const interval_t *a,const interval_t *b){
    return a->start != b->start ? a->start < b->start : a->end > b->end;
}

void swap(interval_t *a, interval_t *b){
    interval_t temp = *a;
    *a = *b;
    *b =temp;
}


int getPovit(interval_t *list, int left, int right){
    swap(&list[(left + right) / 2], &list[right]);
    interval_t *cmpPointer = &list[right];
    for(int i = left; i < right; i++)
        if(cmp(&list[i], cmpPointer))
            swap(&list[left++], &list[i]);
    swap(&list[left], &list[right]);
    return left;
}

void myqsort(interval_t *list, int left, int right){
    if(right > left){
        int povit = getPovit(list, left, right);
        myqsort(list, left, povit - 1);
        myqsort(list, povit + 1, right);
    }
}

int main(){
    int n, ans = 0;
    interval_t list[SIZE];
    readUint(&n);
    for(int i = 0; i < n; i++){
        readUint(&list[i].start);
        readUint(&list[i].end);
    }
    myqsort(list, 0, n-1);
    int laste = -1;
    int temp;
    for(int i = 0; i < n; i++){
        //printf("s %d e %d ans %d\n", list[i].start,  list[i].end, ans);
        temp = list[i].end;
        if(list[i].start < laste){
            if(temp < laste)continue;
            ans += temp - laste;
            laste = temp;
        }
        else{
            ans += temp - list[i].start;
            laste = temp;
        }
    }
    putint(ans);
}

/*#include <stdio.h>//AC (68ms, 768KB)
#include <stdlib.h>
#define SIZE 10000
#define BUFSIZE 2097152

typedef struct interval_s{
    int start, end;
}interval_t;

static inline char readChar(){
    static char buf[BUFSIZE], *temp = buf + BUFSIZE, *end = buf + BUFSIZE;
    if(temp == end){
        if(end < buf + BUFSIZE)
            return EOF;
        end = (buf + fread(buf, 1, BUFSIZE, stdin));
        temp = buf;
    }
    return *temp++;
}

static inline char readUint(int *input){
    register char ch;
    while((ch = readChar()) < '0')
        if(ch == EOF) return 0;
    *input = ch ^ '0';
    while((ch = readChar()) >= '0')
        *input = (*input << 3) + (*input << 1) + (ch ^ '0');
    return 1;
}

static inline void putint(register int output){
    if(output == 0)putchar('0');
    char buf[13];
    char *p = &buf[11];
    if(output < 0){
        putchar('-');
        output *= -1;
    }
    while(output){
        *p-- = '0' ^ (output % 10);
        output /= 10;
    }
    fputs(++p, stdout);
    putchar('\n');
}

void swap(interval_t *a, interval_t *b){
    interval_t temp = *a;
    *a = *b;
    *b =temp;
}

int cmp(interval_t *a, interval_t *b){
    return a->start != b->start ? a->start < b->start : a->end > b->end;
}

int getPovit(interval_t *list, int left, int right){
    interval_t *cmpPointer = &list[right];
    for(int i = left; i < right; i++)
        if(cmp(&list[i], cmpPointer))
            swap(&list[left++], &list[i]);
    swap(&list[left], &list[right]);
    return left;
}

void myqsort(interval_t *list, int left, int right){
    if(right > left){
        int povit = getPovit(list, left, right);
        myqsort(list, left, povit - 1);
        myqsort(list, povit + 1, right);
    }
}

int main(){
    int n, ans = 0;
    interval_t list[SIZE];
    readUint(&n);
    for(int i = 0; i < n; i++){
        readUint(&list[i].start);
        readUint(&list[i].end);
    }
    myqsort(list, 0, n-1);
    int laste = -1;
    int temp;
    for(int i = 0; i < n; i++){
        printf("s %d e %d ans %d\n", list[i].start,  list[i].end, ans);
        temp = list[i].end;
        if(list[i].start < laste){
            if(temp < laste)continue;
            ans += temp - laste;
            laste = temp;
        }
        else{
            ans += temp - list[i].start;
            laste = temp;
        }
    }
    putint(ans);

}*/

/*#include <stdio.h>	//AC (3ms, 272KB)
#define SIZE 10000
#define BUFSIZE 2097152

typedef struct interval_s{
    int start, end;
}interval_t;

static inline char readChar(){
    static char buf[BUFSIZE], *temp = buf + BUFSIZE, *end = buf + BUFSIZE;
    if(temp == end){
        if(end < buf + BUFSIZE)
            return EOF;
        end = (buf + fread(buf, 1, BUFSIZE, stdin));
        temp = buf;
    }
    return *temp++;
}

static inline char readUint(int *input){
    register char ch;
    while((ch = readChar()) < '0')
        if(ch == EOF) return 0;
    *input = ch ^ '0';
    while((ch = readChar()) >= '0')
        *input = (*input << 3) + (*input << 1) + (ch ^ '0');
    return 1;
}

static inline void putint(register int output){
    if(output == 0)putchar('0');
    char buf[13];
    char *p = &buf[11];
    if(output < 0){
        putchar('-');
        output *= -1;
    }
    while(output){
        *p-- = '0' ^ (output % 10);
        output /= 10;
    }
    fputs(++p, stdout);
    putchar('\n');
}

void swap(interval_t *a, interval_t *b){
    interval_t temp = *a;
    *a = *b;
    *b =temp;
}

int cmp(interval_t *a, interval_t *b){
    return a->start != b->start ? a->start < b->start : a->end < b->end;
}

int getPovit(interval_t *list, int left, int right){
    interval_t *cmpPointer = &list[right];
    for(int i = left; i < right; i++)
        if(cmp(&list[i], cmpPointer))
            swap(&list[left++], &list[i]);
    swap(&list[left], &list[right]);
    return left;
}

void myqsort(interval_t *list, int left, int right){
    if(right > left){
        int povit = getPovit(list, left, right);
        myqsort(list, left, povit - 1);
        myqsort(list, povit + 1, right);
    }
}

int main(){
    int n, ans = 0;
    interval_t list[SIZE];
    readUint(&n);
    for(int i = 0; i < n; i++){
        readUint(&list[i].start);
        readUint(&list[i].end);
    }
    myqsort(list, 0, n-1);


    int laste = -1;
    for(int i = 0; i < n; i++){
        //printf("s %d e %d ans %d\n", list[i].start,  list[i].end, ans);
        if(list[i].start < laste){
            if(list[i].end < laste)continue;
            ans += list[i].end - laste;
            laste = list[i].end;
        }
        else{
            ans += list[i].end - list[i].start;
            laste = list[i].end;
        }
    }
    putint(ans);

}*/
