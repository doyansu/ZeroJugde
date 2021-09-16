#include <stdio.h>
#include <string.h>
#define SIZE 20000

int main()
{
    char str[SIZE];
    while(fgets(str,SIZE,stdin)!=NULL){
        int sum=0,index=0;
        char tempstr[SIZE];
        while(str[index]==' ')++index;
        while(sscanf(&str[index],"%s",tempstr)!=EOF){
            int temp=0;
            char *p=tempstr;
            while(*p!='\0'){
                if(*p>'9' || *p<'0'){
                    temp=0;
                    break;
                }
                temp=(temp<<3)+(temp<<1)+*p-'0';
                ++p;
            }
            sum+=temp;
            index+=strlen(tempstr);
            while(str[index]==' ')++index;
        }
        printf("%d\n",sum);
    }
}
