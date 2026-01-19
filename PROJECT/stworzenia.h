#ifndef STWORZENIA_H
#define STWORZENIA_H

#define STWORZENIA_H

#define imie_dlugosc 100
#define gatunek_dlugosc 30
#define data_dlugosc 20

typedef enum {
    STABILNY,
    NIESPOKOJNY,
    AGRESYWNY,
    NIEBEZPIECZNY,
    KWARANTANNA
} StatusStworzenia;

typedef struct {
    char imie[imie_dlugosc];
    char gatunek[gatunek_dlugosc];
    int poziom_mocy;
    int poziom_niebezpieczenstwa;
    char data_karmienia[data_dlugosc];
    StatusStworzenia status;
} Stworzenie;


#endif
