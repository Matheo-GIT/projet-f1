#ifndef GRAND_PRIX_PILOTE_H
#define GRAND_PRIX_PILOTE_H
#include <stdio.h>
#include <string.h>
typedef struct {
    char* nom;
    char* prenom;
    char* nationalite;
    char* ecurie;
    int points;
    int numero;
    int age;
    int actif;
    short active;
} Pilote;

extern Pilote pilotes[10];
extern int nb_pilotes;




// fonctions utiliser dans le programme
void newPilote(const char* nom, const char* prenom, const char* nationalite, const char* ecurie, int points, int numero, int age, int actif);
void deletePilote(int index);
void displayPilote(Pilote* pilote);
void displayTousPilotes();
void updatePointsOfPilote(Pilote* pilote, int modifPoints);
void menu();
void menuPilote();
void menuNewPilote();


#endif //GRAND_PRIX_PILOTE_H
