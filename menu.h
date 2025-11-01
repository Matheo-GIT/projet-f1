#ifndef TEST_GRAND_PRIX_MENU_H
#define TEST_GRAND_PRIX_MENU_H

void mainMenu();

// === MENU PILOTE ===
void menuPilote();
void menuNewPilote();
void menuDeletePilote();
void menuEditPointsPilote();
void menuDisplayPilote();

// === MENU ECURIE ===
void menuEcurie();
void menuNewEcurie();
void menuDeleteEcurie();
void menuEditPointsEcurie();
void menuDisplayEcurie();




// === MENU GRAND PRIX ===
void menuGrandPrix();
void menuNewGrandPrix();
//void menuDeleteGrandPrix();
//void menuEditTimeGrandPrix();
void menuDisplayTempsGrandPrix();
void menuDisplayGrandPrix();
void menuDisplayPointsPilotes();



// === MENU CLASSEMENT ===
void menuClassement();

// === AUTRE FONCTION ===
int estBissextile(int annee);

#endif //TEST_GRAND_PRIX_MENU_H