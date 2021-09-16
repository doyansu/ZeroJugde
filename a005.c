int main(){
    int t=0,list[5];
    scanf("%d",&t);
    while(t--){
        scanf("%d%d%d%d",&list[0],&list[1],&list[2],&list[3]);
        if(list[3]-list[2]==list[2]-list[1] && list[2]-list[1]==list[1]-list[0])list[4]=list[3]+list[3]-list[2];
        else list[4]=list[3]*(list[3]/list[2]);
        printf("%d %d %d %d %d\n",list[0],list[1],list[2],list[3],list[4]);
    }
}
