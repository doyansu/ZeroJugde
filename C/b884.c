#include <stdio.h>

int main(){
    int n;
    scanf("%d",&n);
    while(n--){
        int x,y;
        scanf("%d%d",&x,&y);
        int yee=100-x-y;
        if(yee>60 && yee<100)printf("Happyyummy\n");
        else if(yee>30 && yee<=60)printf("hmm~~\n");
        else if(yee>0 && yee<=30)printf("sad!\n");
        else printf("evil!!\n");
    }
}
