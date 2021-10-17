#include <stdio.h>
#define MAXINF 0x7fffffff

int main(){
    int t, max = 0;
    scanf("%d", &t);
    while(t--){
        int n, min = MAXINF, data;
        scanf("%d", &n);
        while(n--){
            scanf("%d", &data);
            if(data < min)
                min = data;
        }
        if(max < min)
            max = min;
    }
    printf("%d\b", max);
    return 0;
}
