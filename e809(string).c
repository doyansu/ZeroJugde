#include <stdio.h>
#define SIZE 500002//5000002

int main(){
    int n,  count[30] = {0};
    char cmp[30], input[SIZE];
    char *p = input;
    fgets(cmp, 30, stdin);
    fgets(input, SIZE, stdin);
    while(*p != '\n')count[*p++ - 'A']++;
    scanf("%d", &n);
    while(n--){
        int index;
        for(scanf("%d", &index), p = cmp; *p != '\n' && index > 0; index -= count[*p++ - 'A']);
        putchar(*(p - 1));
        putchar('\n');
    }
}

/*#include <stdio.h>
#define SIZE 5000002

int main(){
    int n,  count[30];
    char cmp[30], input[SIZE];
    char *p = input;
    fgets(cmp, 30, stdin);
    fgets(input, SIZE, stdin);
    while(*p != '\n')count[(*p++) - 'A']++;
    scanf("%d", &n);
    while(n--){
        int index;
        int i = 0, temp = 0;
        scanf("%d", &index);
        for(; i < 26 && temp < index; temp += count[cmp[i] - 'A'], i++);
        putchar(cmp[i - 1]);
        putchar('\n');
    }
}*/
