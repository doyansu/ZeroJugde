#include <stdio.h>

unsigned long long int getk(int a,int b){
    if(a>b){
        return 2*getk(a-b,b);
    }
    else if(a<b){
        return getk(b,a)+1;
    }
    return 1;
}

int main(){
    int a,b;
    while(scanf("%d%d",&a,&b)!=EOF){
        printf("%lld\n",getk(a,b));
    }
}
