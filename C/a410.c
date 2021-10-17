#include <stdio.h>

int main(){
    int a,b,c,d,e,f;
    scanf("%d%d%d%d%d%d",&a,&b,&c,&d,&e,&f);
    float v=a*e-b*d;
    float vx=c*e-b*f;
    float vy=a*f-c*d;
    if(v==0 && vx==0 && vy==0)printf("Too many\n");
    else if(v==0 && (vx!=0 || vy!=0))printf("No answer\n");
    else if(v!=0){
        printf("x=%.2f\n",vx/v);
        printf("y=%.2f\n",vy/v);
    }
}
