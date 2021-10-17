#include <stdio.h>

int main(){
    int array[3];
    int ans=0;
    for(int i=0;i<5;++i){
        int max=0,index=0;
        scanf("%d%d%d",&array[0],&array[1],&array[2]);
        for(int x=0;x<3;++x){
            if(array[x]>max){
                max=array[x];
                index=x;
            }
        }
        for(int x=0;x<3;++x){
            if(index!=x)max-=array[x];
        }
        if(max<0)++ans;
    }
    printf("%d",ans);
}
