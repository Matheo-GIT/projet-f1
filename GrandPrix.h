//
// Created by theom on 28/10/2025.
//

#ifndef TEST_GRAND_PRIX_GRANDPRIX_H
#define TEST_GRAND_PRIX_GRANDPRIX_H
#define MAX_GRANDPRIX 3
#include "pilote.h"
typedef struct {
    int jour;
    int mois;
    int annee;
}DATE;

typedef struct {
    int heures;
    int minutes;
}HEURE;

typedef struct {
    Pilote nom[50];
    Pilote prenom[50];
    Pilote nationalite[50];
    Pilote Position;
    char tempsRealise;
    int pointsObtenus;

}ResultatCourse;
ResultatCourse Resultat[20];

typedef struct {
    char nomCircuit[50];
    char Pays[50];
    int nombreTours;
    DATE Date;
    HEURE Horaire;
    ResultatCourse Resultat[20];
    int nombreResultat;
    int Actif;

}GrandPrix;

extern GrandPrix grand_prix[MAX_GRANDPRIX];
extern int nb_grandprix;

void newGrandPrix(const char* nomCircuit,const char* Pays,const char* nombreTours,DATE date,HEURE Horaire,ResultatCourse Resultat[20],int nombreResulat,int Actif);

void deleteGrandPrix();

#endif //TEST_GRAND_PRIX_GRANDPRIX_H