#include <string.h>
#include "pilote.h"
#include "classement.h"
#include "GrandPrix.h"
#include "menu.h"

void afficherClassementCourse(const int indexGrandPrix) {
    if (indexGrandPrix < 0 || indexGrandPrix >= nb_grandprix) {
        printf("*** Indice de Grand Prix invalide. ***\n");
        return;
    }

    GrandPrix gp = grandPrix[indexGrandPrix];
    if (!gp.actif) {
        printf("*** Ce Grand Prix est inactif. ***\n");
        return;
    }

    printf("\n=================== CLASSEMENT DU GRAND PRIX : %s | %s ===================\n",gp.nomCircuit, gp.pays);
    printf("Date : %02d/%02d/%04d  -  Heure : %02dh%02dm\n",
        gp.date.jour, gp.date.mois, gp.date.annee, //Date
        gp.horaire.heures, gp.horaire.minutes);//Heure

    printf("\n| %-3s | %-15s | %-15s | %-15s | %-10s | %-10s |\n",
           "Pos", "Nom", "Prénom", "Nationalité", "Temps", "Points");

    for (int i = 0; i < gp.nombreResultat; i++) {
        ResultatCourse r = gp.resultat[i];
        printf("%-3d %-s %-s %-s %-s %-10d\n",
               r.position, r.nomPilote, r.prenomPilote,
               r.nationnalitePilote, r.tempsRealise, r.pointsObtenus);
    }
    printf("=============================================================================\n");
}

//Classement général des pilotes
void afficherClassementGeneralPilotes() {
    if (nb_pilotes == 0) {
        printf("*** Aucun pilote enregistré. ***\n");
        return;
    }

    // Copie locale pour trier
    Pilote classement[MAX_PILOTE];
    memcpy(classement, pilotes, sizeof(Pilote) * nb_pilotes);

    // Tri par points décroissants (simple bubble sort)
    for (int i = 0; i < nb_pilotes - 1; i++) {
        for (int j = 0; j < nb_pilotes - i - 1; j++) {
            if (classement[j].points < classement[j + 1].points) {
                Pilote temp = classement[j];
                classement[j] = classement[j + 1];
                classement[j + 1] = temp;
            }
        }
    }

    printf("\n======================= CLASSEMENT GÉNÉRAL PILOTES ========================\n");
    printf("%-3s %-s %-s %-s %-s\n",
           "Pos", "Nom", "Prénom", "Écurie", "Points");

    for (int i = 0; i < nb_pilotes; i++) {
        printf("%-3d %-s %-s %-s %-d\n",
               i + 1, classement[i].nom, classement[i].prenom,
               classement[i].ecurie, classement[i].points);
    }
    printf("=============================================================================\n");
}

//Classement des Ecuries
void afficherClassementEcurie() {
    if (nb_pilotes == 0) {
        printf("*** Aucun pilote enregistré. ***\n");
        return;
    }

    ClassementEcurie ecuries[MAX_PILOTE];
    int nbEcuries = 0;

    // Ajout des points par écurie
    for (int i = 0; i < nb_pilotes; i++) {
        int trouve = 0;
        for (int j = 0; j < nbEcuries; j++) {
            if (strcmp(pilotes[i].ecurie, ecuries[j].nomEcurie) == 0) {
                ecuries[j].pointsTotal += pilotes[i].points;
                trouve = 1;
                break;
            }
        }
        if (!trouve) {
            strcpy(ecuries[nbEcuries].nomEcurie, pilotes[i].ecurie);
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
        printf("%-3d %-s %-d\n", i + 1, ecuries[i].nomEcurie, ecuries[i].pointsTotal);
    }
    printf("=============================================================================\n");
}