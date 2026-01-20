#include <stdio.h>
#include "stworzenia.h"


void wyswietlMenu() {
    printf("\n===== MENU =====\n");
    printf("1. Wyswietl wszystkie stworzenia\n");
    printf("2. Dodaj stworzenie\n");
    printf("3. Usun stworzenie\n");
    printf("4. Wyszukaj po imieniu\n");
    printf("5. Wyszukaj po poziomie niebezpieczenstwa\n");
    printf("6. Sortuj po mocy\n");
    printf("7. Zapisz do pliku\n");
    printf("8. Wczytaj z pliku\n");
    printf("9. Edytuj stworzenie\n");
    printf("10. Sortuj po imieniu\n");
    printf("0. Wyjscie\n");
    printf("Wybor: ");
}



int main(void) {
    int wybor;
    char nazwaPliku[100];
    Stworzenie* lista = NULL;

    do {
        wyswietlMenu();
        scanf("%d", &wybor);

        if (wybor == 1) {
            Stworzenie* tmp = lista;
            while (tmp != NULL) {
                printStworzenie(tmp);
                tmp = tmp->next;
            }
        }

        else if (wybor == 2) {
            char imie[100], gatunek[30], data[20];
            int moc, niebezp, status;

            printf("Imie: ");
            scanf("%s", imie);
            printf("Gatunek: ");
            scanf("%s", gatunek);
            printf("Moc: ");
            scanf("%d", &moc);
            printf("Niebezpieczenstwo: ");
            scanf("%d", &niebezp);
            printf("Data karmienia: ");
            scanf("%s", data);
            printf("Status (0-STABILNY, 1-NIESPOKOJNY, 2-AGRESYWNY, 3-NIEBEZPIECZNY, 4-KWARANTANNA): ");
            scanf("%d", &status);

            Stworzenie* s = utworzStworzenie(
                imie, gatunek, moc, niebezp, data, (StatusStworzenia)status
            );

            if (s != NULL) {
                dodajNaPoczatek(&lista, s);
            }
        }

        else if (wybor == 3) {
            char imie[100];
            printf("Podaj imie do usuniecia: ");
            scanf("%s", imie);
            usunStworzenie(&lista, imie);
        }

        else if (wybor == 4) {
            char imie[100];
            printf("Podaj imie: ");
            scanf("%s", imie);
            znajdzPoImieniu(lista, imie);
        }

        else if (wybor == 5) {
            int min;
            printf("Minimalny poziom niebezpieczenstwa: ");
            scanf("%d", &min);
            znajdzPoNiebezpieczenstwie(lista, min);
        }

        else if (wybor == 6) {
            Stworzenie* kopia = kopiujListe(lista);
            sortujPoMocy(kopia);

            Stworzenie* tmp = kopia;
            while (tmp != NULL) {
                printStworzenie(tmp);
                tmp = tmp->next;
            }

            zwolnijListe(kopia);
        }

        else if (wybor == 7) {
            printf("Podaj nazwe pliku do zapisu: ");
            scanf("%s", nazwaPliku);
            zapiszDoPliku(lista, nazwaPliku);

        }
        else if (wybor == 8) {
            printf("Podaj nazwe pliku do odczytu: ");
            scanf("%s", nazwaPliku);

            Stworzenie* nowa = wczytajZPliku(nazwaPliku);
            if (nowa != NULL) {
                zwolnijListe(lista);
                lista = nowa;
            }

        }
        else if (wybor == 9) {
            char imie[100];
            printf("Podaj imie stworzenia do edycji: ");
            scanf("%s", imie);
            edytujStworzenie(lista, imie);
        }
        else if (wybor == 10) {
            Stworzenie* kopia = kopiujListe(lista);
            sortujPoImieniu(kopia);

            printf("\nLista posortowana alfabetycznie po imieniu:\n");
            Stworzenie* tmp = kopia;
            while (tmp != NULL) {
                printStworzenie(tmp);
                tmp = tmp->next;
            }

            zwolnijListe(kopia);
        }



    } while (wybor != 0);

    zwolnijListe(lista);


    return 0;
}
