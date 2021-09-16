#define SIZE 100
int main(){
    int d;
    while(scanf("%d",&d)!=-1){
        char b[SIZE];
        int index=0;
        while(d){
            b[index++]=d%2+'0';
            d/=2;
        }
        for(int i=index-1;i>=0;i--)printf("%c",b[i]);
        printf("\n");
    }
}
