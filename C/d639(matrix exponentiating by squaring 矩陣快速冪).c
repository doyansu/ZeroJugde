#include<stdio.h>
#define MOD 10007

typedef struct matrix_s{
    int table[3][3];
}matrix_t;

matrix_t initial, pb, zero;

void initialMatrix(){
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
            zero.table[i][j] = 0;
    initial.table[0][0] = 5;
    initial.table[0][1] = initial.table[1][0] = 3;
    initial.table[0][2] = initial.table[1][1] = initial.table[1][2] = initial.table[2][0] = initial.table[2][1] = initial.table[2][2] = 1;
    pb.table[0][0] = pb.table[0][1] = pb.table[1][0] = pb.table[1][2] = pb.table[2][0] = 1;
    pb.table[0][2] = pb.table[1][1] = pb.table[2][1] = pb.table[2][2] = 0;

}

matrix_t matrixMul(matrix_t a, matrix_t b){
    matrix_t temp = zero;
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
            for(int k = 0; k < 3; k++){
                temp.table[i][j] += a.table[i][k] * b.table[k][j];
                temp.table[i][j] %= MOD;
            }
    return temp;
}

void matrixFastExponentiation(int power){
    matrix_t ans = initial, base = pb;
    while(power){
        if(power & 1)
            ans = matrixMul(ans, base);
        base = matrixMul(base, base);
        power >>= 1;
    }
    printf("%d\n", ans.table[0][0]);
}

int main(){
    int n;
    initialMatrix();
    while(scanf("%d", &n) == 1){
        if(n < 4)
            puts("1");
        else if(n == 4)
            puts("3");
        else
            matrixFastExponentiation(n - 5);
    }
    return 0;
}
