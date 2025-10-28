#include <stdio.h>
#include "pilote.h"
#include "menu.h"
#include "ecurie.h"
// CLASSEMENT EN PRIO A PRESENTER
int main() {

    newPilote("test", "test", "test", "test", 0, 18, 18, 1);
    // menuEditPoints();
    mainMenu();
    //newEcurie("Ecurie de test", "Autriche", 0, 2005, "Christian Horner", 1);
    //menuNewEcurie();

    return 0;
}