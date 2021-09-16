#include <stdio.h>

int main(){
    int c,w;
    while(scanf("%d%d",&c,&w)!=EOF){
        int d=0;
        while(w!=0){
            c-=11;
            --w;
            if(c<=0){
                if(c+w<=0)break;
                else{
                    while(c<0){
                        ++c;
                        --w;
                    }
                }
            }
            ++c;
            ++d;
        }
        printf("%d\n",d);
    }
}
