#include <stdio.h>
#define MAXINF 0X7fffffff

int main(){
    int n;
    while(scanf("%d", &n) == 1){
        n++;
        int m;
        for(int i = 1; i < n; i++){
            scanf("%d", &m);
            int avg = 0, best = MAXINF;
            for(int j = 0; j < m; j++){
                int min, sec;
                scanf("%d%d", &min, &sec);
                min = 60 * min + sec;
                avg += min;
                if(best > min)best = min;
            }
            avg /= m;
            printf("Track %d:\n", i);
            printf("Best Lap: %d minute(s) %d second(s).\n", best / 60, best % 60);
            printf("Average: %d minute(s) %d second(s).\n", avg / 60, avg %60);
        }
    }
}
