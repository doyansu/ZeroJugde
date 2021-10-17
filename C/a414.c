#include <stdio.h>

int main(){
    int n;
    while(scanf("%d",&n)){
        int result=0;
        if(n==0)break;
        while(n){
            if(n%2)result++;
            else break;
            n/=2;
        }
        printf("%d\n",result);
    }
}
