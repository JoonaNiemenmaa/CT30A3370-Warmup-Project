#define _GNU_SOURCE

#include <stddef.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
    FILE *Sisaan = NULL;
    FILE *Ulos = NULL;

    switch (argc) {
        case 1:
            Sisaan = stdin;
            Ulos = stdout;
            break;
        case 2:
            if ((Sisaan = fopen(argv[1], "r")) == NULL) {
                fprintf(stderr, "Tiedoston '%s' avaamisessa virhe, lopetetaan: ", argv[1]);
                perror("");
                exit(1);
            }
            Ulos = stdout;
            break;
        case 3:
            if (strcmp(argv[1], argv[2]) == 0) {
                fprintf(stderr, "Syötetiedosto ja tulostetiedosto eivät voi olla samat.\n");
                exit(1);
            }

            if ((Sisaan = fopen(argv[1], "r")) == NULL) {
                fprintf(stderr, "Tiedoston '%s' avaamisessa virhe, lopetetaan: ", argv[1]);
                perror("");
                exit(1);
            }
            if ((Ulos = fopen(argv[2], "w")) == NULL) {
                fprintf(stderr, "Tiedoston '%s' avaamisessa virhe, lopetetaan: ", argv[2]);
                perror("");
                exit(1);
            }
            break;
        default:
            fprintf(stderr, "Käyttö: reverse <syöte> <tuloste>\n");
            exit(1);
            break;
    }

    char **aRivit = NULL;
    char *aVali = NULL;
    int iRivit = 0;
    char *aRivi = NULL;
    size_t iRivi = 0;

    while (getline(&aRivi, &iRivi, Sisaan) != -1) {
        iRivit++;
        if ((aRivit = (char **)realloc(aRivit, sizeof(char *) * iRivit)) == NULL) {
            perror("Muistin varaamisessa virhe, lopetetaan");
            exit(1);
        }
        if ((aVali = (char *)malloc(sizeof(char *) * (strlen(aRivi) + 1))) == NULL) {
            perror("Muistin varaamisessa virhe, lopetetaan");
            exit(1);
        }
        strcpy(aVali, aRivi);
        aRivit[iRivit - 1] = aVali;
    }
    if (aRivi != NULL) {
        free(aRivi);
        aRivi = NULL;
    }

    for (int i = iRivit - 1; i >= 0; i--) {
        fprintf(Ulos, "%s", aRivit[i]);
        free(aRivit[i]);
    }
    if (aRivit != NULL) {
        free(aRivit);
    }

    if (Ulos != stdout) {
        fclose(Ulos);
    }

    if (Sisaan != stdin) {
        fclose(Sisaan);
    }

    return 0;
}
