#include <stdio.h>

int main(){
   int n;
   char s[1000], *p;
   scanf("%d ", &n);
   while(n--){
        gets(s);
        p = s;
        int temp = 0;
        while(*p)
            temp += *p++ ^ '0';
        if(temp%3 == 1)
            puts("NO");
        else
            puts("YES");
   }
}
