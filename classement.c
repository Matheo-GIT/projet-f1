#include <string.h>
#include "pilote.h"
#include "classement.h"
#include "GrandPrix.h"
#include "menu.h"

void displayClassementCourse(int indexGrandPrix) {
    // dans le menu on appelera la fonction avec l'indice - 1 car en humain le GP 1 != GP 1 du tableau

    if (indexGrandPrix < 0 || indexGrandPrix >= nb_grandprix) {
        printf("=== Indice de Grand Prix invalide ===\n");
        return;
    }

    // si actif est different de 1 alors il est inactif
    if (!grandPrix[indexGrandPrix].actif) {
        printf("=== Ce Grand Prix est inactif ===\n");
        return;
    }

    printf("\n=================== CLASSEMENT DU GRAND PRIX : %s | %s ===================\n",grandPrix[indexGrandPrix].nomCircuit, grandPrix[indexGrandPrix].pays);
    printf("Date : %02d/%02d/%04d | Heure : %02d:%02d\n",
        grandPrix[indexGrandPrix].date.jour, grandPrix[indexGrandPrix].date.mois, grandPrix[indexGrandPrix].date.annee,
        grandPrix[indexGrandPrix].horaire.heures, grandPrix[indexGrandPrix].horaire.minutes);

    // permet d'ajuster la taille entre les colonnes
    printf("\n%-7s | %-12s | %-11s | %-15s | %-12s | %s\n",
           "Pos", "Nom", "Prenom", "Nationalite", "Temps", "Points");


    // il faut classer les pilotes suivants leur position
    // donc on les met un tableau avec leur pos et on boucle sur la pos avec un indice + 1
    for (int i = 0; i < grandPrix[indexGrandPrix].nombreResultat; i++) {


        printf("Pos : %-3d %-14s %-13s %-17s %-14s %-10d\n",
               grandPrix[indexGrandPrix].resultat[i].position,
               grandPrix[indexGrandPrix].resultat[i].nomPilote,
               grandPrix[indexGrandPrix].resultat[i].prenomPilote,
               grandPrix[indexGrandPrix].resultat[i].nationnalitePilote,
               grandPrix[indexGrandPrix].resultat[i].tempsRealise,
               grandPrix[indexGrandPrix].resultat[i].pointsObtenus);
    }
}

//Classement général des pilotes
void displayGeneralClassementPilote() {
    if (nb_pilotes == 0) {
        printf("=== Aucun pilote enregistre ===\n");
        return;
    }

    // on fait une copie locale pour trier
    Pilote classement[MAX_PILOTE];
    memcpy(classement, pilotes, sizeof(Pilote) * nb_pilotes);

    // on tri par points décroissants grace a un bubble sort
    for (int i = 0; i < nb_pilotes - 1; i++) {
        for (int j = 0; j < nb_pilotes - i - 1; j++) {
            if (classement[j].points < classement[j + 1].points) {
                Pilote temp = classement[j];
                classement[j] = classement[j + 1];
                classement[j + 1] = temp;
            }
        }
    }

    printf("\n======================= CLASSEMENT GENERAL PILOTES ========================\n");
    printf("%-3s | %-12s | %-10s | %-17s | %s\n",
           "Pos", "Nom", "Prenom", "Ecurie", "Points");

    for (int i = 0; i < nb_pilotes; i++) {
        printf("%-5d %-14s %-12s %-19s %d\n",
               i + 1, classement[i].nom, classement[i].prenom,
               classement[i].ecurie, classement[i].points);
    }
}


void displayClassementEcurie() {
    if (nb_pilotes == 0) {
        printf("=== Aucun pilote enregistre ===\n");
        return;
    }

    ClassementEcurie ecuries[MAX_PILOTE];
    int nbEcuries = 0;

    // Ajout des points par écurie
    for (int i = 0; i < nb_pilotes; i++) {
        int trouve = 0;
        for (int j = 0; j < nbEcuries; j++) {
            if (strcmp(pilotes[i].ecurie, ecuries[j].nomEcurie.Nom) == 0) {
                ecuries[j].pointsTotal += pilotes[i].points;
                trouve = 1;
                break;
            }
        }
        if (!trouve) {
            strcpy(ecuries[nbEcuries].nomEcurie.Nom, pilotes[i].ecurie);
            ecuries[nbEcuries].pointsTotal = pilotes[i].points;
            nbEcuries++;
        }
    }

    // Tri décroissant par points
    for (int i = 0; i < nbEcuries - 1; i++) {
        for (int j = 0; j < nbEcuries - i - 1; j++) {
            if (ecuries[j].pointsTotal < ecuries[j + 1].pointsTotal) {
                ClassementEcurie tmp = ecuries[j];
                ecuries[j] = ecuries[j + 1];
                ecuries[j + 1] = tmp;
            }
        }
    }

    printf("\n========================= CLASSEMENT DES ECURIES =========================\n");
    printf("%-3s %-s %-s\n", "Pos", "Écurie", "Points");

    for (int i = 0; i < nbEcuries; i++) {
        printf("%-3d %-s %-d\n", i + 1, ecuries[i].nomEcurie.Nom, ecuries[i].pointsTotal);
    }
    printf("=============================================================================\n");
}