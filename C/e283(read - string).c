#include <stdio.h>//	AC (8ms, 196KB)
#include <string.h>
#define BUFSIZE 65536

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
    *input = ch ^ '0';
    while((ch = readChar()) >= '0')
        *input = (*input << 3) + (*input << 1) + (ch ^ '0');
    return 1;
}

static inline void solve(){
    unsigned int n;
    char output[BUFSIZE], *p = output, *end = output + BUFSIZE - 10;
    while(readUint(&n)){
        while(n--){
            if(readChar() == '1'){
                readChar();
                if(readChar() == '1'){
                    readChar();
                    readChar();
                    readChar();
                    if(readChar() == '1')*p++ = 'D';
                    else *p++ = 'F';
                }
                else {
                    *p++ = 'E';
                    readChar();
                    readChar();
                    readChar();
                    readChar();
                }
            }
            else {
                readChar();
                if(readChar() == '1'){
                    readChar();
                    if(readChar() == '1')*p++ = 'B';
                    else *p++ = 'A';
                }
                else {
                    *p++ = 'C';
                    readChar();
                    readChar();
                }
                readChar();
                readChar();
            }
            if(p > end){
                *p = '\0';
                fputs(output, stdout);
                p = output;
            }
            readChar();
        }
        *p++ = '\n';
    }
    *p = '\0';
    fputs(output, stdout);
}

int main(){
    solve();
    return 0;
}

/*#include <stdio.h>// AC (72ms, 128KB)
#include <string.h>
#define SIZE 10
#define BUFSIZE 65536

static inline void solve(){
    unsigned int n;
    char input[SIZE], output[BUFSIZE], *p = output, *end = output + BUFSIZE - 10;
    while(scanf("%u", &n) == 1){
        getchar();
        while(n--){
            fgets(input, SIZE, stdin);
            if(*input == '1'){
                if(*(input + 2) == '1'){
                    if(*(input + 6) == '1')*p++ = 'D';
                    else *p++ = 'F';
                }
                else *p++ = 'E';
            }
            else {
                if(*(input + 2) == '1'){
                    if(*(input + 4) == '1')*p++ = 'B';
                    else *p++ = 'A';
                }
                else *p++ = 'C';
            }
            if(p > end){
                *p = '\0';
                fputs(output, stdout);
                p = output;
            }
        }
        *p++ = '\n';
    }
    *p = '\0';
    fputs(output, stdout);
}

int main(){
    solve();
    return 0;
}*/

/*#include <stdio.h>//	AC (82ms, 128KB)
#include <string.h>
#define SIZE 10
#define BUFSIZE 65536

static inline void solve(){
    unsigned int n, count = 0;
    char input[SIZE], output[BUFSIZE];
    while(scanf("%u", &n) == 1){
        getchar();
        while(n--){
            fgets(input, SIZE, stdin);
            if(*input == '1'){
                if(*(input + 2) == '1'){
                    if(*(input + 6) == '1')output[count++] = 'D';
                    else output[count++] = 'F';
                }
                else output[count++] = 'E';
            }
            else {
                if(*(input + 2) == '1'){
                    if(*(input + 4) == '1')output[count++] = 'B';
                    else output[count++] = 'A';
                }
                else output[count++] = 'C';
            }
            if(count > 65520){
                output[count] = '\0';
                fputs(output, stdout);
                count = 0;
            }
        }
        output[count++] = '\n';
    }
    output[count] = '\0';
    fputs(output, stdout);
}

int main(){
    solve();
    return 0;
}*/
