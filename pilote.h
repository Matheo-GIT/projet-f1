#ifndef GRAND_PRIX_PILOTE_H
#define GRAND_PRIX_PILOTE_H
#include <stdio.h>
#include <string.h>
#define MAX_PILOTE 20


typedef struct {
    char nom[50];
    char prenom[50];
    char nationalite[50];
    char ecurie[50];
    int points;
    int numero;
    int age;
    int actif;
} Pilote;

extern Pilote pilotes[MAX_PILOTE];
extern int nb_pilotes;


// fonctions utiliser dans le programme
void newPilote(const char* nom, const char* prenom, const char* nationalite, const char* ecurie, int points, int numero, int age, int actif);
void deletePilote(int index);
void displayPilote(int index);
void displayTousPilotes();
void updatePointsOfPilote(int pilote, int modifPoints);

// autre fonction qui serve pour les inputs
int piloteExiste(const char* nom, const char* prenom);
int numberPiloteAlreadyUse(int position);

#endif //GRAND_PRIX_PILOTE_H