#include <stdio.h>

int main(){
    int n;
    scanf("%d ",&n);
    while(n--){
        int x,a,b;
        scanf("%d%d%d",&x,&a,&b);
        int min=0;
        int i;
        for(i=x/a;i>=0;--i){
            if((x-a*i)%b==0){
                min=i+(x-a*i)/b;
                break;
            }
        }
        if(i<0)puts("-1");
        else printf("%d\n",min);
    }
}
