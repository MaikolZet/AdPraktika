#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Kruskal.h"
#include "lag.h"

// METROPOLISA

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

/*
PisuenGoranzkoOrdenaJarraituzOrdenatu(G, a, gEO); eginda ekarri
ertzOrdenatuak--> ertzen zerrenda ordenatua pisuarekiko
*/
extern int ema[];
extern Node2* lista_kruskal;
struct Node2* Emaitza;
int lehena=0;

void KRUSKAL()
{   
    struct Node2 * ertzOrdenatuak = (Node2 *)malloc(sizeof(Node2));
    ertzOrdenatuak->A= lista_kruskal->A;
    ertzOrdenatuak->B= lista_kruskal->B;
    ertzOrdenatuak->weight= lista_kruskal->weight;
    ertzOrdenatuak->next= lista_kruskal->next;
    
    int erpinKop=ema[0];
    int ertzKop=ema[1];

    int sErtzKop = 0, xBarne, yBarne, erpinx, erpiny;
    float pisua;

    //Hasieratu partiketa {-1, -1, ... , -1} izan dadin memorian
    int Partiketa[erpinKop];
    //ZAHARRA
    //memset(Partiketa, -1, erpinKop*sizeof(int));
    //BERRIA: Ustet horrela egin dela (lo he mirao en gologolo)
    for (int index = 0; index < erpinKop; index++){Partiketa[index]=-1;}
    
    while (sErtzKop != ertzKop - 1 && ertzOrdenatuak!=NULL)
    {    
        //Nodoa iteratu, hurrengoa eta hurrengoa lortu arte.NULL izan arte.
        //Horrela lortu dezakgu listako hurrengo ertz pisu gutxienekoa, bere ezaugarri guztiekin. Pisua baita!
        //Denbora kostu minimoarekin
        erpinx = ertzOrdenatuak->A;
        erpiny = ertzOrdenatuak->B;
        pisua = ertzOrdenatuak->weight;

        xBarne = BILATU3(Partiketa, erpinx);
        yBarne = BILATU3(Partiketa, erpiny);

        if (yBarne != xBarne)
        {
            BATERATU3(Partiketa, xBarne, yBarne);
            ErantsiErt(sErtzKop, erpinx, erpiny, pisua);
            sErtzKop++;
        }      
        ertzOrdenatuak=ertzOrdenatuak->next;
    }

}

//KRUSKAL funtzioko emaitz aldagaian egin behar dira aldaketak
//C-n ez dakidanez programatzen ez dakit modu hontan gordeko diren behar diren aldaketak.
void ErantsiErt(int k, int erpinx, int erpiny, float pisua)
{   
    if (Emaitza==NULL){
        Emaitza = (struct Node2*)malloc(sizeof(Node2));
        Emaitza->A=erpinx;
        Emaitza->B=erpiny;
        Emaitza->weight=pisua;
        Emaitza->next= NULL;
    }else{
        append(&Emaitza, erpinx, erpiny, pisua);
    }
}


int BILATU3(int partiketa[], int erpin){
    int etiketa = erpin;
    while (partiketa[etiketa]>=0)
    {
        etiketa = partiketa[etiketa];
    }
    return etiketa;
}

//Funtzioak KRUSKAL funtzioko Partiketa array-ean egin behar ditu aldaketak
//Ez dakit erreferentzia pasata ondo egiten duen. 
void BATERATU3(int partiketa[], int erpinx, int erpiny){
    int x = partiketa[erpinx];
    int y = partiketa[erpiny];
    if (x == y)
    {
        partiketa[erpinx]--;
        partiketa[erpiny] = erpinx;
    }else if (x < y)
    {
        partiketa[erpiny] = erpinx;
    }else
    {
        partiketa[erpinx] = erpiny;
    }
    
    
}
