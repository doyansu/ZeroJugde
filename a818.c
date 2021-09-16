#include<stdio.h>
#include<string.h>
#define SIZE 21

int main(){
    int n;
    while(scanf("%d",&n)!=EOF){
        int array[SIZE]={0};
        int key;
        char string[SIZE];
        char newstring[SIZE];
        for(int i=0;i<n;++i)scanf("%d",&array[i]);
        scanf("%s",string);
        scanf("%d",&key);
        for(int i=0;i<key;++i){
            for(int x=0;x<n;++x){
                newstring[x]=string[array[x]-1];
            }
            strcpy(string,newstring);
        }
        puts(newstring);
    }
}
