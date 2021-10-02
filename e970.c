#include <stdio.h>
#define MAXINPUT 10001

int main(){
    int n, array[MAXINPUT], temp, sum = 0;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
        scanf("%d", array + i);
    *array = temp = array[n];
    for(int i = 1; i <= n; i += temp)
        sum += array[i];
    temp = sum % n;
    if(temp == 0)
        temp = n;
    printf("%d %d\n", temp, array[temp]);
    return 0;
}
