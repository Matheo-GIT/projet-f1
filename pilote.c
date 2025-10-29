#include <string.h>
#include "pilote.h"
#include "GrandPrix.h"
#include "menu.h"

#include <stdlib.h>

// gestion complète des pilotes

Pilote pilotes[MAX_PILOTE] = {
    {"Verstappen", "Max", "Pays-Bas", "Red Bull Racing", 0, 1, 27, 1},
    {"Perez", "Sergio", "Mexique", "Red Bull Racing", 0, 11, 34, 1},
    {"Leclerc", "Charles", "Monaco", "Scuderia Ferrari", 0, 16, 27, 1},
    {"Sainz", "Carlos", "Espagne", "Scuderia Ferrari", 0, 55, 30, 1},
    {"Hamilton", "Lewis", "Royaume-Uni", "Mercedes-AMG", 0, 44, 39, 1},
    {"Russell", "George", "Royaume-Uni", "Mercedes-AMG", 0, 63, 26, 1},
    {"Norris", "Lando", "Royaume-Uni", "McLaren Racing", 0, 4, 25, 1},
    {"Piastri", "Oscar", "Australie", "McLaren Racing", 0, 81, 23, 1},
    {"Alonso", "Fernando", "Espagne", "Aston Martin", 0, 14, 43, 1},
    {"Stroll", "Lance", "Canada", "Aston Martin", 0, 18, 26, 1}
}; // le reste des valeurs sera initialiser comme rien : "" -> char et 0 -> int

int nb_pilotes = 10;


void newPilote(const char* nom, const char* prenom, const char* nationalite,
               const char* ecurie, int points, int numero, int age, int actif) {

    strcpy(pilotes[nb_pilotes].nom, nom);
    strcpy(pilotes[nb_pilotes].prenom, prenom);
    strcpy(pilotes[nb_pilotes].nationalite, nationalite);
    strcpy(pilotes[nb_pilotes].ecurie, ecurie);

    pilotes[nb_pilotes].points = points;
    pilotes[nb_pilotes].numero = numero;
    pilotes[nb_pilotes].age = age;
    pilotes[nb_pilotes].actif = actif;


    // ajout du pilotes dans les resultat des courses
    strcpy(resultat[nb_pilotes].nomPilote, nom);
    strcpy(resultat[nb_pilotes].prenomPilote, prenom);
    strcpy(resultat[nb_pilotes].nationnalitePilote, nationalite);
    resultat[nb_pilotes].position = 0;
    strcpy(resultat[nb_pilotes].tempsRealise, "0:00:00:000");
    resultat[nb_pilotes].pointsObtenus = 0;

    grandPrix[nb_grandprix - 1].nombreResultat++; // ajoute 1 pilote donc le nombre de résultat augmente aussi
    nb_pilotes++;
}

void updatePointsOfPilote(int index, int editPoints) {
    pilotes[index].points = editPoints;
}

void deletePilote(int index) {
    if (index < 0 || index >= nb_pilotes) {
        printf("Erreur : l'index est invalide\n");
        return;
    }
    printf("Le pilote : %s %s va etre supprimer\n", pilotes[index].nom, pilotes[index].prenom);
    // on décale juste les pilotes pour "écraser" le pilote a supp
    for (int i = index; i < nb_pilotes - 1; i++) {
        pilotes[i] = pilotes[i + 1];
    }

    nb_pilotes--;
    printf("Pilote supprime avec succes.\n");
}

int piloteExiste(const char* nom, const char* prenom) {
    for (int i = 0; i < nb_pilotes; i++) {
        if (strcmp(pilotes[i].nom, nom) == 0 && strcmp(pilotes[i].prenom, prenom) == 0) {
            return i;
        }
    }
    return -1;
}

// affiche 1 pilote
void displayPilote(int index) {
    printf("Nom : %-12s | Prenom : %-8s | Nationalite : %-11s | Ecurie : %-16s | Points : %3d | Numero : %3d | Age : %3d | Actif : %d\n",
           pilotes[index].nom,
           pilotes[index].prenom,
           pilotes[index].nationalite,
           pilotes[index].ecurie,
           pilotes[index].points,
           pilotes[index].numero,
           pilotes[index].age,
           pilotes[index].actif);
    printf("\n");
}


// affiche tout les pilotes
void displayTousPilotes() {
    for (int i = 0; i < nb_pilotes; i++) {
        displayPilote(i);
    }
}