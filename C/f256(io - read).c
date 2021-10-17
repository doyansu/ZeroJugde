#include <stdio.h>//	AC (37ms, 344KB)
#define BUFSIZE 262144

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

static inline char readUint(register int *temp){
    register char ch;
    while((ch = readChar()) < '0')
        if(ch == EOF)
            return 0;
    *temp = ch ^ '0';
    while((ch = readChar()) >= '0')
        *temp = (*temp << 3) + (*temp << 1) + (ch ^ '0');
    return 1;
}

int main(){
    int sum = 0, points = 0, grad, point;
    while(readUint(&grad)){
        readUint(&point);
        sum += grad * point;
        points += point;
    }
    /*while(scanf("%d%d", &grad, &point) == 2){
        sum += grad * point;
        points += point;
    }*/
    sum /= points;
    if(sum > 60){
        puts("Oh wow! You pass it!");
        printf("%d\n", sum);
    }
    else{
        puts("YEEEEEE!!!");
        //printf("%d\n", sum);
    }

}
