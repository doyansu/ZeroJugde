//double times=(int)((sqrt(4*n*n-4*n+1+8*m)-2*n+1)/2)+1;
int main(){
    int n,m;
    while(scanf("%d%d",&n,&m)!=-1){
        int sum=n,times=1;
        while(sum<=m){
            n++;
            sum+=n;
            times++;
        }
        printf("%d\n",times);
    }
}
