#include <stdio.h>

int main(){
    int n, k;
    while(scanf("%d%d", &n, &k) == 2){
        //a+a/b+(a/b+a%b)/b
        int sum = n;
        while(n >= k){
            sum += n/k;
            n= n/k + n%k;
        }
        printf("%d\n",sum);
    }
}
