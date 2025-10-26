#include <stdio.h>
#include "pilote.h"

int main() {
    newPilote("Jean", "Sora", "France", "Ferrari", 0, 16, 49, 0);

    printf("\nAprès ajout :\n");
    displayTousPilotes();

    return 0;
}