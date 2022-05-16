#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "IN_script.h"
#include "Prim.h"

int in(void)
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
    const int SZ = ftell(input_file);
    fseek(input_file, 0L, SEEK_SET);

    // Hasieraketa guztiak
    char *contents = NULL;
    size_t len = 0;
    int i, lehen_buelta=0;
    float a=0.0;


    //Lehen lerroa irakurtzen da linkedlista hasieratzeko
    getline(&contents, &len, input_file); 
    printf("%s \n", contents);
    
    char str[strlen(contents)] ;
    strcpy(str, contents);
    int init_size = strlen(str);
    char delim[] = " ";

    char *ptr = strtok(str, delim);
    a=atof(ptr);

    //linkedlist-aren hasieraketa
    Node lista[(int)a];

   //loop honetan 3. lerrotik aurrera irakurtzen da!
    while ((getline(&contents, &len, input_file) != -1) && (i <= SZ))
    {   
        if (lehen_buelta!=0){
            char str[strlen(contents)] ;
            strcpy(str, contents);
            int init_size = strlen(str);
            char delim[] = " ";

            char *ptr = strtok(str, delim);

            while(ptr != NULL)
            {
                printf("'%s'\n", ptr);
                a=atof(ptr);
                ptr = strtok(NULL, delim);
            }

        }else{
           lehen_buelta++; 
        }
    }



    //====== HEMENDIK AURRERA LANA EGIN DAITEKE strs BEKTOREAREKIN =========
    //
    //			Sartu zure kodigoa hemen
    //
    //    Emaitza guztiak fitxategi batean jasotzen joango nintzateke
    //    exekuzio denbora ondo kontrolatzeko (adibidez, Output.txt)
    //    eta gero printOut-ak aparte egingo nituzke OUT_script-arekin.
    //
    //======================================================================

    
    // Bukatzerakoan fitxategia itxi eta rekursoak liberatu
    fclose(input_file);
    free(contents);

    exit(EXIT_SUCCESS);
}


int in2()
{
    //1
    FILE *filePointer;
    char ch;

    //2
    filePointer = fopen("grafoak/gp_7n16a.txt", "r");

    //3
    if (filePointer == NULL)
    {
        printf("File is not available \n");
    }
    else
    {
        //4
        while ((ch = fgetc(filePointer)) != EOF)
        {   //if(ch!=" " || ch!="\n"){
                printf("%c", ch);
            //}
        }
    }

    //5
    fclose(filePointer);

    return 0;
}

