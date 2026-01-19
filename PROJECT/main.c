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

    printStworzenie(&s);

    return 0;
}
