#include <stdio.h>
#define SIZE 10


int main()
{
    int n,data,max=-1;
    scanf("%d",&n);
    while(n--){
        scanf("%d",&data);
        if(data>max)max=data;
    }
    printf("%d",max);
}
