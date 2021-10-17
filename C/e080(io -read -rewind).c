/*
用 fread 輸入進 buf 暫存 readChar() 拿取一個字元
先跳過第1個輸入的整數(即到第一個空白)
然後開始將字元一個一個讀將第2個輸入的整數存到輸出陣列(out) outp > end 就先輸出
然後利用 rewind(stdin) 將 stdin 回到開頭
再重複讀取到 ' ' 結束最後輸出
*/

#include <stdio.h>
#define BUFSIZE 65536

static inline char readChar(char jug){
    static char buf[BUFSIZE], *temp = buf + BUFSIZE, *end = buf + BUFSIZE;
    if(temp == end || jug == '1'){
        if(end < buf + BUFSIZE && jug != '1')
            return EOF;
        if(jug == '1')
            rewind(stdin);
        end = (buf + fread(buf, 1, BUFSIZE, stdin));
        temp = buf;
    }
    return *temp++;
}

static inline void solve(){
    char out[BUFSIZE], *outp = out, *end = out + BUFSIZE;
    while(readChar('0') != ' ');
    while((*outp = readChar('0')) != EOF){
        if(outp++ > end){
            *outp = '\0';
            fputs(out, stdout);
            outp = out;
        }
    }
    *outp++ = ' ';
    *outp++ = readChar('1');
    while((*outp = readChar('0')) != ' '){
        if(outp++ > end){
            *outp = '\0';
            fputs(out, stdout);
            outp = out;
        }
    }
    *outp = '\0';
    fputs(out, stdout);
}

int main(){
    solve();
    return 0;
}

/*#include <stdio.h>
#define BUFSIZE 1048576

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

static inline void solve(){
    char str[BUFSIZE], *p = str, *end = str + BUFSIZE;
    while(fgetc(stdin) != ' ');
    while((*p = fgetc(stdin)) != EOF){
        if(p++ > end){
            *p = '\0';
            fputs(str, stdout);
            p = str;
        }
    }
    *p++ = ' ';
    rewind(stdin);
    while((*p = fgetc(stdin)) != ' '){
        if(p++ > end){
            *p = '\0';
            fputs(str, stdout);
            p = str;
        }
    }
    *p = '\0';
    fputs(str, stdout);
}

int main(){
    solve();
    return 0;
}*/


/*#include <stdio.h>
#define BUFSIZE 1048576

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

static inline void solve(){
    char str[SIZE], *p = str, *end = str + SIZE;
    while(fgetc(stdin) != ' ');
    while((*p = fgetc(stdin)) != EOF){
        if(p++ > end){
            *p = '\0';
            fputs(str, stdout);
            p = str;
        }
    }
    *p++ = ' ';
    rewind(stdin);
    while((*p = fgetc(stdin)) != ' '){
        if(p++ > end){
            *p = '\0';
            fputs(str, stdout);
            p = str;
        }
    }
    *p = '\0';
    fputs(str, stdout);
}

int main(){
    solve();
    return 0;
}

*/
