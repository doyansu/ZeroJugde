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
        print(i,'*');
        putchar('\n');
    }

}
