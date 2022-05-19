#include <stdio.h>
#include "OUT_script.h"
#include "IN_script.h"
#include "lag.h"
#include "Prim.h"
#include <time.h>
#define elemkop(x)  (sizeof(x) / sizeof((x)[0]))

void prim(int nodokop);
void kruskal(int nodoKop);
void printPrim();
void printKruskal();

// Fitxategien izena definitu
const char *filename0 = "grafoak/gp_7n16a.txt";
const char *filename1 = "grafoak/gp_9n36a.txt";
const char *filename2 = "grafoak/gp_100n1000a.txt";
const char *filename3 = "grafoak/gp_200n396a.txt";
const char *filename4 = "grafoak/gp_250n1273a.txt";
const char *filename5 = "grafoak/gp_1000n8433a.txt";
const char *filename6 = "grafoak/gp_10000n61731a.txt";

int main(void){

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
    
    //Fitxategien irakurketa:
    int nodoKop = in(filename0);
    
    //Algoritmoaren exekuzioa eta kronometrazioa
    prim(nodoKop);
   


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
    
    //Fitxategien irakurketa:
    in2(filename0);

    //Algoritmoaren exekuzioa:
    kruskal(nodoKop);
    
}

//BUKATUTA
void prim(int nodoKop){
    //Donde se ejekuta la magia

    printf("Prim ejekutatzen ari da:: \n");
    printf("========= \n");
    
    // 1- Denboragailuaren hasieraketa
    clock_t t;
    t = clock();

    // 2.1- Bektorearen hasieraketa
    ertzPisuPos hzm [nodoKop - 1];
    // 2.2- Algoritmoareren exekuzioa
    PRIM(nodoKop,hzm);
    // 2.3- Emaitzen pantailaraketa
    for (int i = 0; i < nodoKop - 1; i++){ 
        printf("from %d to %d, with weight: %f \n", hzm[i].A, hzm[i].B, hzm[i].weight);
    }

    // 3- Denboragailuaren amaiera
    t = clock() - t;
    double time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds
    printf("prim() exekutatzeko %f segundu behar izan dira \n\n\n", time_taken);

    printf("========= \n");
}

void kruskal(int nodoKop){

    //Donde se ejekuta la magia
    printf("Kruskal ejekutatzen ari da:: \n");
    printf("========= \n");
    
    // 1- Denboragailuaren hasieraketa
    clock_t t;
    t = clock();

    // 2.1- Bektorearen hasieraketa
    ertzPisuPos hzm [nodoKop - 1];
    // 2.2- Algoritmoareren exekuzioa
        //TODO
    // 2.3- Emaitzen pantailaraketa
        //TODO

    // 3- Denboragailuaren amaiera
    t = clock() - t;
    double time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds
    printf("kruskal() exekutatzeko %f segundu behar izan dira \n\n\n", time_taken);

    printf("========= \n");
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