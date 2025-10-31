#ifndef GRAND_PRIX_CLASSEMENT_H
#define GRAND_PRIX_CLASSEMENT_H
#include "pilote.h"
#include "GrandPrix.h"
#include "ecurie.h"

typedef struct {
    Ecurie nomEcurie; // structure imbrique pour connaitre le nom de l'écurie on fait  : *.nomEcurie.Nom
    int pointsTotal;
} ClassementEcurie;

void displayClassementCourse(int indexGrandPrix);
void displayGeneralClassementPilote();
void displayClassementEcurie();

#endif //GRAND_PRIX_CLASSEMENT_H