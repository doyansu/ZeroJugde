#include <stdio.h>

int main(){
    int t;
    long long int m, k, div;
    scanf("%d", &t);
    for(int Case = 1; Case <= t; Case++){
        printf("Case %d :\n", Case);
        scanf("%lld%lld", &m, &k);
        div = m / k;
        m %= k;
        for(long long int i = 1; i < k; i++)
            printf("��%d�� : ��%lld���û�DD! BAD!\n", i, div);
        printf("��%d�� : ��%lld���û�DD! BAD!\n", k, div + m);
    }
}
