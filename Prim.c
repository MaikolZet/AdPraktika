#include <stdio.h>
#include "Prim.h"

//METROPOLISA

/*Metropolis hiriko Trafiko Sailak zenbait kaleetan zehar konponketa lanak egitea erabaki du. Baina lan
hauek aurrera emateko trafikoa etetea beharrezkoa da konponketak egiten ari diren kaleetan zehar.
***Trafikoa eten daitekeen kaleen zerrenda maximoa ematea eskatzen da***, bidagurutze guztiak
atxikigarriak izan behar dutela jakinik eta trafiko fluxu ahalik eta handiena utziz/errespetatuz.
Adi: Zein da problema honetan funtzio hautesle zuzena?

Sarrera: Sarrerako datuak testuzko fitxategi batean metatu behar dira jarraiko formatua izango duena:
    
    • Lehenengo lerroan n zenbaki osoko positiboa, (n≤10 6): ===>  grafoak dituen erpin kopurua adierazten du.    
    • Bigarrengo lerroan a zenbaki osoko positiboa, (a≤108): ===>  grafoak dituen ertz kopurua adierazten du.
    • Hurrengo a lerroetan, 3 zenbaki:
        o Lehenengo biak ===> (x,y) ertza adierazten dute.
        o Hirugarrengoa  ===> (x,y) ertzari dagokion pisua adieraziko du. 

Sarrerako .txt adibide bat:

    7
    16
    0 1 0.15     1 2 4.52    2 3 12.1   3 4 3.45    4 5 5.43   5 6 12.5
    0 2 0.87     1 3 5.8     2 4 3.6    3 5 9.21
    0 3 4.4      1 4 9.65    2 5 2.0      
    0 4 1.3      1 5 12.2
    0 5 5.9
    
*/


void PRIM (int p, ertzPisuPos hzm []){

    //Gero berez matrize hau parametro bezela pasa beahr deu
    int G[30][30];
    
    int PisuMin[p], 
    Auzokide[p];

    int k, ind, j, z, minP, sLuz=0; // = MultzoHutsaErt (hzm);
    
    //Lehen erpina kanpoan hasieratu??
    PisuMin[0]=-1;
    
    for (k=1; k<p; k++){
        //ERT-ko lehen erpina 0 da. Besteek haraino duten distantziaz hasieratu        
        Auzokide[k]= 0; 
        PisuMin[k] = G[k][0]; 
    }

    for (sLuz=0; sLuz<(p-1); sLuz++) {// #(p-1) aldiz
        
        //Balio maximoarekin hasieratu minP
        minP = __INT_MAX__;

        for (j=1; j<p; j++){ // 1..p-1
            
            //minimoa bilatu eta posizioa K-n gorde
            if (PisuMin[j]>-1 && PisuMin[j] < minP){
                minP=PisuMin[j]; 
                k=j;
            }
        }

    // k harrapatzen du hzm-k;
    ErantsiErt(hzm, k, &Auzokide[k], &PisuMin[k], sLuz);
    
    // ≅sErt[sLuz]=(k,Auzokide[k], PisuMin[k])
    PisuMin[k]= -1;
    
    for (z=1; z<p; z++ ){ //k-ren auzokideeak direnak
        
        if (G[k][j]<PisuMin[z]) {
            
            PisuMin[z]= G[k][z]; Auzokide[z]=k; 
        }
    }
    }
}

void ErantsiErt(ertzPisuPos hzm [], int k, int Auzokide [], int PisuMin [], int sluz){
    //TODO
}

void main2(void){
    printf("Auxilio");
}
