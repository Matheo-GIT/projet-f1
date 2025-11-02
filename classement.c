#include <string.h>
#include "pilote.h"
#include "classement.h"
#include "GrandPrix.h"

void displayClassementCourse(int indexGrandPrix) {
    // cette fonction renvoie le classement à la fin du grand prix

    // si actif vaut 0 alors le GP est inactif donc pas besoin de l'afficher
    if (!grandPrix[indexGrandPrix].actif) {
        printf("=== Ce Grand Prix est inactif ===\n");
        return;
    }

    printf("\n=================== CLASSEMENT DU GRAND PRIX : %s | %s ===================\n",
           grandPrix[indexGrandPrix].nomCircuit, grandPrix[indexGrandPrix].pays);

    printf("Date : %02d/%02d/%04d | Heure : %02d:%02d\n",
           grandPrix[indexGrandPrix].date.jour, grandPrix[indexGrandPrix].date.mois, grandPrix[indexGrandPrix].date.annee,
           grandPrix[indexGrandPrix].horaire.heures, grandPrix[indexGrandPrix].horaire.minutes);

    printf("\n%-5s | %-12s | %-11s | %-15s | %-12s | %s\n",
           "Pos", "Nom", "Prenom", "Nationalite", "Temps", "Points");

    // en premier on affiche les pilotes qui ont courus : leur position vaut 1 ou plus
    for (int position = 1; position <= nb_pilotes; position++) {
        for (int i = 0; i < nb_pilotes; i++) {
            // si la position du pilote est égale à l'indice de la boucle alors je l'affiche
            // on affiche donc que un pilote par tour de boucle
            if (grandPrix[indexGrandPrix].resultat[i].position == position) {
                printf("%-5d | %-12s | %-11s | %-15s | %-12s | %-3d\n",
                       grandPrix[indexGrandPrix].resultat[i].position,
                       grandPrix[indexGrandPrix].resultat[i].nomPilote,
                       grandPrix[indexGrandPrix].resultat[i].prenomPilote,
                       grandPrix[indexGrandPrix].resultat[i].nationnalitePilote,
                       grandPrix[indexGrandPrix].resultat[i].tempsRealise,
                       grandPrix[indexGrandPrix].resultat[i].pointsObtenus);
            }
        }
    }

    // maintenant on affiche les pilotes n’ayant pas couru : leur position vaut 0
    for (int i = 0; i < nb_pilotes; i++) {
        // si la position du pilote vaut 0 on l'affiche
        if (grandPrix[indexGrandPrix].resultat[i].position == 0) {
            printf("%-5d | %-12s | %-11s | %-15s | %-12s | %-3d\n",
                grandPrix[indexGrandPrix].resultat[i].position,
                grandPrix[indexGrandPrix].resultat[i].nomPilote,
                grandPrix[indexGrandPrix].resultat[i].prenomPilote,
                grandPrix[indexGrandPrix].resultat[i].nationnalitePilote,
                grandPrix[indexGrandPrix].resultat[i].tempsRealise,
                grandPrix[indexGrandPrix].resultat[i].pointsObtenus);
        }
    }
}


// classement général des pilotes
void displayGeneralClassementPilote() {
    if (nb_pilotes == 0) {
        printf("Erreur : aucun pilote enregistre\n");
        return;
    }

    // on fait une copie locale des pilotes pour trier
    Pilote classement[MAX_PILOTE];
    memcpy(classement, pilotes, sizeof(Pilote) * nb_pilotes);

    // on tri par points décroissants grace a un trie a bulle
    // on parcourt le tableau plusieurs fois et a chaque passage on echange les pilotes
    // si celui d’après a plus de points que celui d’avant
    for (int i = 0; i < nb_pilotes - 1; i++) {
        for (int j = 0; j < nb_pilotes - i - 1; j++) {
            if (classement[j].points < classement[j + 1].points) {
                // création d'une variable temporaire dans pilote
                Pilote temp = classement[j];
                classement[j] = classement[j + 1];
                classement[j + 1] = temp;
            }
        }
    }

    printf("\n======================= CLASSEMENT GENERAL PILOTES ========================\n");
    printf("%-3s | %-12s | %-10s | %-17s | %s\n",
           "Pos", "Nom", "Prenom", "Ecurie", "Points");

    // affichage des pilotes trier (nouveau tableau classement)
    for (int i = 0; i < nb_pilotes; i++) {
        printf("%-5d %-14s %-12s %-19s %d\n",
               i + 1, classement[i].nom, classement[i].prenom,
               classement[i].ecurie, classement[i].points);
    }
}






