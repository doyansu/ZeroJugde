/*
sscanf 可從字串中讀取
第一個參數 (char *) 為要讀取的字串開頭指標 
第二個參數 "%d %s ... " 為讀取格式與 scanf 相同
第三個參數 (void *) 為讀取結果要存在的變數 (該變數之位置)

先讀取整行
再利用 sscanf (用一個 (int index) 來控制開頭位置) 讀取運算子、運算元進行運算
*/

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
