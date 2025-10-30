#include "ecurie.h"
#include "menu.h"
#include <stdio.h>
#include <string.h>

Ecurie ecuries[MAX_ECURIE] = {
    {"Red Bull Racing", "Autriche", 0, 2005, "Christian Horner", 1},
    {"Scuderia Ferrari", "Italie", 0, 1950, "Frédéric Vasseur", 1},
    {"Mercedes-AMG", "Allemagne", 0, 2010, "Toto Wolff", 1},
    {"McLaren Racing", "Royaume-Uni", 0, 1966, "Andrea Stella", 1},
    {"Aston Martin", "Royaume-Uni", 0, 2021, "Mike Krack", 1}
};

int nb_ecurie = 5;



void newEcurie(const char* nom, const char* pays, int points, int anneCreation, const char* directeur, int actif) {

    strcpy(ecuries[nb_ecurie].Nom, nom);
    strcpy(ecuries[nb_ecurie].Pays, pays);
    strcpy(ecuries[nb_ecurie].Directeur, directeur);

    ecuries[nb_ecurie].Points = points;
    ecuries[nb_ecurie].Actif = actif;

    nb_ecurie++;
    printf("Nouvelle ecurie ajoute : %s (%s)", nom, pays);
}

// Probleme regler c'était juste un : - 1
void deleteEcurie(int index) {
    if (index < 0 || index >= nb_ecurie) {
        printf("Erreur : l'index est invalide\n");
        return;
    }
    printf("L'ecurie : %s va etre supprimer\n", ecuries[index].Nom);
    // on décale juste les ecuries pour "écraser" l'ecurie a supp
    for (int i = index; i < nb_ecurie - 1; i++) {
        ecuries[i] = ecuries[i + 1];
    }

    nb_ecurie--;

    printf("Ecurie supprime avec succes.\n");
}

void displayEcurie(int index) {
    if (index < 0 || index >= nb_ecurie) {
        printf("Erreur : l'index (ecurie) est invalide\n");
        return;
    }
    printf("Ecurie : %-16s | Pays : %-12s | Pts : %-2d | Annee Creation : %-4d | Directeur : %-13s | Actif : %-10s\n",
        ecuries[index].Nom,
        ecuries[index].Pays,
        ecuries[index].Points,
        ecuries[index].anneeCreation,
        ecuries[index].Directeur,
        ecuries[index].Actif ? "Oui" : "Non");
}

void displayTousEcurie() {
    for (int i = 0; i < nb_ecurie; i++) {
        displayEcurie(i);
    }
}

void updatePointsOfEcurie(int index, int modifPoints) {
    ecuries[index].Points = modifPoints;
}

int ecurieExiste(char ecurie[50]) {
    for (int i = 0; i < nb_ecurie; i++) {
        if (strcmp(ecuries[i].Nom, ecurie) == 0) {
            return 1;
        }
    }
    return -1;
}