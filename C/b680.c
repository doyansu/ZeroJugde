#include <stdio.h>
#define SIZE 400

typedef struct player_s{
    int id;
    double grade;
}player_t;


int main(){
    int n;
    int raceTrack[8]={6,4,2,0,1,3,5,7};
    while(scanf("%d",&n)!=EOF){
        player_t list[SIZE];
        player_t group[SIZE/8][8];
        for(int i=0;i<n;++i){
            scanf("%d%lf",&list[i].id,&list[i].grade);
            for(int j=i;j>0;--j){
                if(list[j].grade<list[j-1].grade){
                    player_t temp=list[j];
                    list[j]=list[j-1];
                    list[j-1]=temp;
                }
                else break;
            }
        }

        //for(int i=0;i<n;++i)printf("%d %.2f\n",list[i].id,list[i].grade);
        for(int i=0;i<n/8;++i){
            for(int j=0;j<n;j+=n/4){
                group[i][j*8/n]=list[j+i];
                group[i][j*8/n+1]=list[j+n/4-i-1];
                //printf("%d %d %d %d\n",j*8/n,j*8/n+1,j+i,j+n/4-i-1);
            }
        }
        //printf("\n");
        for(int i=0;i<n/8;++i){
            printf("%d ",i+1);
            for(int j=0;j<8;++j){
                printf("%d ",group[i][raceTrack[j]].id);
            }
            putchar('\n');
        }
    }
}
