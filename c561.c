#include <stdio.h>

int main(){
    int n;
    int max=-1;
    scanf("%d",&n);
    while(n--){
        int newn=0;
        int temp;
        scanf("%d",&temp);
        while(temp){
            newn=(newn<<3)+(newn<<1)+temp%10;
            temp/=10;
        }
        if(newn>max)max=newn;
    }
    printf("%d\n",max);
}
