#include <stdio.h>
#define SIZE 101
#define MAXINF 0x7fffffff


int main(){
    int input[7];
    int table[7]={1,2,4,8,16,32,64};
    while(scanf("%d%d%d%d%d%d%d",&input[0],&input[1],&input[2],&input[3],&input[4],&input[5],&input[6])){
        if(input[0]==-1)break;
        int ans=0;
        int box[7]={0};
        int index=1;
        for(int i=6;i>-1;--i){
            while(box[i]<input[i]){
                box[i]+=index;
                ans+=table[i];
                index+=2;
            }
            index<<=1;
            --index;
            box[i-1]=(box[i]-input[i])*4;
        }
        printf("%d\n",ans);
    }
}
