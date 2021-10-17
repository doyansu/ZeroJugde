#define SIZE 1000

int SWAP(int *a,int *b){
    int t=*a;
    *a=*b;
    *b=t;
}

int main(){
    int n;
    while(scanf("%d",&n)!=-1){
        int list[SIZE];
        for(int i=0;i<n;i++){
            scanf("%d",&list[i]);
            for(int j=i;j>0;j--)if(list[j]>list[j-1])SWAP(&list[j],&list[j-1]);else break;
        }
        for(int i=0;i<n;i++)for(int j=i;j>0;j--)if(list[j]%10<list[j-1]%10)SWAP(&list[j],&list[j-1]);else break;
        for(int i=0;i<n;i++)printf("%d ",list[i]);
        printf("\n");
    }
}
