#include <stdio.h>//AC 10ms
#include <string.h>
#define SIZE 10001
#define MAXINF 0x7fffffff

int isTagetWord(char *s1,char *s2,int size){
    for(;size>0;s1++,s2++,size--){
        if(*s1!=*s2)return 0;
    }
    return 1;
}

char* mysplit(char *str, char *sp){
    static char* p = NULL;
    if(str != NULL)p = str;
    else str = p;
    while(*p != '\0'){
        if(isTagetWord(p, sp, strlen(sp)))break;
        p++;
    }
    if(*p == '\0'){
        p=str;
        return NULL;
    }
    *p = '\0';
    p += strlen(sp);
    return str;
}

int main(){
    int coin[9]={1, 2, 4, 10, 20, 40, 100, 200, 400};
    long long int array[SIZE];
    for(int i = 0; i < SIZE; i++)
        array[i] = 1;
    for(int i = 0; i < 9; i++)
        for(int j = coin[i]; j < SIZE ;j++)
            array[j] += array[j-coin[i]];
    char input[SIZE];
    while(fgets(input, SIZE+1, stdin) != NULL){
        if(*input == '0')break;
        input[strlen(input)-1]=' ';
        int n = 0;
        char *p = mysplit(input, " ");
        while(p != NULL){
            int temp = 0;
            while(*p != '\0'){
                temp = (temp << 3) + (temp << 1) + (*p ^ '0');
                p++;
            }
            n += temp;
            p = mysplit(NULL, " ");
        }
        //printf("%d\n", n);
        printf("%lld\n", array[n/5] - 1);
    }
}

/*#include <stdio.h>//AC 16ms
#include <string.h>
#define SIZE 10001

int main(){
    int coin[9]={1, 2, 4, 10, 20, 40, 100, 200, 400};
    long long int array[SIZE];
    for(int i = 0; i < SIZE; i++)
        array[i] = 1;
    for(int i = 0; i < 9; i++)
        for(int j = coin[i]; j < SIZE ;j++)
            array[j] += array[j-coin[i]];
    char ch;
    int input;
    while(scanf("%d", &input) != EOF && input){
        int sum = input;
        if(getchar()!='\n')
            while(scanf("%d%c", &input, &ch)){
                sum += input;
                if(ch == '\n')break;
            }
        printf("%lld\n", array[sum/5] - 1);
    }
}*/

/*#include <stdio.h>
#define MAX 10001

const int money[] = { 1, 2, 4, 10, 20, 40, 100, 200, 400 };
unsigned long long list[MAX];
int n, tmp;
char input[1000], * st;

inline char* getUInt(unsigned int* dst, char src[])
{
    while (*src < '0')
        if (!*src++) return NULL;
    *dst = *src ^ '0';
    while (*++src >= '0')
        * dst = (*dst << 3) + (*dst << 1) + (*src ^ '0');
    return src;
}

int main()
{
    for (int i = 0; i < MAX; i++)
        list[i] = 1;
    for (int i = 0; i < 9; i++)
    {
        for (int j = money[i]; j < MAX; j++)
            list[j] += list[j - money[i]];
    }
    while (gets(input) && input[0] - '0')
    {
        n = 0, st = input;
        while (st = getUInt(&tmp, st))
            n += tmp;
        printf("%llu\n", list[n / 5] - 1);
    }
    return 0;
}
*/
