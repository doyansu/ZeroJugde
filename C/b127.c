#include <stdio.h>
#define SIZE 46

int Fibonacci(int n,int list[SIZE]){
    if(list[n]!=0)return list[n];
    list[n]=Fibonacci(n-1,list)+Fibonacci(n-2,list);
    return list[n];
}


int main(){
    int list[SIZE]={1,1,2,3,5,8};
    int n;
    while(scanf("%d",&n)!=EOF){
        printf("%d\n",Fibonacci(n,list));
    }
}
