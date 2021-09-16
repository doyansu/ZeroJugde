#include <stdio.h>

int main(){
    long long int list[3];
    while(scanf("%lld%lld%lld",list,list+1,list+2)!=EOF){
        if(list[0]>list[1] && list[1]>list[2]){
            list[1]+=list[2];
            list[2]=0;
        }
        else if(list[0]>list[2] && list[2]>list[1]){
            list[2]+=list[1];
            list[1]=0;
        }
        else if(list[1]>list[2] && list[2]>list[0]){
            list[2]+=list[0];
            list[0]=0;
        }
        else if(list[1]>list[0] && list[0]>list[2]){
            list[0]+=list[2];
            list[2]=0;
        }
        else if(list[2]>list[0] && list[0]>list[1]){
            list[0]+=list[1];
            list[1]=0;
        }
        else if(list[2]>list[1] && list[1]>list[0]){
            list[1]+=list[0];
            list[0]=0;
        }
        int index=0;
        for(int i=0;i<3;++i)if(list[i]>list[index])index=i;
        switch(index){
        case 0:
            puts("A");
            break;
        case 1:
            puts("B");
            break;
        case 2:
            puts("C");
            break;

        }
    }
}
