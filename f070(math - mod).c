#include <stdio.h>

void extgcd(long long int a, long long int b, long long int* d, long long int* x, long long int* y){
	if(!b) {
		*d = a;
		*x = 1;
		*y = 0;
	}
	else{
		extgcd(b, a % b, d, y, x);
		*y -= *x * (a / b);
	}
}

long long int mod_inv(long long int a, long long int n){
	long long int d, x, y;
	extgcd(a, n, &d, &x, &y);
	return d == 1 ? (x + n) % n : -1;
}


int main(){
    long long int m[3], r[3], prod;
    scanf("%lld%lld%lld%lld%lld%lld", m, r, m + 1, r + 1, m + 2, r + 2);
    prod = m[0] * m[1] * m[2];
    printf("%lld", (r[0] * mod_inv(prod / m[0], m[0]) * (prod / m[0]) + r[1] * mod_inv(prod / m[1], m[1]) * (prod / m[1]) + r[2] * mod_inv(prod / m[2], m[2]) * (prod / m[2])) % prod);
	return 0;
}
