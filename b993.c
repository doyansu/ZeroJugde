#include <stdio.h>
int main(){
    int n;
    while(scanf("%d",&n)!=EOF){
        int max=0;
        while(n--){
            int p;
            scanf("%d",&p);
            if(p>max)max=p;
        }
        printf("%d\n",max);
    }
}
