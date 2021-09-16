#include <stdio.h>
#define SIZE 4800
#define MOST 46350

int isprime(int list[SIZE],int index,int n){
    if(n==1)return 0;
    else if(n==2 || n==3)return 1;
    for(int i=1;i<index;i++){
        if(list[i]*list[i]>n)return 1;
        if(n%list[i]==0)return 0;
    }
    return 1;
}

int main(){
    int n;
    int prime[SIZE]={2},len=1;
    for(int i=3;i<MOST;i+=2)if(isprime(prime,len,i))prime[len++]=i;
    while(scanf("%d",&n)!=EOF){
        if(isprime(prime,len,n))printf("質數\n");
        else printf("非質數\n");
    }
    return 0;
}


