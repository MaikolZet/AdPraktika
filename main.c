#include <stdio.h>
#include <stdlib.h>
#include "OUT_script.h"
#include "IN_script.h"
#include "lag.h"
#include "Prim.h"
#include "Kruskal.h"
#include <time.h>
#define elemkop(x)  (sizeof(x) / sizeof((x)[0]))

void menu();
void prim();
void kruskal();
void printPrim();
void printKruskal();

extern Node2* Emaitza;
extern double baturaPrim;
extern double baturaKruskal;
extern int sErtzKop;

// Fitxategien izena definitu
const char *filename;
const char *filename0 = "grafoak/gp_7n16a.txt";
const char *filename1 = "grafoak/gp_9n36a.txt";
const char *filename2 = "grafoak/gp_100n1000a.txt";
const char *filename3 = "grafoak/gp_200n396a.txt";
const char *filename4 = "grafoak/gp_250n1273a.txt";
const char *filename5 = "grafoak/gp_1000n8433a.txt";
const char *filename6 = "grafoak/gp_10000n61731a.txt";


int main(void){
    
    
    
    //================================================//
                     printf("\n\n");
    //================================================//
    



    menu();



    //================================================//
                     printf("\n\n");
    //================================================//
    


    printPrim();
    //==============================//
    //                              //      
    //   &&&&   &&&&   &  &&   &&   //                   
    //   &   &  &   &  &  & & & &   //                          
    //   &&&&   &&&&   &  &  &  &   //
    //   &      &  &   &  &     &   //
    //   &      &  &   &  &     &   //             
    //                              //    
    //==============================//
    
    //Algoritmoaren exekuzioa:
    printf("\nPrim exekutatzen ari da: \n");
    printf("========= \n\n");
    prim();
    printf("========= \n");
   
    
    
    //================================================//
                     printf("\n\n");
    //================================================//



    printKruskal();
    //================================================//
    //                                                //      
    //   &  &  &&&&   &  &   &&&   &  &  &&&&   &     //                   
    //   & &   &   &  &  &  &      & &   &  &   &     //                          
    //   &&    &&&&   &  &   &&&   &&    &&&&   &     //
    //   & &   &  &   &  &      &  & &   &  &   &     //
    //   &  &  &  &   &&&&   &&&   &  &  &  &   &&&&  //             
    //                                                //    
    //================================================//

    //Algoritmoaren exekuzioa:  
    printf("\nKruskal exekutatzen ari da: \n");
    printf("========= \n\n");
    kruskal();
    printf("========= \n");
  


    //================================================//
                     printf("\n\n");
    //================================================//



}


//Aukera menua
void menu(){
    int aukera;
    printf("\n\n Sartu ireki erabili nahi duzun fitxategiaren zenbakia: \n");
    printf("    1- grafoak/gp_7n16a.txt\n");
    printf("    2- grafoak/gp_9n36a.txt\n");
    printf("    3- grafoak/gp_100n1000a.txt\n");
    printf("    4- grafoak/gp_200n396a.txt\n");
    printf("    5- grafoak/gp_250n1273a.txt\n");
    printf("    6- grafoak/gp_1000n8433a.txt\n");
    printf("    7- grafoak/gp_10000n61731a.txt\n");
    printf("\n (idatzi hemen):");
    scanf("%d", &aukera);

    switch (aukera)
    {
    case 1:
        filename=filename0;
        break;
    case 2:
        filename=filename1;
        break;
    case 3:
        filename=filename2;
        break;
    case 4:
        filename=filename3;
        break;
    case 5:
        filename=filename4;
        break;
    case 6:
        filename=filename5;
        break;
    case 7:
        filename=filename6;
        break;
    default:
        break;
    }
}


//Donde se ejekuta la magia
void prim(){
    
    //Output fitxategiaren hasieraketa
    int num;
    FILE *out=fopen("prim_out.txt","w");
    if(out == NULL){printf("Error!");exit(1);} 

    // 1- Fitxategien irakurketa:
    clock_t t;
    t = clock();
    int nodoKop = in(filename);   
    t = clock() - t;
    float time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds
    printf("Fitxategitik datuak irakurtzeko:         ~~~ >  %f segundu \n\n", time_taken);

    // 2- Algoritmoareren exekuzioa
    t = clock();
    ertzPisuPos hzm [nodoKop - 1];
    PRIM(nodoKop,hzm);
    t = clock() - t;
    time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds
    printf("Prim algoritmoa exekutatzeko:            ~~~ >  %f segundu \n\n", time_taken);
    
    // 3- Emaitzen OutPut-a:
    t = clock();
    fprintf(out,"%f \n",baturaPrim);
    fprintf(out,"%d \n",nodoKop-1);
    for (int i = 0; i < nodoKop - 1; i++){ 
        fprintf(out, "%d %d %f \n", hzm[i].A, hzm[i].B, hzm[i].weight);
    }
    fclose(out);
    t = clock() - t;
    time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds
    printf("Lortutako datuak fitxategian idazteko:   ~~~ >  %f segundu \n\n", time_taken);

    
}


//Donde se ejekuta la magia
void kruskal(){

    //Output fitxategiaren hasieraketa
    FILE *out=fopen("kruskal_out.txt","w");
    if(out == NULL){printf("Error!");exit(1);}  
    
    // 1- Fitxategien irakurketa:
    clock_t t;
    t = clock();
    in2(filename);   
    t = clock() - t;
    float time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds
    printf("Fitxategitik datuak irakurtzeko:         ~~~ >  %f segundu \n\n", time_taken);

    // 2- Algoritmoareren exekuzioa
    t = clock();
    KRUSKAL();
    t = clock() - t;
    time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds
    printf("Kruskal algoritmoa exekutatzeko:         ~~~ >  %f segundu \n\n", time_taken);

    // 3- Emaitzen OutPut-a:
    t = clock();
    fprintf(out,"%f \n",baturaKruskal);
    fprintf(out,"%d \n",sErtzKop);
    while(Emaitza!=NULL)
    {
        fprintf(out, "%d %d %f \n", Emaitza->A, Emaitza->B, Emaitza->weight);
        Emaitza = Emaitza->next;
    }
    fclose(out);
    t = clock() - t;
    time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds
    printf("Lortutako datuak fitxategian idazteko:   ~~~ >  %f segundu \n\n", time_taken);

}


//==================FRIKADAS=================//
//             Ez da garrantzitsua           //  
//===========================================//

void printPrim(){
    
    printf("\n\n//==============================// \n");
    printf("//                              // \n");
    printf("//   &&&&   &&&&   &  &&   &&   // \n");
    printf("//   &   &  &   &  &  & & & &   // \n");
    printf("//   &&&&   &&&&   &  &  &  &   // \n");
    printf("//   &      &  &   &  &     &   // \n");
    printf("//   &      &  &   &  &     &   // \n");
    printf("//                              // \n");
    printf("//==============================// \n");

}


void printKruskal(){
    printf("//================================================// \n");
    printf("//                                                // \n");
    printf("//   &  &  &&&&   &  &   &&&   &  &  &&&&   &     // \n");
    printf("//   & &   &   &  &  &  &      & &   &  &   &     // \n");
    printf("//   &&    &&&&   &  &   &&&   &&    &&&&   &     // \n");
    printf("//   & &   &  &   &  &      &  & &   &  &   &     // \n");
    printf("//   &  &  &  &   &&&&   &&&   &  &  &  &   &&&&  // \n");
    printf("//                                                // \n");
    printf("//================================================// \n");
            
}