int pointsF1(int position) {
    // cette fonction aide a recalculer tous les points des pilotes pour le classement final
    // elle prend la position d'un pilote puis lui calcule ses points depuis sa position
    // pos = 1 = 25 points etc...
    switch(position) {
        case 1: return 25;
        case 2: return 18;
        case 3: return 15;
        case 4: return 12;
        case 5: return 10;
        case 6: return 8;
        case 7: return 6;
        case 8: return 4;
        case 9: return 2;
        case 10: return 1;
        default: return 0;
    }
}


void displayClassementEcurie() {
    if (nb_ecurie == 0) {
        printf("Erreur : aucune ecurie enregistree\n");
        return;
    }

    // on créer une copie du tableau "ecuries" pour trier sans modifier le tableau original
    Ecurie classement[MAX_ECURIE];
    memcpy(classement, ecuries, sizeof(Ecurie) * nb_ecurie);

    // on réinitialise les points avant recalcul pour éviter les erreurs
    for (int i = 0; i < nb_ecurie; i++) {
        classement[i].Points = 0;
    }

    // on calcul les points par écurie depuis les tableaux de résultats des Grand Prix
    for (int i = 0; i < nb_grandprix; i++) {
        if (!grandPrix[i].actif) continue; // <- si le GP est inactif (actif == 0) on l'ignore

        // je boucle sur mon nombre de résultat qui est égale a mon nombre de piltoe
        for (int j = 0; j < grandPrix[i].nombreResultat; j++) {
            // pour plus de lisibiliter dans le code, je créer une variable "pos" qui contient la position du pilote
            // cela évite quand on donne en parametre la position du pilote de devoir
            // écrire grandPrix[i].resultat[j].position à chaque fois
            int pos = grandPrix[i].resultat[j].position;

            if (pos == 0) {
                // si le pilote n'a pas couru je l'ignore (pas de points)
                continue;
            }

            // ici on cherche a trouver l'indice du pilote
            int idxPilote = piloteExiste(grandPrix[i].resultat[j].nomPilote,
                                        grandPrix[i].resultat[j].prenomPilote);
            if (idxPilote == -1) {
                // le pilote n'existe pas donc on ignore
                // (j'ai préferer retourner -1 que 0 au cas ou la position vaux 0)
                continue;
            }

            // ici on cherche a trouver l'indice de l'écurie
            for (int k = 0; k < nb_ecurie; k++) {
                // si le nom de l'écurie du pilote et celle qui se trouve dans le tableau temporaire sont les mêmes
                // alors on recalcul les points du pilotes puis on les ajoutes à l'écurie
                if (strcmp(classement[k].Nom, pilotes[idxPilote].ecurie) == 0) {
                    // la fonciton pointsF1 recalcul les points du pilotes
                    classement[k].Points += pointsF1(pos);
                    // on met a jour les points du pilote
                    grandPrix[i].resultat[j].pointsObtenus = pointsF1(pos);
                }
            }
        }
    }

    // on trie de maniere décroissante grace a un trie a bulle
    // si le nombre de points d'apres et plus grand que celui d'avant alors on les inverses
    for (int i = 0; i < nb_ecurie - 1; i++) {
        for (int j = 0; j < nb_ecurie - i - 1; j++) {
            if (classement[j].Points < classement[j + 1].Points) {
                // création d'une variable temporaire pour stocker le classement
                Ecurie tmp = classement[j];
                classement[j] = classement[j + 1];
                classement[j + 1] = tmp;
            }
        }
    }

    // les points on bien été mis a jour donc on affichage le résultat
    printf("\n========================= CLASSEMENT DES ECURIES =========================\n");
    printf("%-3s %-20s %s\n", "Pos", "Ecurie", "Points");
    for (int i = 0; i < nb_ecurie; i++) {
        printf("%-3d %-20s %d\n", i + 1, classement[i].Nom, classement[i].Points);
    }
}