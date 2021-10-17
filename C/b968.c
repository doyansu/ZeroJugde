#include <stdio.h>
#define SIZE 100

int main(){
    char str[SIZE];
    gets(str);
    printf("%s and ", str);
    gets(str);
    printf("%s", str);
    puts(" sitting in the tree");
}
