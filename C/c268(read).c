#include <stdio.h>//AC (33ms, 1.1MB)
#include <stdlib.h>
#define BUFSIZE 1048576

int cmp(const int *a, const int *b){
    return *a - *b;
}

int main(){
    int t, array[46];
    char buf[BUFSIZE];
    scanf("%d", &t);
    while(t--){
        int n;
        scanf("%d ", &n);
        if(n > 45){
            puts("YES");
            do{
                buf[BUFSIZE - 2] = EOF;
            }while(fgets(buf, BUFSIZE, stdin)[BUFSIZE - 2] != EOF);
        }
        else {
            int i;
            for(i = 0; i < n; i++)
                scanf("%d", array + i);
            qsort(array, n, sizeof(int), cmp);
            for(i = 0; i < n - 2; i++)
                if(array[i] + array[i + 1] > array[i + 2])
                    break;
            if(i == n - 2 || n < 2)
                puts("NO");
            else
                puts("YES");
        }
    }
    return 0;
}

/*#include <stdio.h>//	AC (83ms, 1.1MB)
#include <stdlib.h>
#define BUFSIZE 1048576

static inline char readChar(){
    static char buf[BUFSIZE], *temp = buf + BUFSIZE, *end = buf + BUFSIZE;
    if(temp == end){
        if(end < buf + BUFSIZE)
            return EOF;
        end = buf + fread(buf, 1, BUFSIZE, stdin);
        temp = buf;
    }
    return *temp++;
}

static inline char readUint(register int *input){
    register char ch;
    while((ch = readChar()) < '0' && ch != '-')
        if(ch == EOF) return 0;
    *input = ch ^ '0';
    while((ch = readChar()) >= '0')
        *input = (*input << 3) + (*input << 1) + (ch ^ '0');
    return 1;
}

int cmp(const int *a, const int *b){
    return *a - *b;
}

int main(){
    int t, array[46];
    readUint(&t);
    while(t--){
        int n;
        readUint(&n);
        if(n > 45){
            puts("YES");
            while(readChar() != '\n');
        }
        else {
            int i;
            for(i = 0; i < n; i++)
                readUint(array + i);
            qsort(array, n, sizeof(int), cmp);
            for(i = 0; i < n - 2; i++)
                if(array[i] + array[i + 1] > array[i + 2])
                    break;
            if(i == n - 2 || n < 2)
                puts("NO");
            else
                puts("YES");
        }
    }
    return 0;
}
*/
