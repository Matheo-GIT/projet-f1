#include "pilote.h"
#include "menu.h"
#include "ecurie.h"
#include "GrandPrix.h"
#include "classement.h"

int main() {
    // création d'une nouvelle écurie + un pilote en dur pour les test
    newEcurie("Ecurie de Matheo", "France", 0, 2025, "Matheo Nogues", 1);
    newPilote("Nogues", "Matheo", "France", "Ecurie de Matheo", 0, 18, 18, 1);

    mainMenu(); // <- fonction pour lancer le programme
    return 0;
}