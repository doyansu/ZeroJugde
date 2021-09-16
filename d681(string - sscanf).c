#include <stdio.h>//	AC (30ms, 88KB)
#include <string.h>

void OR(char *res, char *sour){
    printf("||");
    for(int i = 0; i < 5; i++){
        res[i] |= sour[i];
    }
}

void AND(char *res, char *sour){
    printf("&&");
    for(int i = 0; i < 5; i++){
        res[i] &= sour[i];
    }
}

int main(){
    char input[10000], ans[6], temp[6], oper[4];
    while(gets(input) != NULL){
        int index = 0;
        sscanf(&input[index], "%s", ans);
        printf("%s", ans);
        index += 6;
        while(sscanf(&input[index], "%s %s ", oper, temp) == 2){
            void (*func)(char *, char *);
            if(strcmp(oper, "or") == 0)func = OR;
            else func = AND;
            func(ans, temp);
            printf("%s", temp);
            index += strlen(oper) + 7;
        }
        printf(" = ");
        printf("%s", ans);
        putchar('\n');
    }
}

/*#include <stdio.h>//	AC (16ms, 596KB)
#include <string.h>
#define SIZE 1000000

char out[SIZE];
int count = 0;

void OR(char *res, char *sour){
    out[count++] = '|';
    out[count++] = '|';
    for(int i = 0; i < 5; i++)
        res[i] |= sour[i];
}

void AND(char *res, char *sour){
    out[count++] = '&';
    out[count++] = '&';
    for(int i = 0; i < 5; i++)
        res[i] &= sour[i];
}

int main(){
    char input[SIZE], ans[6], temp[6], oper[4];
    while(fgets(input, SIZE, stdin) != NULL){
        int index = 0;
        sscanf(&input[index], "%s", ans);
        for(int i = 0; i < 5; i++)out[count++] = ans[i];
        index += 6;
        while(sscanf(&input[index], "%s %s ", oper, temp) == 2){
            void (*func)(char *, char *);
            if(strcmp(oper, "or") == 0)func = OR;
            else func = AND;
            func(ans, temp);
            for(int i = 0; i < 5; i++)out[count++] = temp[i];
            index += strlen(oper) + 7;
        }
        out[count++] = ' ';
        out[count++] = '=';
        out[count++] = ' ';
        for(int i = 0; i < 5; i++)out[count++] = ans[i];
        out[count++] = '\n';
    }
    out[count] = '\0';
    puts(out);
}*/
