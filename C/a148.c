#define PASS 59

int main(){
    int n;
    while(scanf("%d",&n)!=-1){
        int total=0;
        for(int i=0;i<n;i++){
            int x;
            scanf("%d",&x);
            total+=x;
        }
        if(total>PASS*n)printf("no\n");
        else printf("yes\n");
    }
}
