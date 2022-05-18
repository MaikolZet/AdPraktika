#include <stdio.h>
#include "Prim.h"
#include "lag.h"

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

extern Node lista[];

void PRIM (int p, ertzPisuPos hzm []){
    
    //Auzokide[p] ertz bektore bat da: p nodotik, Auzokide[p]-ra joateko ertza
    int Auzokide[p];
    //Auzokide[p] bektoreko ertzei dagokien pisua biltzen duen bektorea
    float PisuMin[p]; 

    int k, ind, j, z, sLuz=0; // = MultzoHutsaErt (hzm);
    float minP=0.0;
    //Lehen erpina kanpoan hasieratu??
    PisuMin[0]=-1;
    
    for (k=1; k<p; k++){
        //ERT-ko lehen erpina 0 da. Besteek haraino duten distantziaz hasieratu        
        Auzokide[k]= 0; 
        
        //Zaharra:
        //PisuMin[k] = G[k][0]; 

        //Berria:
        //Simetrikotasun errorea Maikol
        PisuMin[k] = mysearchElement(&lista[0], k);
        printf("Pisumin[%d]: %f \n",k, PisuMin[k]);

        
    }

    for (sLuz=0; sLuz<(p-1); sLuz++) {// #(p-1) aldiz
        
        //Balio maximoarekin hasieratu minP
        minP = __FLT_MAX__;
        printf("minP: %d \n", minP);

        for (j=1; j<p; j++){ // 1..p-1
            
            //minimoa bilatu eta posizioa K-n gorde
            if (-1<PisuMin[j] && PisuMin[j] < minP){
                minP=PisuMin[j]; 
                k=j;
            }
        }

        //K. nodotik, Auzokide[k]-ra joateko ertza eta honen pisua (Pisumin[K])
        //gordetzen duen funtzioa. Hzm-n gordeko da (soluzio bektorea) //sLuz zertarako??
        //ErantsiErt(hzm, k, &Auzokide[k], &PisuMin[k], sLuz);
        
        hzm[sLuz].A=k;
        hzm[sLuz].B=Auzokide[k];
        hzm[sLuz].weight=PisuMin[k];
        
        printf("KONTUZ!! from %d to %d, with weight: %f \n", k, Auzokide[k], PisuMin[k]);
        
        // ≅sErt[sLuz]=(k,Auzokide[k], PisuMin[k])
        PisuMin[k]= -1;
        
        int handiena=0, txikiena=0;
        if (k>j){
            handiena=k;
            txikiena=j;
        }else{
            handiena=j;
            txikiena=k;
        }


        for (z=1; z<p; z++ ){ //k-ren auzokideeak direnak
            // //Zaharra:
            // if (G[k][j]<PisuMin[z]) {
            //     PisuMin[z]= G[k][z]; 
            //     Auzokide[z]=k; 
            // }
            
            //Berria:
            //Simetrikotasun arazoa Maikol
            
            
            //Simetrikotasun arazoa Maikol
            if (mysearchElement(&lista[txikiena], handiena) < PisuMin[z]) {
                
                int handienaZ=0, txikienaZ=0;
                if (k>z){
                    handienaZ=k;
                    txikienaZ=z;
                }else{
                    handienaZ=z;
                    txikienaZ=k;
                }
                
                PisuMin[z]= mysearchElement(&lista[txikienaZ], handienaZ); 
                Auzokide[z]=k; 
            }
        }
    }
}

void ErantsiErt(ertzPisuPos hzm [], int k, int Auzokide [], float PisuMin [], int sluz){
   return;
}

void main2(void){
    float a = mysearchElement(&lista[0], 14);
    printf("%f \n", a);
}
