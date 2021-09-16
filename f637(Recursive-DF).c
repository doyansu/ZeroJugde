#include <stdio.h>
#include <string.h>
#define SIZE 11000100

char str[SIZE];
char *p = str;

int square(int length , int n, int *i){//AC (10ms, 1.3MB)
    int time=0, total=0;
    while((*i)<length){
        time++;
        if(str[*i]=='2'){
            (*i)++;
            total =  total+ square(length ,n>>1 ,i);
        }
        else if(str[*i]=='1'){
            total = total+(n*n);
            (*i)++;
        }
        else if(str[*i]=='0'){
            (*i)++;
        }
        if(time==4)break;
    }
    return total;
}

int DF(int n){//	AC (11ms, 1.3MB)
    int sum = 0;
    if(*p == '2'){
        p++;
        sum += DF(n>>2);
        sum += DF(n>>2);
        sum += DF(n>>2);
        sum += DF(n>>2);
    }
    else if(*p == '1'){
        p++;
        sum += n;
    }
    else p++;
    return sum;
}

int main(){
    int weight;
    fgets(str, SIZE, stdin);
    scanf("%d", &weight);
    p=str;
    int i=0;
    printf("%d\n", square(strlen(str)-1, weight, &i));
    //printf("%d\n", DF(weight*weight));
}


/*#include <stdio.h>

int func(const c,int result[][c],char *DF,int *index,int *allwhite,int cf,int cend,int rf,int rend){
    if(cf==cend||rf==rend)return 0;
    if(DF[*index]=='2'){
        (*index)++;
        func(c,result,DF,index,allwhite,cf,cf+(cend-cf)/2,rf,rf+(rend-rf)/2);
        func(c,result,DF,index,allwhite,cf,cf+(cend-cf)/2,rf+(rend-rf)/2,rend);
        func(c,result,DF,index,allwhite,cf+(cend-cf)/2,cend,rf,rf+(rend-rf)/2);
        func(c,result,DF,index,allwhite,cf+(cend-cf)/2,cend,rf+(rend-rf)/2,rend);
    }
    else if(DF[*(index)]=='1'){
        (*index)++;
        *allwhite=0;
        for(int x=cf;x<cend;x++)for(int y=rf;y<rend;y++)result[x][y]=1;
    }
    else(*index)++;
}

int main(){
    char DF[100];
    int width=0,index=0,allwhite=1;
    scanf("%s",&DF);
    scanf("%d",&width);
    const c=width;
    int result[c][c];
    for(int x=0;x<c;x++)for(int y=0;y<c;y++)result[x][y]=0;
    func(c,result,DF,&index,&allwhite,0,width,0,width);
    int sum=0;
    for(int x=0;x<c;x++)for(int y=0;y<c;y++)if(result[x][y]==1)sum++;
    printf("%d\n",sum);
}*/
