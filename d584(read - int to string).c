#include <stdio.h>
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
    unsigned int type, level;
    int count = 0;
    while(readUint(&type)){
        readUint(&level);
        int index = 0, temp = 0;
        char num[6];
        if(type == 0)out[count++] = '0';
        else{
            if(level > 119)temp = 6;
            else if(level > 69)temp = 3;
            else if(level > 29)temp = 2;
            else if(level > 9)temp = 1;
            else temp = 0;
            if(type == 2){
                if(level > 9)temp += 6;
                else if(level == 9)temp = 4;
                else if(level == 8)temp = 1;
            }
            if(level > 9){
                level -= 10;
                temp += (level << 1) + level;
            }
            while(temp){
                num[index++] = '0' ^ (temp % 10);
                temp /= 10;
            }
            for(temp = count, count += index--; temp < count; temp++, index--)
                out[temp] = num[index];
        }
        out[count++] = '\n';
    }
    out[count] = '\0';
    puts(out);
}
