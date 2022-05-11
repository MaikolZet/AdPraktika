#include "Lag.h"
#include <stdio.h>


/*ROSAN KODEA


void PRIM (int G[][], int p, ertzPisuPos hzm []){
int PisuMin[p], Auzokide[p];
int k,ind, j,z, minP, sLuz=0; // = MultzoHutsaErt (hzm);
PisuMin[0]=-1;
for (k=1; k<p; k++)
// ERT-ko lehen erpina 0 da. Besteek haraino duten distantziaz hasieratu
{Auzokide[k]= 0; PisuMin[k]= G[k][0]; }
for (sLuz=0; sLuz<(p-1); sLuz++) {// #(p-1) aldiz
minP = 99999999;
for (j=1; j<p; j++){ // 1..p-1
    if (-1<PisuMin[j] && PisuMin[j] < minP){minP=PisuMin[j]; k=j;}
}
// k harrapatzen du hzm-k;
ErantsiErt(hzm,k,Auzokide[k],PisuMin[k], sLuz );
// ≅sErt[sLuz]=(k,Auzokide[k], PisuMin[k])
PisuMin[k]= -1;
for (z=1; z<p; z++ ){ //k-ren auzokideeak direnak
    if (G[k][j]<PisuMin[z]) {PisuMin[z]= G[k][z]; Auzokide[z]=k; }
}
}

void ErantsiErt(ertzPisuPos hzm [],int k,int Auzokide [],int PisuMin [],int sluz){
    //TODO
}
*/
void main2(void){
    printf("Auxilio");
}
