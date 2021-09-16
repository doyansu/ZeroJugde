#include <stdio.h>

int main(){
    int n, max = 0, min = 10001;
    scanf("%d", &n);
    while(n--){
        int data;
        scanf("%d", &data);
        if(data > max)max = data;
        if(data < min)min = data;
    }
    printf("%d %d", max, min);
}
