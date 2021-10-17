#include <stdio.h>
#define F(x) 2 * x - 3
#define G(x, y) 2 * x + y - 7
#define H(x, y, z) 3 * x - 2 * y + z

char str[6];
char *p;

static inline int solve(){
    int temp = 0;
    scanf("%s", str);
    switch(*str){
    case 'f':
        temp = F(solve());
        break;
    case 'g':
        temp = G(solve(), solve());
        break;
    case 'h':
        temp = H(solve(), solve(), solve());
        break;
    default:
        p = str;
        if(*p == '-')p++;
        while(*p != '\0')
            temp = (temp << 3) + (temp << 1) + ('0' ^ *p++);
        if(*str == '-')temp = ~temp + 1;
        break;
    }
    return temp;

}

int main(){
    printf("%d",solve());
    return 0;
}
