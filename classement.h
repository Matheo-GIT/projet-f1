#ifndef GRAND_PRIX_CLASSEMENT_H
#define GRAND_PRIX_CLASSEMENT_H
#include "pilote.h"
#include "GrandPrix.h"

typedef struct {
    char nomEcurie[50];
    int pointsTotal;
}ClassementEcurie;

void afficherClassementCourse(int indexGrandPrix);
void afficherClassementGeneralPilote();
void afficherClassementEcurie();

#endif //GRAND_PRIX_CLASSEMENT_H