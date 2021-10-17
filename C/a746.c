#include <stdio.h>
#include <stdlib.h>

int main(){
    int m,n;
    while(scanf("%d%d",&n,&m)!=EOF){
        char list[n*n];
        int lastx=-1,lasty=-1;
        while(m--){
            int x,y;
            scanf("%d%d",&x,&y);
            --x;
            --y;
            if(lastx>=0 || lasty>=0){
                if(x==lastx){
                    if(y-lasty>0)for(int i=lasty;i<=y;++i)list[n*x+i]='*';
                    else for(int i=y;i<=lasty;++i)list[n*x+i]='*';
                }
                else if(y==lasty){
                    if(x-lastx>0)for(int i=lastx;i<=x;++i)list[n*i+y]='*';
                    else for(int i=x;i<=lastx;++i)list[n*i+y]='*';
                }
            }
            lastx=x;
            lasty=y;
        }
        for(int i=0;i<n+2;++i)printf("-");
        printf("\n");
        for(int x=0;x<n;++x){
            printf("|");
            for(int y=0;y<n;++y){
                if(list[x*n+y]!='*')printf(" ");
                else printf("*");
            }
            printf("|\n");
        }
        for(int i=0;i<n+2;++i)printf("-");
        printf("\n");
    }
}
