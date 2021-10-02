#include <stdio.h>//	AC (0.4s, 1.1MB)
#define BUFSIZE 1048576

char out[65536], *p = out, *end = out + 65530;

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

static inline char readUint(register unsigned int *temp){
    register char ch;
    while((ch = readChar()) < '0')
        if(ch == EOF)
            return 0;
    *temp = '0' ^ ch;
    while((ch = readChar()) >= '0')
        *temp = (*temp << 3) + (*temp << 1) + ('0' ^ ch);
    return 1;
}

static inline unsigned int hacker_popcnt(unsigned int  n){
    n -= (n >> 1) & 0x55555555;
    n = (n & 0x33333333) + ((n >> 2) & 0x33333333);
    n = ((n >> 4) + n) & 0x0f0f0f0f;
    n += n >> 8;
    n += n >> 16;
    return n & 0x0000003f;
}

static inline void putAns(unsigned int a){
    if(a == 0){
        *p++ = '0';
        *p++ = '\n';
        return;
    }
    if(p > end){
        *p = '\0';
        fputs(out, stdout);
        p = out;
    }
    char temp[3], *tp = temp + 2;
    *tp-- = '\0';
    while(a){
        *tp-- = '0' ^ (a % 10);
        a /= 10;
    }
    while(*++tp)
        *p++ = *tp;
    *p++ = '\n';
}

int main(){
    unsigned int n;
    while(readUint(&n))
        putAns(hacker_popcnt(n));
    *p = '\0';
    fputs(out, stdout);
    return 0;
}
