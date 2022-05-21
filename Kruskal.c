#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Kruskal.h"
#include "lag.h"

// METROPOLISA

/*
Memoria-estra:
    - O(a) lista_kruskal--> ertzen lista dinamikoa ordenatua pisuarekiko handienetik txikienera
    - O(a) Emaitza--> gehienez ertz guztiak izango dituen lista dinamikoa
    - O(1) azkena--> emaitzen listaren amaiera gordetzen duen nodoa
    - O(1) berri--> emaitzen listan sartu beharreko nodo berria 
    - O(2) ema--> ertz eta erpin kopuru totala gordetzen dituen bektorea
    - O(p) Partiketa[p]--> partiketa bektorea, erpin kopurua izango da luzeera
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
{   //Erazagupenak
    int xBarne, yBarne, erpinx, erpiny;
    float pisua;
    /*Hasieraketak*/
    /*KOSTUAK: Konstanteak dira*/
    int erpinKop=ema[0]; //p
    int ertzKop=ema[1]; //a
    sErtzKop = 0;
    pisuMet = 0;

    //Partiketa erazagutu
    int Partiketa[erpinKop];

    //Hasieratu partiketa {-1, -1, ... , -1} izan dadin memorian
    //KOSTUA: O(p), p izanik erpin kopurua
    for (int index = 0; index < erpinKop; index++){Partiketa[index]=-1;}
    
    /*
    Begizta honetan partiketa garatzen da, ertz guztiak iteratuz eta emaitzan sartu daitezken konprobatuz.
    KOSTUA:Ertz guztiak iteratu kasu okerrenean O(a)
    sErtzKop != ertzKop - 1  baldintza algoritmoan agertzen da, baina gure  
    kasuan lista dinamikoa amaitzearen baliokide da
    */
    while (lista_kruskal!=NULL)
    {    
        
        /*Horrela lortu ditugu listako hurrengo ertzen informazioa*/
        erpinx = lista_kruskal->A;
        erpiny = lista_kruskal->B;
        pisua = lista_kruskal->weight;

        /*Emandako erpina emanda etiketa  lortu.
        KOSTUA: O(p)*/
        xBarne = BILATU3(Partiketa, erpinx);
        yBarne = BILATU3(Partiketa, erpiny);

        /*Etiketak berdinak badira zikloa dagoela esan nahi du*/
        if (yBarne != xBarne)
        {
            /*Bi erpinen etiketak emanda, konparatu eta dagokion aldaketa egin partiketan*/
            /*KOSTUA: Konstantea da*/
            BATERATU3(Partiketa, xBarne, yBarne);
            /*Ertza emaitzan gehitu*/
            /*KOSTUA: Konstantea da*/
            ErantsiErt(sErtzKop, erpinx, erpiny, pisua);
            /*Emaitzako ertz kopuruan +1 egin*/
            /*KOSTUA: Konstantea da*/
            sErtzKop++;
            /*Emaitzaren pisu metatuari gehitu momentuko ertzaren pisua*/
            /*KOSTUA: Konstantea da*/
            pisuMet += pisua;
        }      
        /*Nodoa iteratu, hurrengoa eta hurrengoa lortu arte.NULL izan arte.*/
        lista_kruskal=lista_kruskal->next;
    }

}

//Emaitzean gordetzen du emandako ertza, nodo berriak sortu behar bada.
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

/*Partiketan erpinaren sakonera bilatzen du. Etiketa bat badu ordea, etiketa horren
partiketako posiziora joango da eta gauza bera egingo du sakonera aurkitu arte.
Azkenik, sakoneradun erpinaren etiketa bueltatu.*/
int BILATU3(int partiketa[], int erpin){
    int etiketa = erpin;
    while (partiketa[etiketa]>=0)
    {
        etiketa = partiketa[etiketa];
    }
    return etiketa;
}

/*
Bi erpinen etiketak emanda, konparatu eta dagokion aldaketa egin partiketan:
    - Erpinen sakonerak berdinak badira lehen erpinari sakonera handitu eta bigarrenari lehen erpinaren etiketa esleitzen dio
    - Bestela, sakonera txikiena duen erpinari esleitzen diot sakonera handiena duen erpinaren etiketa
*/
void BATERATU3(int partiketa[], int erpinx, int erpiny){
    int x = partiketa[erpinx]; //sakonera x erpinarena
    int y = partiketa[erpiny]; //sakonera y erpinarena
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
