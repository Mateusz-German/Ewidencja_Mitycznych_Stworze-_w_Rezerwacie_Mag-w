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

typedef struct Stworzenie {
    char imie[imie_dlugosc];
    char gatunek[gatunek_dlugosc];
    int poziom_mocy;
    int poziom_niebezpieczenstwa;
    char data_karmienia[data_dlugosc];
    StatusStworzenia status;

    struct Stworzenie* next;
} Stworzenie;

const char* statusNaString(StatusStworzenia status);
void printStworzenie(const Stworzenie* s);

Stworzenie* utworzStworzenie(
    const char* imie,
    const char* gatunek,
    int moc,
    int niebezpieczenstwo,
    const char* data,
    StatusStworzenia status
);


#endif
