#include <stdio.h>
#define SIZE 1229
#define MOST 10000
/*int isprime(int *list,int index,int n){
    if(n==1)return 0;
    for(int i=0;i<index;i++){
        if(list[i]*list[i]>n)return 1;
        if(n%list[i]==0)return 0;
    }
    return 1;
}*/

int isprime(int *list,int index,int n){
    if(n==1)return 0;
    else if(n==2 || n==3)return 1;
    int m=n%6;
    if(m!=1 && m!=5)return 0;
    for(int i=2;i<index;i++){
        if(list[i]*list[i]>n)return 1;
        if(n%list[i]==0)return 0;
    }
    return 1;
}

int main(){
    int len=1;
    int prime[SIZE]={2};
    for(int i=3;i<MOST;i+=2)if(isprime(prime,len,i))prime[len++]=i;
    int a=0,b=0;
    while(scanf("%d %d",&a,&b)!=EOF){
        int result=0;
        if(a%2==0)a++;
        if(a==1 && b>=2){
            a=3;
            result++;
        }
        for(int j=a;j<=b;j+=2)if(j<=b && isprime(prime,SIZE,j))result++;
        printf("%d\n",result);
    }
}
