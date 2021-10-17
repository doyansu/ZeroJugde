#include <stdio.h>
#define SIZE 1001

int main(){
    int n,t;
    while(scanf("%d%d",&n,&t)!=EOF){
        int array[SIZE]={0},data,di,index=0;
        for(int i=0;i<n;++i){
            for(scanf("%d%d",&data,&di);data>0;data-=di){
                array[index]=data;
                for(int x=index;x>0;--x){
                    if(array[x]>array[x-1]){
                        int temp=array[x];
                        array[x]=array[x-1];
                        array[x-1]=temp;
                    }
                    else break;
                }
                if(index<1000)++index;
            }
        }
        data=0;
        for(int i=0;i<t;++i){
            data+=array[i];
        }
        printf("%d\n",data);
    }
}
