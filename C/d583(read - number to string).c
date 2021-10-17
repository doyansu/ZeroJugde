#include <stdio.h>//	AC (3ms, 460KB)
#include <math.h>
#define SIZE 1000000
#define BUFSIZE 1024

char out[SIZE];

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

int main(){
    unsigned int n;
    while(readUint(&n)){
        int index, count = 0, temp;
        char num[6];
        for(int i = 1; i <= n; i++){
            readUint(&index);
            index = 0;
            temp = i;
            while(temp){
                num[index++] = '0' ^ (temp % 10);
                temp /= 10;
            }
            for(temp = count, count += index--; temp < count; temp++, index--)
                out[temp] = num[index];
            out[count++] = ' ';
        }
        out[count] = '\0';
        puts(out);
    }
}

/*#include <stdio.h>//	AC (4ms, 480KB)
#include <math.h>
#define SIZE 1000000
#define BUFSIZE 1024

char out[SIZE];

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

int main(){
    int n;
    while(scanf("%d ", &n) == 1){
        //readUint(&n)
        fgets(out, SIZE, stdin);
        int index, count = 0, temp;
        char num[6];
        for(int i = 1; i <= n; i++){
            index = 0;
            temp = i;
            while(temp){
                num[index++] = '0' ^ (temp % 10);
                temp /= 10;
            }
            for(temp = count, count += index--; temp < count; temp++, index--)
                out[temp] = num[index];
            out[count++] = ' ';
        }
        out[count] = '\0';
        puts(out);
    }
}*/
