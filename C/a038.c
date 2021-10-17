#include<string.h>
#define SIZE 100
int main(){
    char s[SIZE];
    scanf("%s",s);
    s[SIZE-1]='1';
    for(int i=strlen(s)-1;i>=0;i--){
        if(s[i]!='0')s[SIZE-1]='0';
        if(s[SIZE-1]=='0')printf("%c",s[i]);
    }
    if(s[SIZE-1]=='1')printf("0");
}
