#include<stdio.h>

int main(){
    int luckNumber[3], temp[5] = {0}, data, total = 0, thirdG = 2;
    for(int i = 0; i < 3; i++)
        scanf("%d", luckNumber + i);
    for(int i = 0; i < 5; i++){
        scanf("%d", &data);
        for(int j = 0; j < 3; j++){
            if(data == luckNumber[j]){
                if(j == 2){
                    temp[i] -= 1;
                    thirdG = 1;
                }
                else
                    temp[i] += 1;
            }
        }
    }
    for(int i = 0; i < 5; i++){
        scanf("%d", &data);
        total += data * temp[i];
    }
    total *= thirdG;
    printf("%d", (total > 0) ? total : 0);
}
