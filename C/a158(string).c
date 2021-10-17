#include <stdio.h>

int gcd(int n, int m){
    return n%m ? gcd(m, n%m) : m;
}

static inline void solve(){
    int Case, list[100];
    char input[10000];
    register char *p;
    scanf("%d ", &Case);
    while(Case--){
        fgets(input, 10000, stdin);
        int max = 1, len = 0, temp= 0;
        for(p = input; *p != '\0'; p++){
            if(*p >= '0' && *p <= '9')
                temp = (temp << 3) + (temp << 1) + (*p ^ '0');
            else {
                if(temp)
                    list[len++] = temp;
                temp = 0;
            }
        }
        if(temp)
            list[len++] = temp;
        for(int i = 0; i < len; i++)
            for(int j = i + 1; j < len; j++)
                if(max < (temp = gcd(list[i], list[j])))
                    max = temp;
        printf("%d\n", max);
    }
}

int main(){
    solve();
    return 0;
}
