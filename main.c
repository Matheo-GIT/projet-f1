#include <stdio.h>
#include "pilote.h"

int main() {

    newPilote("test", "test", "test", "test", 0, 18, 18, 1);
    menuEditPoints();
    displayTousPilotes();
    return 0;
}