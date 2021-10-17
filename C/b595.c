#include <stdio.h>
#define SIZE 31
#define MAXINF 0x7fffffff

int main(){
    int n;
    while(scanf("%d", &n)==1 && n){
        int list[SIZE] = {0};
        int punishPoint[SIZE] = {0};
        int last[SIZE] = {0};
        for(int i = 1; i < n + 1; i++){
            scanf("%d", list + i);
            int min = MAXINF, index = 0;
            for(int j = 0; j < i; j++){
                int temp = (200 - (list[i] - list[j]));
                temp *= temp;
                temp += punishPoint[j];
                if(temp < min){
                    min = temp;
                    index = j;
                }
            }
            punishPoint[i] = min;
            last[i] = index;
        }

        /*for(int i=0;i<n+1;i++)printf("%d ",punishPoint[i]);
        putchar('\n');*/

        int out[SIZE] = {n}, len = 1;
        for(int i = last[n]; i > 0; i = last[i], len++)
            out[len] = i;
        for(int i = len; i >= 0; i--)
            printf("%d ",out[i]);
        putchar('\n');
    }
}
