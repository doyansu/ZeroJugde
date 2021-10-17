#include <stdio.h>

int main(){
    int main=0,cos=0;
    int win=0;
    int temp;
    for(int i=0;i<4;++i){
        scanf("%d",&temp);
        main+=temp;
    }
    for(int i=0;i<4;++i){
        scanf("%d",&temp);
        cos+=temp;
    }
    printf("%d:%d\n",main,cos);
    if(main>cos)++win;
    else --win;
    main=0;
    cos=0;
    for(int i=0;i<4;++i){
        scanf("%d",&temp);
        main+=temp;
    }
    for(int i=0;i<4;++i){
        scanf("%d",&temp);
        cos+=temp;
    }
    printf("%d:%d\n",main,cos);
    if(main>cos)++win;
    else --win;
    if(win>0)puts("Win");
    else if(win==0)puts("Tie");
    else puts("Lose");
}
