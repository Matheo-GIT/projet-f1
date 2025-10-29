#include <stdio.h>
#include "pilote.h"
#include "menu.h"
#include "ecurie.h"
#include "GrandPrix.h"
// CLASSEMENT EN PRIO A PRESENTER
int main() {
    // NE PAS SUPP
    newPilote("Nogues", "Matheo", "France", "Ecurie de Matheo", 0, 18, 18, 1);
    newEcurie("Ecurie de Matheo", "France", 0, 2025, "Matheo Nogues", 1);
    newGrandPrix("Silverstone", "Royaume-Uni", 52, (Date){7,7,2024}, (Heure){14,0}, 10, 1);


    //updateResultGranPrix(); <- gaver long sa mere a faire
    //car faut rentrer tout les temps a la main 1 par 1 + faut bien écrire avec les : (0:00:00:000)
    displayTempsPilotes(2);

    return 0;
}