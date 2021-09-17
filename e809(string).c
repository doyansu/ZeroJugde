/*
利用 counting sort

cmp 紀錄排序順序 (cmp[0]為最先, cmp[1]為第2 ...)
input 儲存輸入字串
count 儲存字母出現次數 (count[0] = 'A'出現次數, count[1] = 'B'出現次數 ...)
p 為指標方便尋訪字元陣列

輸入字串，
然後 尋訪input 字母每出現對應的 count[n] 就 + 1 計算次數，
然後 輸入目標位置 index 後用迴圈從 cmp[0](最先) 開始 index 減掉 cmp[n] 的出現次數(count[cmp[n] - 'A'])
直到 index < 0 代表超過 index
輸出前一個字母 *(cmp[n] - 1) */

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
