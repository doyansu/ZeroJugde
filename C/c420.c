#include <stdio.h>

void print(int n,char ch){
    for(int i=0;i<n;++i)putchar(ch);
}

int main()
{
    int n;
    scanf("%d",&n);
    ++n;
    for(int i=1;i<n;++i){
        print(n-i-1,'_');
        print(2*i-1,'*');
        print(n-i-1,'_');
        putchar('\n');
    }

}
