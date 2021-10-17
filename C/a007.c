#include <stdio.h>
#define SIZE 4800
#define MAXPRIME 46340

int len = 0, prime[SIZE];
char isnotprime[MAXPRIME] = {1, 1};

static inline char isprime(int n){
    if(n < MAXPRIME)
        return !isnotprime[n];
    else {
        for(int i = 0; i < len; i++){
            if(n < prime[i] * prime[i])
                break;
            if(n % prime[i] == 0)
                return 0;
        }
    }
    return 1;
}

int main(){
    int n, temp = 2;
    while(temp < 220){
        for(int i = temp << 1; i < MAXPRIME; i += temp)
            isnotprime[i] = 1;
        while(isnotprime[++temp]);
    }
    for(int i = 2; i < MAXPRIME; i++)
        if(isnotprime[i] == 0)
            prime[len++] = i;
    while(scanf("%d", &n) == 1){
        if(isprime(n))
            puts("借计");
        else
            puts("獶借计");
    }
    return 0;
}

/*#include <stdio.h>
#define SIZE 4800
#define MOST 46350

int isprime(int list[SIZE],int index,int n){
    if(n==1)return 0;
    else if(n==2 || n==3)return 1;
    for(int i=1;i<index;i++){
        if(list[i]*list[i]>n)return 1;
        if(n%list[i]==0)return 0;
    }
    return 1;
}

int main(){
    int n;
    int prime[SIZE]={2},len=1;
    for(int i=3;i<MOST;i+=2)if(isprime(prime,len,i))prime[len++]=i;
    while(scanf("%d",&n)!=EOF){
        if(isprime(prime,len,n))printf("借计\n");
        else printf("獶借计\n");
    }
    return 0;
}
*/

