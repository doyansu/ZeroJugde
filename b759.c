#include <stdio.h>
#include <string.h>
#define SIZE 2000000
int main(){
    char s[SIZE];
    scanf("%s",s);
    int len=strlen(s);
    for(int i=0;i<len;++i){
        puts(s+i);
        s[len+i]=s[i];
    }
}
