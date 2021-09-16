#include<math.h>
int main(){
    int data;
    scanf("%d",&data);
    data++;
    for(int i=1;i<data;i++){
        int result=0,a,b;
        scanf("%d%d",&a,&b);
        b++;
        for(int j=a;j<b;j++){
            double x=sqrt(j);
            int y=(int)x;
            if(x-y==0)result+=j;
        }
        printf("Case %d: %d\n",i,result);
    }
}
