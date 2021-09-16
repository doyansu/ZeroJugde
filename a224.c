#include <string.h>
int main(){
    char s[1001];
    while(scanf("%s",s)!=-1){
        int list[26]={0},ch=0;
        for(int i=0;i<26;i++)for(int j=0;j<strlen(s);j++)if(s[j]==65+i || s[j]==97+i)list[i]++;
        for(int i=0;i<26;i++){
            if(list[i]%2!=0)ch++;
            if(ch==2){
                printf("no...\n");
                break;
            }
            if(i==25)printf("yes !\n");
        }
    }
}
