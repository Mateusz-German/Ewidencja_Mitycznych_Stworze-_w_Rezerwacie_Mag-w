#include <stdio.h>
#include "stworzenia.h"

const char* statusNaString(StatusStworzenia status) {
    switch (status) {
        case STABILNY: return "stabilny";
        case NIESPOKOJNY: return "niespokojny";
        case AGRESYWNY: return "agresywny";
        case NIEBEZPIECZNY: return "niebezpieczny";
        case KWARANTANNA: return "w kwarantannie";
        default: return "nieznany";
    }
}

void printStworzenie(const Stworzenie* s) {
    if (s == NULL) {
        printf("Brak danych o stworzeniu\n");
        return;
    }

    printf("Imie: %s\n", s->imie);
    printf("Gatunek: %s\n", s->gatunek);
    printf("Poziom mocy: %d\n", s->poziom_mocy);
    printf("Poziom niebezpieczenstwa: %d\n", s->poziom_niebezpieczenstwa);
    printf("Ostatnie karmienie: %s\n", s->data_karmienia);
    printf("Status: %s\n", statusNaString(s->status));
}
