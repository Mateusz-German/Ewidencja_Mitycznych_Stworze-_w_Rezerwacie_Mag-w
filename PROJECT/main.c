#include <stdio.h>
#include "stworzenia.h"


int main(void) {
    Stworzenie* lista = NULL;
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

    dodajNaPoczatek(&lista, s1);
    dodajNaPoczatek(&lista, s2);


    Stworzenie* aktualne = lista;

    while (aktualne != NULL) {
        printStworzenie(aktualne);
        aktualne = aktualne->next;
    }

    printf("\nWyszukiwanie po imieniu:\n");
    znajdzPoImieniu(lista, "Smaug");
    printf("\nWyszukiwanie po poziomie niebezpieczenstwa >= 5:\n");
    znajdzPoNiebezpieczenstwie(lista, 5);

    printf("\nLista posortowana alfabetycznie po imieniu:\n");

    Stworzenie* kopia = kopiujListe(lista);
    sortujPoImieniu(kopia);

    Stworzenie* tmp = kopia;
    while (tmp != NULL) {
        printStworzenie(tmp);
        tmp = tmp->next;
    }

    zwolnijListe(kopia);





    zwolnijListe(lista);

    return 0;
}
