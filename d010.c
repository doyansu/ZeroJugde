#include <stdio.h>


int main(){
    int n;
    while(scanf("%d",&n)!=EOF){
        int s=1;
        for(int i=2;i<n;++i)if(!(n%i))s+=i;
        if(s>n)printf("�ռ�\n");
        else if(s<n)printf("����\n");
        else printf("������\n");
    }
}
