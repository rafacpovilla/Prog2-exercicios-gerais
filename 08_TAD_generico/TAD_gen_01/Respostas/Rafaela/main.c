#include <stdio.h>
#include <stdlib.h>
#include "tadgen.h"

int main (){
    printf("tad_gen_01\n");
    printf("Digite o tipo e numero de elementos: \n");
    
    int tipo, numElem;
    scanf("%d %d", &tipo, &numElem);
    
    tGeneric *gen = CriaGenerico(tipo, numElem);
    LeGenerico(gen);
    ImprimeGenerico(gen);
    DestroiGenerico(gen);
    
    return 0;
}