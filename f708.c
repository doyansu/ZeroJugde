#include <stdio.h>

int main(){
    int n, m, data;
    int sumn = 0, summ = 0;
    scanf("%d%d", &n, &m);
    for(int i = 0; i < n; i++){
        scanf("%d", &data);
        sumn += data;
    }
    for(int i = 0; i < m; i++){
        scanf("%d", &data);
        summ += data;
    }
    if(n > m && sumn > summ)puts("Yes");
    else puts("No");
}
