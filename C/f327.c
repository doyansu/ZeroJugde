#include <stdio.h>

int turnNum(char* str){
    int ans = 0;
    while(*str)
        ans = ans * 26 + ('@' ^ *str++);
    return ans;
}

int main(){
    char s1[8], s2[8];
    scanf("%s%s", s1, s2);
    printf("%d\n", turnNum(s2) - turnNum(s1) + 1);
    return 0;
}
