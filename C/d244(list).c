#include <stdio.h>
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
    int ans = 0, temp = 0, input;
    while(readUint(&input)){
        temp = ans & (temp ^ input);
        ans = temp | (ans ^ input);
    }
    printf("%d\n", ans);
}

/*#include <stdio.h>
#define BUFSIZE 1048576

int list[BUFSIZE][2]={{-1,-1}};

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
    int i = 0, count = 0;
    while(readUint(&n)){
        for(i = 0; i < count; i++){
            if(list[i][0] == n){
                list[i][1]++;
                break;
            }
        }
        if(i == count){
            count++;
            list[i][0] = n;
            list[i][1] = 1;
        }
    }
    for(i = 0; i < count; i++){
        if(list[i][1] == 2){
            printf("%d", list[i][0]);
            break;
        }
    }
}*/

/*#include <stdio.h>
#define BUFSIZE 1048576

int stone[BUFSIZE], cont[BUFSIZE];

inline char readChar()
{
    static char buffer[BUFSIZE], * now = buffer + BUFSIZE, * end = buffer + BUFSIZE;
    if (now == end)
    {
        if (end < buffer + BUFSIZE)
            return EOF;
        end = (buffer + fread(buffer, 1, BUFSIZE, stdin));
        now = buffer;
    }
    return *now++;
}

inline char readUInt(unsigned int* dst)
{
    register char ch;
    while ((ch = readChar()) < '0')
        if (ch == EOF) return 0;
    *dst = ch ^ '0';
    while ((ch = readChar()) >= '0')
        * dst = (*dst << 3) + (*dst << 1) + (ch ^ '0');
    return 1;
}

int main()
{
    unsigned int tmp, len = 0;
    while (readUInt(&tmp))
    {
        for (int i = 0; i < len; i++)
        {
            if (stone[i] == tmp)
            {
                if (cont[i] == 2)
                    stone[i] = stone[--len], cont[i] = cont[len];
                else
                    cont[i]++;
                goto end;
            }
        }
        stone[len] = tmp, cont[len++] = 1;
    end:;
    }
    printf("%d", stone[0]);
    return 0;
}*/

/*#include <stdio.h>
#define BUKCNT 9887
#define BUKSIZ 1000000
#define BUFSIZE 1048576

typedef struct
{
    unsigned int Key, Value, Next;
} Node;

unsigned int buckets[BUKCNT], freeBuk, lastNode;
Node dict[BUKSIZ];

inline char readChar()
{
    static char buffer[BUFSIZE], * now = buffer + BUFSIZE, * end = buffer + BUFSIZE;
    if (now == end)
    {
        if (end < buffer + BUFSIZE)
            return EOF;
        end = (buffer + fread(buffer, 1, BUFSIZE, stdin));
        now = buffer;
    }
    return *now++;
}

inline char readUInt(unsigned int* dst)
{
    register char ch;
    while ((ch = readChar()) < '0')
        if (ch == EOF) return 0;
    *dst = ch ^ '0';
    while ((ch = readChar()) >= '0')
        * dst = (*dst << 3) + (*dst << 1) + (ch ^ '0');
    return 1;
}

void setNode(int Key)
{
    int targetBuk = Key % 9887, currNode = buckets[targetBuk];
    while (currNode)
    {
        if (dict[currNode].Key == Key)
        {
            if (dict[currNode].Value == 2)
            {
                int del = dict[currNode].Next;
                dict[currNode] = dict[del];
                //
                if (del)
                {
                    dict[del].Next = freeBuk;
                    freeBuk = del;
                }
                return;
            }
            dict[currNode].Value++;
            return;
        }
        currNode = dict[currNode].Next;
    }
    if (freeBuk)
        currNode = freeBuk, freeBuk = dict[freeBuk].Next;
    else
        currNode = ++lastNode;
    dict[currNode].Next = buckets[targetBuk];
    buckets[targetBuk] = currNode;
    dict[currNode].Key = Key;
    dict[currNode].Value = 1;
}

int getAns()
{
    int currNode;
    for (int i = 0; i < BUKCNT; i++)
    {
        currNode = buckets[i];
        while (currNode)
        {
            if (dict[currNode].Value == 2)
                return dict[currNode].Key;
            currNode = dict[currNode].Next;
        }
    }
}

int main()
{
    int tmp;
    while (readUInt(&tmp))
        setNode(tmp);
    printf("%d", getAns());
    return 0;
}*/
