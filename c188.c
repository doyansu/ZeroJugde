#include <stdio.h>
#define SIZE 201

int main(){
    int n;
    long long int list[SIZE]={1};
    for(int i=1;i<SIZE;++i)for(int j=i;j<SIZE;++j)list[j]+=list[j-i];
    while(scanf("%d",&n)!=EOF){
        printf("%lld\n",list[n]);
    }
}
