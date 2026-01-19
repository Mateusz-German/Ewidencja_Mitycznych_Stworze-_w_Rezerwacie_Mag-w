#include <stdio.h>
#include "stworzenia.h"

int main(void) {
    Stworzenie s = {
        "Smaug",
        "Smok",
        95,
        10,
        "2243-06-12",
        NIEBEZPIECZNY
    };

    Stworzenie s2 = {
        "Fenix",
        "Feniks",
        70,
        4,
        "2243-06-10",
        STABILNY
    };
    s.next = &s2;
    s2.next = NULL;


    Stworzenie* aktualne = &s;

    while (aktualne != NULL) {
        printStworzenie(aktualne);
        aktualne = aktualne->next;
    }



    return 0;
}
