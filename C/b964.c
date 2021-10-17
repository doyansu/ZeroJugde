#include <stdio.h>
#include <stdlib.h>
#define SIZE 21
#define MAXINF 0x7fffffff

int comp(const void *a,const void *b){return *(int*)a-*(int*)b;}

int main()
{
    int t;
    int array[SIZE]={0};
    scanf("%d",&t);
    int max=-1,min=MAXINF;
    for(int i=0;i<t;++i){
        scanf("%d",array+i);
        if(array[i]>=60){
            if(min>array[i])min=array[i];
        }
        else if(max<array[i])max=array[i];
    }
    qsort(array,t,sizeof(int),comp);
    for(int i=0;i<t;++i)printf("%d ",array[i]);
    putchar('\n');
    if(max==-1)puts("best case");
    else printf("%d\n",max);
    if(min==MAXINF)puts("worst case");
    else printf("%d\n",min);

}

