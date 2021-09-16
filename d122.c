#include <stdio.h>//AC 2ms

int main(){
    long int n, ans, temp;
    while(scanf("%ld", &n)!=EOF){
        temp = 5;
        ans = 0;
        while(n>=temp){
            ans += n/temp;
            temp = (temp << 2) +temp;
        }
        printf("%ld\n",ans);
    }
    return 0;
}

/*#include <stdio.h>//AC 1ms

int main(){
    long int n, sum;
    while(scanf("%ld", &n)!=EOF){
        sum = 0;
        do{
            n /= 5;
            sum += n;
        }while(n);
        printf("%ld\n",sum);
    }
    return 0;
}*/
