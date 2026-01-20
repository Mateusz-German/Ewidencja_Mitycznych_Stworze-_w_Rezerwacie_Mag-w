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

void dodajNaPoczatek(Stworzenie** lista, Stworzenie* nowy) {
    if (nowy == NULL) {
        return;
    }

    nowy->next = *lista;
    *lista = nowy;
}

void zwolnijListe(Stworzenie* lista) {
    Stworzenie* tmp;

    while (lista != NULL) {
        tmp = lista;
        lista = lista->next;
        free(tmp);
    }
}


void znajdzPoImieniu(Stworzenie* lista, const char* imie) {
    int znaleziono = 0;

    while (lista != NULL) {
        if (strcmp(lista->imie, imie) == 0) {
            printStworzenie(lista);
            znaleziono = 1;
        }
        lista = lista->next;
    }

    if (!znaleziono) {
        printf("Nie znaleziono stworzenia o imieniu: %s\n", imie);
    }
}

void znajdzPoNiebezpieczenstwie(Stworzenie* lista, int min_poziom) {
    int znaleziono = 0;

    while (lista != NULL) {
        if (lista->poziom_niebezpieczenstwa >= min_poziom) {
            printStworzenie(lista);
            znaleziono = 1;
        }
        lista = lista->next;
    }

    if (!znaleziono) {
        printf("Brak stworzen o poziomie niebezpieczenstwa >= %d\n", min_poziom);
    }
}

Stworzenie* kopiujListe(Stworzenie* lista) {
    Stworzenie* nowaLista = NULL;
    Stworzenie* aktualne = lista;

    while (aktualne != NULL) {
        Stworzenie* kopia = utworzStworzenie(
            aktualne->imie,
            aktualne->gatunek,
            aktualne->poziom_mocy,
            aktualne->poziom_niebezpieczenstwa,
            aktualne->data_karmienia,
            aktualne->status
        );

        dodajNaPoczatek(&nowaLista, kopia);
        aktualne = aktualne->next;
    }

    return nowaLista;
}

void sortujPoImieniu(Stworzenie* lista) {
    if (lista == NULL) return;

    int zamiana;
    Stworzenie* a;
    Stworzenie* b;

    do {
        zamiana = 0;
        a = lista;

        while (a->next != NULL) {
            b = a->next;

            if (strcmp(a->imie, b->imie) > 0) {

                Stworzenie tmp = *a;
                *a = *b;
                *b = tmp;


                Stworzenie* t = a->next;
                a->next = b->next;
                b->next = t;

                zamiana = 1;
            }
            a = a->next;
        }
    } while (zamiana);
}

void sortujPoMocy(Stworzenie* lista) {
    if (lista == NULL) return;

    int zamiana;
    Stworzenie* a;
    Stworzenie* b;

    do {
        zamiana = 0;
        a = lista;

        while (a->next != NULL) {
            b = a->next;

            if (a->poziom_mocy > b->poziom_mocy) {
                Stworzenie tmp = *a;
                *a = *b;
                *b = tmp;

                Stworzenie* t = a->next;
                a->next = b->next;
                b->next = t;

                zamiana = 1;
            }
            a = a->next;
        }
    } while (zamiana);
}

void zapiszDoPliku(Stworzenie* lista, const char* nazwa_pliku) {
    FILE* plik = fopen(nazwa_pliku, "w");
    if (plik == NULL) {
        printf("Nie mozna otworzyc pliku!\n");
        return;
    }

    while (lista != NULL) {
        fprintf(
            plik,
            "%s;%s;%d;%d;%s;%d\n",
            lista->imie,
            lista->gatunek,
            lista->poziom_mocy,
            lista->poziom_niebezpieczenstwa,
            lista->data_karmienia,
            lista->status
        );
        lista = lista->next;
    }

    fclose(plik);
}





