#include <stdio.h>
#define CHECK(s) *s=='-'?s+1:s
int main(){
    char s[20];
    gets(s);
    puts(CHECK(s));
}
/*#define abs(x) x>0?x:-x

int main(){
    int n;
    scanf("%d",&n);
    printf("%d",abs(n));
}
*/
