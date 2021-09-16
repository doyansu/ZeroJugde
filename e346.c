#include <stdio.h>//AC (0.1s, 1.6MB)
#define SIZE 200001

long long int list[SIZE];

void putllint(long long int out)
{
    char buf[1000];
    int n=0;
    if(out<0) putchar('-'),out=out*-1;
    do{
        buf[n++]='0'+(out%10);
        out=out/10;
    }while(out>0);
    for(n=n-1;n>=0;n--)
        putchar(buf[n]);
    putchar('\n');
}

int get_int(){
    int n = 0, si = 1;
    char tc = getchar();
    while((tc<'0'||tc>'9') &&  tc != '-')tc = getchar();
    if(tc == '-'){
        tc = getchar();
        si = -1;
    }
    while(tc >= '0' && tc <= '9'){
        n = (n<<1) + (n<<3) + (tc ^ '0');
        tc = getchar();
    }
    return n * si;
}

int main(){
    int n = get_int() + 1;
    list[0] = 0;
    for(int i = 1; i < n; i++)
        list[i] = list[i - 1] + get_int();
    int left, right, q = get_int();
    while(q--){
        left = get_int();
        right = get_int();
        putllint(list[right] - list[left - 1]);
    }
}
