int main(){
    char c;
    while(scanf("%c",&c)!=-1){
        int result=0;
        int type=1;
        while(c!='\n'){
            if((c>64 && c<91) || (c>96 && c<123)){
                if(type){
                    result++;
                    type=0;
                }
            }
            else type=1;
            scanf("%c",&c);
        }
        printf("%d\n",result);
    }
}
