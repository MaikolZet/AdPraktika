#include <stdio.h>
#include "OUT_script.h"
#include "IN_script.h"
#include "lag.h"
#include "Prim.h"
#define elemkop(x)  (sizeof(x) / sizeof((x)[0]))

int main(void){
    //Donde se ejekuta la magia
    //TODO
    printf("Ejekutatzen da \n");
    //out();
    printf("========= \n");
    
    int nodoKop = in();
    ertzPisuPos hzm [nodoKop];
    PRIM(nodoKop,hzm);
    
    printf("%d\n", __INT_MAX__);
    
    for (int i = 0; i < nodoKop; i++){ 
        printf("from %d to %d, with weight: %f \n", hzm[i].A, hzm[i].B, hzm[i].weight);
    }
    
    printf("========= \n");
    //main2();
    
}