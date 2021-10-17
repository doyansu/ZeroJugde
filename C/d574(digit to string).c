#include <stdio.h>//AC (26ms, 6.5MB)
#define SIZE 10000010

char str[SIZE], out[SIZE];

int main(){
    int len;
    while(scanf("%d", &len) == 1){
        getchar();
        fgets(str, SIZE, stdin);
        str[len] = '\0';
        int temp = 0, count = 0, index;
        char *p = str, last = *p, tempint[13];
        while(*p != '\0'){
            if(*p != last){
                index = 0;
                while(temp){
                    tempint[index++] = '0' ^ (temp % 10);
                    temp /= 10;
                }
                for(temp = count, count += index--; temp < count; temp++, index--)
                    out[temp] = tempint[index];
                out[count++] = last;
                temp = 1;
            }
            else temp++;
            last = *p++;
        }
        index = 0;
        while(temp){
            tempint[index++] = '0' ^ (temp % 10);
            temp /= 10;
        }
        for(temp = count, count += index--; temp < count; temp++, index--)
            out[temp] = tempint[index];
        out[count++] = last;
        if(len > --count) puts(out);
        else puts(str);
    }
}
