#include <stdio.h>//AC 64ms 92kb

int main(){
    int n, data;
    long out=0;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &data);
        out += data;
        printf("%lld ",out);
    }
}

/*#include <stdio.h>
#define SIZE 200001

int main(){
    int n;
    int list[SIZE];
    scanf("%d", &n);
    for(int i = 0; i < n; i++)scanf("%d", list+i);
    long out=0;
    for(int i = 0; i < n; i++){
        out += list[i];
        printf("%lld ",out);
    }
}*/
