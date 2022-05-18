#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "IN_script.h"

//Solucion de mierda ezin da modu globalean utxik utzi eta listak zenbat dittun jakitteko ezinbestekoa da irakurtzea artxiboa
Node lista[10000];

Node* in(void)
{
    // Fitxategiaren izena definitu
    const char *filename = "grafoak/gp_7n16a.txt";

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
    printf("%s \n", contents);

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

    for (int j = 0; j < a; j++)
    {

        printf("Nodo honetatik: %d Hauetara joan daiteke ", j);
        lag = &lista[j];
        printf("%d , ", lag->data);
        lag = lag->next;
        while (lag != 0)
        {
            printf("%d , ", lag->data);
            lag = lag->next;
        }
        printf("\n");
    }
    fclose(input_file);
    free(contents);
    return &lista[0];
}

int geta(){
    // Fitxategiaren izena definitu
    const char *filename = "grafoak/gp_7n16a.txt";

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
    printf("%s \n", contents);

    char str[strlen(contents)];
    strcpy(str, contents);
    char delim[] = " ";

    char *ptr = strtok(str, delim);
    return atoi(ptr);
}

