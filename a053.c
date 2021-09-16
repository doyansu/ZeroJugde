int score(int n){
    if(n==0)return 6;
    else if(n==11)return 2;
    return 1;
}

int main(){
    int n;
    while(scanf("%d",&n)!=-1){
        int result=0;
        if(n>=40)printf("100\n");
        else{
            for(int i=1;i<n+1;i++){
                if(i>20)result+=score(21);
                else if(i>10)result+=score(11);
                else result+=score(0);
            }
            printf("%d\n",result);
        }
    }
}
