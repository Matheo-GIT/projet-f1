#ifndef GRAND_PRIX_ECURIE_H
#define GRAND_PRIX_ECURIE_H
#include <stdio.h>
#include <string.h>
#define MAX_ECURIE 10

typedef struct {
    char Nom[50];
    char Pays[50];
    int Points;
    int anneeCreation;
    char Directeur[50];
    int Actif;
} Ecurie;

extern Ecurie ecuries[MAX_ECURIE];
extern int nb_ecurie;

void newEcurie(const char *nom, const char *pays, int points, int anneCreation, const char *directeur, int actif);
void deleteEcurie(int index);
void displayEcurie(int index);
void displayTousEcurie();
void updatePointsOfEcurie(int index, int modifPoints);

// autre fonction qui serve pour les inputs
int ecurieExiste(char ecurie[50]);
#endif //GRAND_PRIX_ECURIE_H
