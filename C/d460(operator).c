#include <stdio.h>

int main(){
    int n;
    while(scanf("%d", &n) == 1){
        printf("%d\n",(n>5)*590+(n>11)*200+(n>17)*100+(n>59)*(-491));
    }
}

/*#include <stdio.h>

int main(){
    int n;
    while(scanf("%d", &n) == 1){
        printf("%d\n",((n>5)&(n<12))*590+((n>11)&(n<18))*790+((n>17)&(n<60))*890+(n>59)*399);
    }
}
*/
