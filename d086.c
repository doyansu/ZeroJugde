#include <stdio.h>
#include <string.h>
#define SIZE 202

int main()
{
    char str[SIZE];
    while(scanf("%s",str)!=EOF){
        if((*str=='0') && (strlen(str)==1))break;
        char *p=str;
        int sum=0;
        while(*p!='\0'){
            if(*p>64 && *p<91){
                sum+=*p-'@';
            }
            else if(*p>96 && *p<123){
                sum+=*p-'a';
                ++sum;
            }
            else{
                sum=-1;
                break;
            }
            ++p;
        }
        if(sum>=0)printf("%d\n",sum);
        else puts("Fail");
    }
}
