#include <stdio.h>//	AC (0.1s, 2.1MB)
#define BUFSIZE 1048576

char output[BUFSIZE];

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

static inline char readint(register int *input){
    register char ch;
    int flag = 1;
    while((ch = readChar()) < '0' && ch != '-')
        if(ch == EOF) return 0;
    if(ch == '-'){
        ch = readChar();
        flag = -1;
    }
    *input = ch ^ '0';
    while((ch = readChar()) >= '0')
        *input = (*input << 3) + (*input << 1) + (ch ^ '0');
    *input *= flag;
    return 1;
}

int main(){
    int n;
    register char *p = output;
    char *end = p + BUFSIZE;
    while(readint(&n)){
        int count = 0;
        if(n && (!(n&(n - 1)))){
            *p++ = 'Y';
            *p++ = 'e';
            *p++ = 's';
            *p++ = '\n';
        }
        else {
            *p++ = 'N';
            *p++ = 'o';
            *p++ = '\n';
        }
        if(p > end){
            *p = '\0';
            fputs(output ,stdout);
            p = output;
        }
    }
    *p = '\0';
    fputs(output, stdout);
}

/*#include <stdio.h>
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

static inline char readint(register int *input){
    register char ch;
    int flag = 1;
    while((ch = readChar()) < '0' && ch != '-')
        if(ch == EOF) return 0;
    if(ch == '-'){
        ch = readChar();
        flag = -1;
    }
    *input = ch ^ '0';
    while((ch = readChar()) >= '0')
        *input = (*input << 3) + (*input << 1) + (ch ^ '0');
    *input *= flag;
    return 1;
}

int main(){//	AC (0.4s, 2.1MB)
    int n;
    while(readint(&n)){
        int count = 0;
        if(n && (!(n&(n - 1))))puts("Yes");
        else puts("No");
    }
}*/

/*int main(){//	AC (0.5s, 2.1MB)
    int n;
    while(readint(&n)){
        int count = 0;
        while(n){
            if(n&1)count++;
            if(count == 2)break;
            n >>= 1;
        }
        if(count == 1)puts("Yes");
        else puts("No");
    }
}*/
