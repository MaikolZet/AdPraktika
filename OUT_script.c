#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>

int out(void)
{
    // Fitxategiaren izena definitu
    const char *filename = "output.txt";

    // Fitxategia ireki fopen-ekin
    FILE *input_file = fopen(filename, "r");

    // Fitxategirik ezin bada ireki (izena gaizki dagoelako adibidez)
    // Errorea bueltatu
    if (!input_file)
        exit(EXIT_FAILURE);

    // Hasieraketa guztiak
    char *contents = NULL;
    size_t len = 0;

    // getline funtzioak irakurritako lerroaren luzeera bueltatzen du
    // eta -1 bada, orduan errorea!
    while (getline(&contents, &len, input_file) != -1)
    {
        //&contents-ekin egin behar dugu lana, hori da String-a
        printf("%s", contents);
    }
    printf("\n");
    // Bukatzerakoan fitxategia itxi eta rekursoak liberatu
    fclose(input_file);
    free(contents);

    exit(EXIT_SUCCESS);
}