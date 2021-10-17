#include <stdio.h>
#define SIZE 81

long long int Fibonacci(int n,long long int list[SIZE]){
    if(list[n]!=0)return list[n];
    list[n]=Fibonacci(n-1,list)+Fibonacci(n-2,list);
    return list[n];
}


int main(){
    long long int list[SIZE]={1,1,2,3,5,8,13,21,34,55,89,144,233,377,610};
    int n;
    while(scanf("%d",&n)){
        if(n==0)break;
        printf("%lld\n",Fibonacci(n,list));
    }
}
