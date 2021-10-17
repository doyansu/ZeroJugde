#include <stdio.h>
#include <string.h>
#define SIZE 101


int main(){
    long long int array[SIZE]={1,1};
    for(int i=2;i<SIZE;++i)array[i]=array[i-1]+array[i-2];
    int n;
    while(scanf("%d",&n)==1)printf("%lld\n",array[n]);
}
