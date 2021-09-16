#include <stdio.h>
#include <string.h>
#define SIZE 10001


int main(){
    int array[SIZE]={1,1};
    for(int i=2;i<SIZE;++i)array[i]=(array[i-1]+array[i-2])%1000000007;
    int n;
    while(scanf("%d",&n)==1)printf("%d\n",array[n]);
}
