#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(void)
{
    // Fitxategiaren izena definitu
    const char *filename = "input.txt";

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
    int i = 0;

    // Hau string bektorearen hasieraketa da, lehen zenbakia bektoreak
    // izango dituen posizio kopurua da, eta bigarrena posizio bakoitzak
    // izango dituen karaktere kopuru maximoa. Bigarren zenbaki honetan
    // ez dakit zenbat jarri, asike printzipioz 150 jarriet, como lo veis??
    char strs[SZ][150];
    // NOTA: SZ-k errorea emateu baino berez ondo dao, se supone. Por lo que
    // he leido por ahi es error de VScode, pero cuando compilas funca bien
    

    // getline funtzioak irakurritako lerroaren luzeera bueltatzen du
    // eta -1 bada, orduan errorea!
    while ((getline(&contents, &len, input_file) != -1) && (i <= SZ))
    {
        //&contents-ekin egin behar dugu lana, hori da String-a

        // Ez nago zihur honek funtzionatzen duen edo ez, baino ustedut
        // String bektore bat atzitzeko horrela egin behar dela
        strcpy(strs[i], contents);
        i++;
    }

    // Bukatzerakoan fitxategia itxi eta rekursoak liberatu
    fclose(input_file);
    free(contents);

    exit(EXIT_SUCCESS);

    //====== HEMENDIK AURRERA LANA EGIN DAITEKE strs BEKTOREAREKIN =========
    //
    //			Sartu zure kodigoa hemen
    //
    //    Emaitza guztiak fitxategi batean jasotzen joango nintzateke
    //    exekuzio denbora ondo kontrolatzeko (adibidez, Output.txt)
    //    eta gero printOut-ak aparte egingo nituzke OUT_script-arekin.
    //
    //======================================================================
}