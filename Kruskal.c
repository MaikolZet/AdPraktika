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

a: #ertz; p: #erpin
*/

/*
PisuenGoranzkoOrdenaJarraituzOrdenatu(G, a, gEO); eginda ekarri
ertzOrdenatuak--> ertzen zerrenda ordenatua pisuarekiko
*/

void KRUSKAL(int ertzKop, int erpinKop, Node2 *ertzOrdenatuak)
{
    int sErtzKop = 0, xBarne, yBarne, erpinx, erpiny;
    float pisua;
    /*Node2 hzm = NULL;*/
    ertz emaitz[ertzKop];
    struct Node2 *iteratzaile;
    iteratzaile = (Node2*)malloc(sizeof(Node2));
    iteratzaile = ertzOrdenatuak;
    //Hasieratu partiketa {-1, -1, ... , -1} izan dadin memorian
    int Partiketa[erpinKop];
    memset(Partiketa, -1, erpinKop*sizeof(int));

    while (sErtzKop != ertzKop - 1)
    {
        //Nodoa iteratu, hurrengoa eta hurrengoa lortu arte.NULL izan arte.
        //Horrela lortu dezakgu listako hurrengo ertz pisu gutxienekoa, bere ezaugarri guztiekin. Pisua baita!
        //Denbora kostu minimoarekin
        erpinx = iteratzaile->A;
        erpiny = iteratzaile->B;
        pisua = iteratzaile->weight;

        xBarne = BILATU3(Partiketa, erpinx);
        yBarne = BILATU3(Partiketa, erpiny);
        if (yBarne != xBarne)
        {
            BATERATU3(Partiketa, xBarne, yBarne);
            /*ErantsiErt(&hzm, erpinx, erpiny);// logikoki: hzm[sErtzKop]=(erpinx,erpiny);*/
            ErantsiErt(emaitz,sErtzKop, erpinx, erpiny, pisua);
            sErtzKop++;
        }
        iteratzaile = iteratzaile->next;
    }
}

//KRUSKAL funtzioko emaitz aldagaian egin behar dira aldaketak
//C-n ez dakidanez programatzen ez dakit modu hontan gordeko diren behar diren aldaketak.
void ErantsiErt(ertz emaitz[], int k, int erpinx, int erpiny, float pisua)
{   
    emaitz[k].A = erpinx;
    emaitz[k].B = erpiny;
    emaitz[k].weight = pisua;
}


int BILATU3(int partiketa[], int erpin){
    int etiketa = erpin;
    while (partiketa[etiketa]>0)
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

/*
void ErantsiErt(Node2 * hzm, int erpinx, int erpiny)

{   
    struct Node2 *nodoBerria = malloc(sizeof(struct Node2));
    //create a new node
    
    nodoBerria->A = erpinx;
    nodoBerria->B = erpiny;
    nodoBerria->weight = erpiny;
    nodoBerria->next = NULL;

    //if head is NULL, it is an empty list
    if(hzm == NULL)
         hzm = nodoBerria;
    //Otherwise, find the last node and add the newNode
    else
    {
        struct Node2 *erro = hzm;
        
        //last node's next address will be NULL.
        while(erro->next != NULL)
        {
            erro = erro->next;
        }

        //add the newNode at the end of the linked list
        erro->next = nodoBerria;
    }
}
*/
