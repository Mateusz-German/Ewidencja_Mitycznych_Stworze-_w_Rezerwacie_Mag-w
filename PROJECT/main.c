#include <stdio.h>
#include "stworzenia.h"

int main(void) {
Stworzenie* s1 = utworzStworzenie(
    "Smaug",
    "Smok",
    95,
    10,
    "2243-06-12",
    NIEBEZPIECZNY
);

Stworzenie* s2 = utworzStworzenie(
    "Fenix",
    "Feniks",
    70,
    4,
    "2243-06-10",
    STABILNY
);

    s1->next = s2;
    s2->next = NULL;


    Stworzenie* aktualne = s1;

    while (aktualne != NULL) {
        printStworzenie(aktualne);
        aktualne = aktualne->next;
    }



    return 0;
}
