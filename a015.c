#define SIZE 100
int main(){
    int list[SIZE][SIZE],c,r;
    while(scanf("%d%d",&c,&r)!=-1){
        for(int i=0;i<c;i++)for(int j=0;j<r;j++)scanf("%d",&list[i][j]);
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++)printf("%d ",list[j][i]);
            printf("\n");
        }
    }
}
