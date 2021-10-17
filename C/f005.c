#include <stdio.h>
#define SIZE 102

static inline void solve(){
    int t, list[40];
    char str[SIZE];
    scanf("%d", &t);
    t++;
    for(int Case = 1; Case < t; Case++){
        int count = 0, len;
        scanf("%d ", &len);
        gets(str);
        for(int i = 0; i < len; i++)
            if(str[i] == '.'){
                if(i + 2 <= len)
                    list[count++] = i += 2;
                else
                    list[count++] = i += 1;
            }
        printf("Case %d: %d", Case, count);
        if(count){
            putchar('(');
            for(int i = 0; i < count; i++){
                printf("%d", list[i]);
                if(i != count - 1)putchar(',');
            }
            putchar(')');
        }
        putchar('\n');
    }
}

int main(){
    solve();
    return 0;
}
