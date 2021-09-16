#include<string.h>
#define SIZE 1001
int main(){
    char s[SIZE];
    scanf("%s",s);
    int len=strlen(s);
    for(int i=0;i<len/2;i++){
        if(s[i]!=s[len-i-1]){
            printf("no");
            return 0;
        }
    }
    printf("yes");
}
