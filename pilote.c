#include "pilote.h"

#include <stdlib.h>

// gestion complète des pilotes
#define MAX_PILOTE 20

Pilote pilotes[10] = {
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
};

int nb_pilotes = 9;




void newPilote(const char* nom, const char* prenom, const char* nationalite,
                   const char* ecurie, int points, int numero, int age, int actif) {
    if (nb_pilotes >= MAX_PILOTE) {
        printf("Tableau de pilotes plein !\n");
        return;
    }

    // Copier directement les valeurs dans le tableau statique
    pilotes[nb_pilotes].nom = strdup(nom);
    pilotes[nb_pilotes].prenom = strdup(prenom);
    pilotes[nb_pilotes].nationalite = strdup(nationalite);
    pilotes[nb_pilotes].ecurie = strdup(ecurie);
    pilotes[nb_pilotes].points = points;
    pilotes[nb_pilotes].numero = numero;
    pilotes[nb_pilotes].age = age;
    pilotes[nb_pilotes].actif = actif;

    nb_pilotes++;
}


void updatePointsOfPilote(Pilote* pilote, int modifPoints) {
    if (modifPoints <= 0) { printf("Erreur : le nombre de points ne peux pas être négatif\n");}
    else {
        pilote->points += modifPoints;
    }
}

void deletePilote(int index) {
    if (index < 0 || index >= nb_pilotes) return;

    free(pilotes[index].nom);
    free(pilotes[index].prenom);
    free(pilotes[index].nationalite);
    free(pilotes[index].ecurie);

    // Optionnel : déplacer les autres pilotes pour combler le trou
    for (int i = index; i < nb_pilotes - 1; i++) {
        pilotes[i] = pilotes[i+1];
    }
    nb_pilotes--;
}

void displayPilote(Pilote* pilote) {
    printf("Nom : %s | Prenom : %s | Nationalite : %s | Ecurie : %s | Points : %d | Numero : %d | Age : %d | Actif : %d\n",
           pilote->nom, pilote->prenom, pilote->nationalite,
           pilote->ecurie, pilote->points, pilote->numero, pilote->age, pilote->active);
}

void displayTousPilotes() {
    for (int i = 0; i < nb_pilotes; i++) {
        displayPilote(&pilotes[i]);
    }
}