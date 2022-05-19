#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "IN_script.h"
#include "lag.h"
//Solucion de mierda ezin da modu globalean utxik utzi eta listak zenbat dittun jakitteko ezinbestekoa da irakurtzea artxiboa
Node lista[10000];
struct Node2* lista_kruskal;

//FOR PRIM
int in(const char *filename){
    
    // Fitxategia ireki fopen-ekin
    FILE *input_file = fopen(filename, "r");

    // Fitxategirik ezin bada ireki (izena gaizki dagoelako adibidez)
    // Errorea bueltatu
    if (!input_file)
        exit(EXIT_FAILURE);

    // Fitxategiaren luzeera kalkulatzeko
    fseek(input_file, 0L, SEEK_END);
    fseek(input_file, 0L, SEEK_SET);

    // Hasieraketa guztiak
    char *contents = NULL;
    size_t len = 0;
    int i, a, v = -1;
    float pisua = 0.0;
    // Lehen lerroa irakurtzen da linkedlista hasieratzeko
    getline(&contents, &len, input_file);

    char str[strlen(contents)];
    strcpy(str, contents);
    char delim[] = " ";

    char *ptr = strtok(str, delim);
    a = atoi(ptr);

    // linkedlist-aren hasieraketa
    for (int j = 0; j < a; j++)
    {
        lista[j].data = -1;
        lista[j].next = 0;
    }
    Node *lag;
    getline(&contents, &len, input_file);

    // loop honetan 3. lerrotik aurrera irakurtzen da!
    while ((getline(&contents, &len, input_file) != -1))
    {

        strcpy(str, contents);
        ptr = strtok(str, delim);
        if (v != atoi(ptr))
        {
            lag = 0;
        }
        v = atoi(ptr);
        ptr = strtok(NULL, delim);
        i = atoi(ptr);
        ptr = strtok(NULL, delim);
        pisua = atof(ptr);
        //printf("======%s, %f====== \n",ptr, pisua);
        if (lag != 0)
        {
            lag->next = (Node *)malloc(sizeof(Node));
            lag = lag->next;
        }
        else
        {
            lag = &lista[v];
            lag->next = (Node *)malloc(sizeof(Node));
            lag = lag->next;
        }
        lag->data = i;
        lag->weight = pisua;
        lag->next = 0;
    }


    //PRINT-AK ikusteko deskomentatu hau
    // for (int j = 0; j < a; j++)
    // {   
    //     printf("Nodo honetatik: %d Hauetara joan daiteke ", j);
    //     lag = &lista[j];
    //     printf("(%d eta %f) , ",lag->data, lag->weight);
    //     lag = lag->next;
    //     while (lag != 0)
    //     {
    //         printf("(%d eta %f) , ",lag->data, lag->weight);
    //         lag = lag->next;
    //     }
    //     printf("\n");
    // }

    fclose(input_file);
    free(contents);
    return a;
}

//FOR KRUSKAL
int in2(const char *filename){

    // Fitxategia ireki fopen-ekin
    FILE *input_file = fopen(filename, "r");

    // Fitxategirik ezin bada ireki (izena gaizki dagoelako adibidez)
    // Errorea bueltatu
    if (!input_file)
        exit(EXIT_FAILURE);

    // Fitxategiaren luzeera kalkulatzeko
    fseek(input_file, 0L, SEEK_END);
    fseek(input_file, 0L, SEEK_SET);

    // Hasieraketa guztiak
    char *contents = NULL;
    size_t len = 0;
    int i, a, v = -1;
    int lehena=0;
    float pisua = 0.0;
    // Lehen lerroa irakurtzen da linkedlista hasieratzeko
    getline(&contents, &len, input_file);
    getline(&contents, &len, input_file);
    
    char str[strlen(contents)];
    strcpy(str, contents);
    char delim[] = " ";
    char *ptr = strtok(str, delim);

    // loop honetan 3. lerrotik aurrera irakurtzen da!
    while ((getline(&contents, &len, input_file) != -1))
    {
       
        if (lehena==0){
            //LISTAREN LEHEN NODOA HASIERATU

            strcpy(str, contents);
            
            //Ertza (v, i)
            ptr = strtok(str, delim);
            v = atoi(ptr);
            ptr = strtok(NULL, delim);
            i = atoi(ptr);
            //Weight
            ptr = strtok(NULL, delim);
            pisua = atof(ptr);

            lehena++;
            lista_kruskal = (struct Node2*)malloc(sizeof(Node2));
            lista_kruskal->A=v;
            lista_kruskal->B=i;
            lista_kruskal->weight=pisua;
            lista_kruskal->next= NULL;

        }else{
            strcpy(str, contents);
            
            //Ertza (v, i)
            ptr = strtok(str, delim);
            v = atoi(ptr);
            ptr = strtok(NULL, delim);
            i = atoi(ptr);
            //Weight
            ptr = strtok(NULL, delim);
            pisua = atof(ptr);
            push(&lista_kruskal, v, i, pisua);
            
        }
        
    }
    MergeSort(&lista_kruskal);
    fclose(input_file);
    free(contents);
    return a;
}


//DAGOENEKO EZ DA BEHAR BORRATU DAITEKE
int geta(char *filename){

    // Fitxategia ireki fopen-ekin
    FILE *input_file = fopen(filename, "r");

    // Fitxategirik ezin bada ireki (izena gaizki dagoelako adibidez)
    // Errorea bueltatu
    if (!input_file)
        exit(EXIT_FAILURE);

    // Fitxategiaren luzeera kalkulatzeko
    fseek(input_file, 0L, SEEK_END);
    fseek(input_file, 0L, SEEK_SET);

    // Hasieraketa guztiak
    char *contents = NULL;
    size_t len = 0;
    // Lehen lerroa irakurtzen da linkedlista hasieratzeko
    getline(&contents, &len, input_file);

    char str[strlen(contents)];
    strcpy(str, contents);
    char delim[] = " ";

    char *ptr = strtok(str, delim);
    return atoi(ptr);
}

