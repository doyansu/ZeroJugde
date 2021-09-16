#include<math.h>
#define V(a,b,c) b*b-4*a*c
int RP(int a,int b,int c){
    return (-b+sqrt(V(a,b,c)))/(a+a);
}

int RG(int a,int b,int c){
    return (-b-sqrt(V(a,b,c)))/(a+a);
}

int main(){
    int a,b,c;
    scanf("%d%d%d",&a,&b,&c);
    if(V(a,b,c)>0)printf("Two different roots x1=%d , x2=%d",RP(a,b,c),RG(a,b,c));
    else if(V(a,b,c)==0)printf("Two same roots x=%d",RP(a,b,c));
    else printf("No real root");
}
