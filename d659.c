#include <stdio.h>

int main(){
    int t,who;
    int list[3];
    scanf("%d", &t);
    t++;
    for(int i = 1; i < t; i++){
        scanf("%d%d%d", list, list+1, list+2);
        if(list[1] > list[0] && list[0] > list[2] || list[2] > list[0] && list[0] > list[1])who = list[0];
        else if(list[0] > list[1] && list[1] > list[2] || list[2] > list[1] && list[1] > list[0])who = list[1];
        else who = list[2];
        printf("Case %d: %d\n", i, who);
    }
}
