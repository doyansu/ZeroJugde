#include <stdio.h>
#include <stdlib.h>
#define SIZE 15001


int main(){
    int v1[SIZE][2],v2[SIZE][2];
    int len1=0;
    int len2=0;
    char ch;
    while(scanf("%d%c%d",v1[len1],&ch,v1[len1]+1)){
        if(v1[len1][0]==0 && v1[len1][1]==0)break;
        //printf("%d %d\n",v1[len1][0],v1[len1][1]);
        len1++;
    }
    while(scanf("%d%c%d",v2[len2],&ch,v2[len2]+1)){
        if(v2[len2][0]==0 && v2[len2][1]==0)break;
        len2++;
    }
    int innerProduct=0;
    for(int i=0;i<len1;++i){
        for(int j=0;j<len2;++j){
            if(v1[i][0]==v2[j][0]){
                innerProduct+=v1[i][1]*v2[j][1];
            }
        }
    }
    printf("%d\n",innerProduct);
}
