#include<stdio.h>
#define SIZE 100

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int list[SIZE][SIZE];
        int n,m;
        scanf("%d%d",&n,&m);
        int x=0,y=-1,len=n,state=0,step=0;
        for(int i=1;i<n*n+1;++i){
            //printf("state= %d len= %d step= %d\n",state,len,step);
            ++step;
            switch(state){
            case 0:
                ++y;
                break;
            case 1:
                ++x;
                break;
            case 2:
                --y;
                break;
            case 3:
                --x;
                break;
            }
            list[x][y]=i;
            if(step==len){
                step=0;
                if((state==0 || state==2) && len>1)--len;
                ++state;
                if(state==4)state=0;
            }

        }

        if(m==1){
            for(int i=0;i<n;++i){
                for(int j=0;j<n;++j){
                    printf("%5d",list[i][j]);
                }
                printf("\n");
            }
        }
        else{
            for(int i=0;i<n;++i){
                for(int j=0;j<n;++j){
                    printf("%5d",list[j][i]);
                }
                printf("\n");
            }
        }
    }
}
