#include <stdio.h>
#define SIZE 2097152
#define BUFSIZE 2097152

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

static inline char readUint(unsigned int *input){
    register char ch;
    while((ch = readChar()) < '0')
        if(ch == EOF) return 0;
    *input = ch ^ '0';
    while((ch = readChar()) >= '0')
        *input = (*input << 3) + (*input << 1) + (ch ^ '0');
    return 1;
}

char out[SIZE];

int main(){
    int list[4] = {0};
    int count = 0;
    unsigned int n;
    unsigned int temp;
    readUint(&n);
    while(n--){
        readUint(&temp);
        list[temp]++;
    }
    n = 1;
    while(n < 4){
        out[count++] = '0' ^ n;
        out[count++] = ' ';
        if(--list[n] == 0)n++;
    }
    out[count] = '\0';
    puts(out);
}
