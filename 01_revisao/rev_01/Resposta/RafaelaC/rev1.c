#include <stdio.h>
#include <math.h>

int main (){
    float xAlvo, yAlvo, rAlvo, xDisparo, yDisparo, rDisparo;
    float distancia;

    scanf("%f %f %f", &xAlvo, &yAlvo, &rAlvo);
    scanf("%f %f %f", &xDisparo, &yDisparo, &rDisparo);

    distancia = sqrt((xAlvo - xDisparo)*(xAlvo - xDisparo) + (yAlvo - yDisparo)*(yAlvo - yDisparo));

    if(rAlvo + rDisparo >= distancia){
        printf("ACERTOU\n");
    }
    else{
        printf("ERROU\n");
    }

}