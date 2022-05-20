#include <stdio.h>
#include "OUT_script.h"
#include "IN_script.h"
#include "lag.h"
#include "Prim.h"
#include "Kruskal.h"
#include <time.h>
#define elemkop(x)  (sizeof(x) / sizeof((x)[0]))

void prim(int nodokop);
void kruskal();
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

extern Node2* Emaitza;

int main(void){



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
    
    //Fitxategien irakurketa:
    int nodoKop = in(filename0);

    //Algoritmoaren exekuzioa:
    prim(nodoKop);
   
    
    
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
    
    //Fitxategien irakurketa:
    in2(filename0);

    //Algoritmoaren exekuzioa:
    kruskal();
    


    //================================================//
                     printf("\n\n");
    //================================================//



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
    PRIM_MAX(nodoKop,hzm);
    // 2.3- Emaitzen pantailaraketa
    for (int i = 0; i < nodoKop - 1; i++){ 
        printf("from %d to %d, with weight: %f \n", hzm[i].A, hzm[i].B, hzm[i].weight);
    }

    // 3- Denboragailuaren amaiera
    t = clock() - t;
    double time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds
    printf("========= \n");
    printf("prim() exekutatzeko %f segundu behar izan dira \n\n\n", time_taken);

    
}

void kruskal(){

    //Donde se ejekuta la magia
    printf("Kruskal ejekutatzen ari da:: \n");
    printf("========= \n");
    
    // 1- Denboragailuaren hasieraketa
    clock_t t;
    t = clock();
    // 2.2- Algoritmoareren exekuzioa
    KRUSKAL();
    // 2.3- Emaitzen pantailaraketa
    while(Emaitza!=NULL)
    {
        printf("from %d to %d, with weight: %f \n", Emaitza->A, Emaitza->B, Emaitza->weight);
        Emaitza = Emaitza->next;
    }

    // 3- Denboragailuaren amaiera
    t = clock() - t;
    double time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds
    printf("========= \n");
    printf("kruskal() exekutatzeko %f segundu behar izan dira \n\n\n", time_taken);

    
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