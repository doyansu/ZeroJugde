#include <stdio.h>

int main(){
    int n;
    scanf("%d",&n);
    while(n--){
        int h1,m1,h2,m2,m3;
        scanf("%d%d%d%d%d",&h1,&m1,&h2,&m2,&m3);
        m1+=m3;
        h1+=m1/60;
        m1%=60;
        if(h2>h1)puts("Yes");
        else if(h2==h1){
            if(m2>=m1)puts("Yes");
            else puts("No");
        }
        else puts("No");
    }
}
