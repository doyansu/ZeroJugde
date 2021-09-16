#include <stdio.h>
#define SIZE 501
int main(){
    int m,n;
    while(scanf("%d%d",&n,&m)!=EOF){
        int list[SIZE][SIZE];
        ++n;
        for(int j=1;j<n;++j){
            list[j][0]=0;
            for(int i=1;i<n;++i){
                int sum;
                scanf("%d",&sum);
                list[j][i]=list[j][i-1]+sum;
            }
        }
        while(m--){
            int x1,x2,y1,y2,result=0;
            scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
            for(int i=x1;i<x2+1;++i){
                result+=list[i][y2]-list[i][y1-1];
            }
            printf("%d\n",result);
        }
    }
}
