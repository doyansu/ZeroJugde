#include <stdio.h>
#include <string.h>
#include <math.h>
#define MAXSIZE 92500
#define EulerMascheroniconstant 0.261497212847642
#define e 2.718281828459045


int main() {
    char input[MAXSIZE], *p;
	while(gets(input)){
        int i;
        double temp = 0;
        for(p = input, i = 0; i < 15 && *p; i++, p++)
            temp = 10 * temp + ('0' ^ *p);
        temp /= pow(10, i - 1);
        printf("%.3lf\n", log((log10(temp) + strlen(input) - 1) / log10(e)) + EulerMascheroniconstant);
	}
	return 0;
}
