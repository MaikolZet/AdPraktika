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
double baturaPrim=0;
extern Node lista[];

//Komentatze hasi aurretik, kostuen
//analisiak formatu hau jarraituko du:
//  - A: nodo kopurua
//  - K: ertz kopurua

//Bestetik hzm emaitzeko ertzak biltzen 
//dituen multzo hutsa da
void PRIM (int p, ertzPisuPos hzm []){
    
    //Auzokide[p] ertz bektore bat da: p nodotik, Auzokide[p]-ra joateko ertza
    int Auzokide[p];  // O(1)
    //Auzokide[p] bektoreko ertzei dagokien pisua biltzen duen bektorea
    float PisuMin[p]; // O(1)
    
    //Hasieraketak
    int k, j, z, sLuz=0;  // O(1) 
    float minP=0.0;       // O(1)
    
    //Lehen erpina kanpoan hasieratu
    PisuMin[0]=-1;    // O(1)    
    
    //Hasieraketa. Honen kostua O(p)
    for (k=1; k<p; k++){
        //ERT-ko lehen erpina 0 da. Besteek haraino duten distantziaz hasieratu        
        Auzokide[k]= 0; // O(1)
        //mysearchElement funtzioak nodo baten auzokideen artean ea k nodoarekin 
        //ertza dagoen edo ez bilatzen du, horregatik, honen kostua:
        PisuMin[k] = 1/mysearchElement(0, k);  //  O(K/A)
    }

    //Oinarrizko iterazioa, emaitzak bilatzeko
    for (sLuz=0; sLuz<(p-1); sLuz++) { // O(A) -> #(p-1) aldiz
        
        //Balio maximoarekin hasieratu minP
        minP = __FLT_MAX__;   //  O(1)

        //nodo guztien artean pisu gutxiena duena bilatzen du,
        //eta horren posizioa gordetzen du
        for (j=1; j<p; j++){  //  O(A)
            
            //minimoa bilatu eta posizioa K-n gorde
            if (-1<PisuMin[j] && PisuMin[j] < minP){
                minP=PisuMin[j]; //  O(1)
                k=j;  //  O(1)
            }
        }

        //K. nodotik, Auzokide[k]-ra joateko ertza eta honen pisua (Pisumin[K])
        //gordetzen duen funtzioa eraiki beharrean, emaitzak eskuz gordeko
        //ditugu hzm-n.  
        hzm[sLuz].A=k;   //  O(1)
        hzm[sLuz].B=Auzokide[k];   //  O(1)
        hzm[sLuz].weight= 1/PisuMin[k];   //  O(1)
        baturaPrim+=hzm[sLuz].weight;   //  O(1)
                
        //ertz berria emaitzean erantsi ondoren, pisu minimoen bektorea
        //eguneratu behar da, eta beraz, auzokide bektorea ere.
        PisuMin[k]= -1;   //  O(1)
        for (z=1; z<p; z++ ){  //  O(A)
            
            if (1/mysearchElement(k,z) < PisuMin[z]){  //  O(1)
                PisuMin[z]= 1/mysearchElement(k, z);   //  O(1)
                Auzokide[z]=k;    //  O(1)
            }
        }
    }
}



void PRIM_MAX (int p, ertzPisuPos hzm []){
    
    //Auzokide[p] ertz bektore bat da: p nodotik, Auzokide[p]-ra joateko ertza
    int Auzokide[p];
    //Auzokide[p] bektoreko ertzei dagokien pisua biltzen duen bektorea
    float PisuMax[p]; 

    int k, j, z, sLuz=0; // = MultzoHutsaErt (hzm);
    float maxP=0.0;
    
    //Lehen erpina kanpoan hasieratu??
    PisuMax[0]= -1;
    
    for (k=1; k<p; k++){
        //ERT-ko lehen erpina 0 da. Besteek haraino duten distantziaz hasieratu        
        Auzokide[k]= 0; 
        
        //Berria:
        //Simetrikotasun errorea Maikol
        PisuMax[k] = mysearchElement(0, k);
        //printf("Pisumin[%d]: %f \n",k, PisuMin[k]);

        
    }

    for (sLuz=0; sLuz<(p-1); sLuz++) {// #(p-1) aldiz
        
        //Balio maximoarekin hasieratu minP
        maxP = __FLT_MIN__;
        //printf("minP: %f \n", minP);

        for (j=1; j<p; j++){ // 1..p-1
            
            //minimoa bilatu eta posizioa K-n gorde
            if (PisuMax[j] > maxP){
                maxP=PisuMax[j]; 
                k=j;
            }
        }

        //K. nodotik, Auzokide[k]-ra joateko ertza eta honen pisua (Pisumin[K])
        //gordetzen duen funtzioa. Hzm-n gordeko da (soluzio bektorea) //sLuz zertarako??
        //ErantsiErt(hzm, k, &Auzokide[k], &PisuMin[k], sLuz);
        
        hzm[sLuz].A=k;
        hzm[sLuz].B=Auzokide[k];
        hzm[sLuz].weight=PisuMax[k];
        baturaPrim+=hzm[sLuz].weight;
        //printf("KONTUZ!! from %d to %d, with weight: %f \n", k, Auzokide[k], PisuMin[k]);
        
        // ≅sErt[sLuz]=(k,Auzokide[k], PisuMin[k])
        PisuMax[k]= -1;


        for (z=1; z<p; z++ ){ //k-ren auzokideeak direnak
            // //Zaharra:
            // if (G[k][j]<PisuMin[z]) {
            //     PisuMin[z]= G[k][z]; 
            //     Auzokide[z]=k; 
            // }
            
            //Berria:
            //Simetrikotasun arazoa Maikol
            
            
            //Simetrikotasun arazoa Maikol
            if (mysearchElement(k,z) > PisuMax[z] && PisuMax[z] != -1) {
                //printf("HAu da Z: %d eta hau da K: %d eta hau da J: %d\n",z,k,j);
                PisuMax[z]= mysearchElement(k, z); 
                Auzokide[z]=k; 
            }
        }
    }
}

