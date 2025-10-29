#ifndef GRAND_PRIX_GRANDPRIX_H
#define GRAND_PRIX_GRANDPRIX_H

#include "pilote.h"

#define MAX_GRANDPRIX 3
#define MAX_RESULTATS 20

typedef struct {
    int jour;
    int mois;
    int annee;
} Date;

typedef struct {
    int heures;
    int minutes;
} Heure;

typedef struct {
    char nomPilote[50];
    char prenomPilote[50];
    char nationnalitePilote[50];
    int position;
    char tempsRealise[20];
    int pointsObtenus;
} ResultatCourse;

typedef struct {
    char nomCircuit[50];
    char pays[50];
    int nombreTours;
    Date date;
    Heure horaire;
    ResultatCourse resultat[MAX_RESULTATS];
    int nombreResultat; // nb de resultat suivant le nb de pilote
    int actif;
} GrandPrix;


extern GrandPrix grandPrix[MAX_GRANDPRIX];
extern int nb_grandprix;
extern ResultatCourse resultat[MAX_RESULTATS];


void newGrandPrix(const char* nomCircuit, const char* pays, int nombreTours,
                  Date date, Heure horaire, int actif);
void updateResultGranPrix();
void displayGrandPrix(int indexGrandPrix);
void displayTousGrandPrix();
void deleteGrandPrix(int indexGranPrix);
void displayTempsPilotes(int numGrandPrix);

#endif // GRAND_PRIX_GRANDPRIX_H