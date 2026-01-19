#include <stdio.h>
#include "stworzenia.h"
#include <stdlib.h>
#include <string.h>

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

Stworzenie* utworzStworzenie(
    const char* imie,
    const char* gatunek,
    int moc,
    int niebezpieczenstwo,
    const char* data,
    StatusStworzenia status
) {
    Stworzenie* s = malloc(sizeof(Stworzenie));
    if (s == NULL) {
        return NULL;
    }

    strcpy(s->imie, imie);
    strcpy(s->gatunek, gatunek);
    s->poziom_mocy = moc;
    s->poziom_niebezpieczenstwa = niebezpieczenstwo;
    strcpy(s->data_karmienia, data);
    s->status = status;
    s->next = NULL;

    return s;
}
