#include <stdio.h>
#define FUNCTION(n) (n*(n-1))/2+1
int main(){
    int n;
    while(scanf("%d",&n)!=EOF){
        printf("%d\n",FUNCTION(n));
    }
}
