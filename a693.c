#include <stdio.h>
#define SIZE 100001
int main(){
    int m,n;
    while(scanf("%d%d",&n,&m)!=EOF){
        int list[SIZE];
        list[0]=0;
        ++n;
        for(int i=1;i<n;++i){
            int sum;
            scanf("%d",&sum);
            list[i]=list[i-1]+sum;
        }
        while(m--){
            int l,r;
            scanf("%d%d",&l,&r);
            printf("%d\n",list[r]-list[l-1]);
        }
    }
}
