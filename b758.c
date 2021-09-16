#include <stdio.h>

int main(){
    int x,y;
    while(scanf("%d%d",&x,&y)!=EOF){
        int t=60*x+y+150;
        printf("%02d:%02d\n",(t/60)%24,t%60);
    }
}
