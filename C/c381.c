#include <stdio.h>
#include <string.h>
#define SIZE 60000010

char s[SIZE];

int main()
{
    int n,m,index;
    char *p;
    while(scanf("%d%d",&n,&m)==2 && n+m){
        getchar();
        p=s;
        /*while(n--){
            gets(p);
            p+=strlen(p);
        }*/
        while(n--){
            fgets(p,102,stdin);
            p+=strlen(p);
            --p;
            *p='\0';
        }
        while(m--){
            scanf("%d",&index);
            --index;
            putchar(s[index]);
        }
        putchar('\n');
    }
}
