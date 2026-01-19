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


    printStworzenie(&s);
    printStworzenie(&s2);


    return 0;
}
