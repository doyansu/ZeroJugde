#include <stdio.h>//	AC (27ms, 2MB)
#define BUFSIZE 2097152
//1048576

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

static inline char readint(int *input){
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

static inline void putint(register int output){
    if(output == 0)putchar('0');
    char buf[13];
    char *p = buf + 11;
    *(p + 1) = '\0';
    if(output < 0){
        putchar('-');
        output = ~output + 1;
    }
    while(output){
        *p-- = '0' ^ (output % 10);
        output /= 10;
    }
    fputs(++p, stdout);
    putchar(' ');
}

int main(){
    int n;
    while(readint(&n)){
        int last = 0, data;
        while(n--){
            readint(&data);
            putint(data - last);
            last = data;
        }
        putchar('\n');
    }
}

/*#include <stdio.h>//	AC (84ms, 108KB)

int main(){
    int n;
    while(scanf("%d", &n) == 1){
        int last = 0, data;
        while(n--){
            scanf("%d", &data);
            printf("%d ", data - last);
            last = data;
        }
        putchar('\n');
    }
}*/
