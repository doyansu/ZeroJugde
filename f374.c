#include <stdio.h>

int main(){
    int n, p;
    while(scanf("%d%d", &n, &p) == 2){
        int group = 1, power = -1, maxgroup = 0;
        while(p){
            int temp = 0;
            for(int i = 0; i < n; i++){
                temp += p%10;
                p /= 10;
            }
            if(temp >= power){
                power = temp;
                maxgroup = group;
            }
            group++;
        }
        printf("%d %d\n", maxgroup, power);
    }
}
