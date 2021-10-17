#include <stdio.h>

int main()
{
    int n,m,index;
    char oper;
    while(scanf("%d %c %d",&n,&oper,&m)!=EOF){
        int ans;
        switch(oper){
        case '+':
            ans=n+m;
            break;
        case '-':
            ans=n-m;
            break;
        case '*':
            ans=n*m;
            break;
        case '/':
            ans=n/m;
            break;

        }
        printf("%d",ans);
        putchar('\n');
    }
}
