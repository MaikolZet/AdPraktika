#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Kruskal.h"
#include "lag.h"

// METROPOLISA

/*
PisuenGoranzkoOrdenaJarraituzOrdenatu(G, a, gEO); eginda ekarri
ertzOrdenatuak--> ertzen zerrenda ordenatua pisuarekiko
*/
extern int ema[];
extern Node2* lista_kruskal;

struct Node2* Emaitza;
struct Node2* azkena;
struct Node2* berri;

int sErtzKop;
int pisuMet;
int lehena=0;

double baturaKruskal=0;


void KRUSKAL()
{   
    struct Node2 * ertzOrdenatuak = (Node2 *)malloc(sizeof(Node2));
    ertzOrdenatuak->A= lista_kruskal->A;
    ertzOrdenatuak->B= lista_kruskal->B;
    ertzOrdenatuak->weight= lista_kruskal->weight;
    ertzOrdenatuak->next= lista_kruskal->next;
    
    int erpinKop=ema[0];
    int ertzKop=ema[1];
    sErtzKop = 0;
    pisuMet = 0;

    int xBarne, yBarne, erpinx, erpiny;
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
            pisuMet += pisua;
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
        azkena = (struct Node2*)malloc(sizeof(Node2));
        Emaitza->A=erpinx;
        Emaitza->B=erpiny;
        Emaitza->weight=pisua;
        Emaitza->next= NULL;
        azkena = Emaitza;
        baturaKruskal+=Emaitza->weight;
    }else{
        berri = (struct Node2*)malloc(sizeof(Node2));
        berri->A=erpinx;
        berri->B=erpiny;
        berri->weight=pisua;
        berri->next = NULL;
        azkena->next= berri;
        azkena = berri;
        baturaKruskal+=berri->weight;
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
