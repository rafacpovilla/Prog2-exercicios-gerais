#include <stdio.h>

int main (){
    int decimal;
    int octal[1000];
    int i = 0;

    scanf("%d", &decimal);

    while(decimal > 0){
        octal[i] = decimal % 8;
        decimal = decimal / 8;
        i++;
    }

for(int j = i - 1; j >= 0; j--){
    printf("%d", octal[j]);
}

    return 0;
}