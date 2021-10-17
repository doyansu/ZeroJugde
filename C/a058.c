int main(){
    int n,num;
    scanf("%d",&n);
    int k3=0,k31=0,k32=0;
    while(n--){
        scanf("%d",&num);
        switch(num%3){
        case 0:
            k3++;
            break;
        case 1:
            k31++;
            break;
        case 2:
            k32++;
            break;
        }
    }
    printf("%d %d %d",k3,k31,k32);
}
