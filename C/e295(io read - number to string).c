#include <stdio.h>//	AC (24ms, 2.1MB)
#define BUFSIZE 2097152

char out[100000];
int count = 0;

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

static inline char readUint(register unsigned int *input){
    register char ch;
    while((ch = readChar()) < '0')
        if(ch == EOF) return 0;
    *input = '0' ^ ch;
    while((ch = readChar()) >= '0')
        *input = (*input << 3) + (*input << 1) + ('0' ^ ch);
    return 1;
}

int main(){
    char ch[13];
    unsigned int a, b, temp;
    while(readUint(&a)){
        readUint(&b);
        temp = a + b;
        int len = 0;
        while(temp){
            ch[len++] = '0' | (temp%10);
            temp /= 10;
        }
        for(temp = count , count += len--; len >= 0; out[temp++] = ch[len--]);
        out[count++] = '\n';
        if(count > 99000){
            out[count] = '\0';
            fputs(out, stdout);
            count = 0;
        }
    }
    out[count] = '\0';
    fputs(out, stdout);
}
