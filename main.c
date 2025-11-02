#include "pilote.h"
#include "menu.h"
#include "ecurie.h"
#include "GrandPrix.h"
#include "classement.h"
// CLASSEMENT EN PRIO A PRESENTER
int main() {
    // NE PAS SUPP
    newEcurie("Ecurie de Matheo", "France", 0, 2025, "Matheo Nogues", 1);
    newPilote("Nogues", "Matheo", "France", "Ecurie de Matheo", 0, 18, 18, 1);

    // finir menu ajouter un grand prix


    //updateResultGranPrix(); // <- gaver long sa mere a faire
                            // car faut rentrer tout les temps a la main 1 par 1
                            // et en + faut bien écrire avec les : (ex : 0:00:00:000)

    //displayTempsPilotes(2);
    //displayTousGrandPrix();
    //deleteGrandPrix(1); // faut que sa delete aussi les résultats du grand prix
    //displayTousGrandPrix();
    mainMenu();
    return 0;
}