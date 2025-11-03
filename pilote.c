#include <string.h>
#include "pilote.h"
#include "GrandPrix.h"
#include "ecurie.h"
#include "menu.h"

#include <stdlib.h>

// implémentation en dur des pilotes

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
    // cette fonction créer un pilote, elle prend en parametre un nim, prenom, nationnalite, écurie
    // nombre de points, un numéro, un age et un statu d'activité
    // la fonction ne renvoie rien.

    strcpy(pilotes[nb_pilotes].nom, nom);
    strcpy(pilotes[nb_pilotes].prenom, prenom);
    strcpy(pilotes[nb_pilotes].nationalite, nationalite);
    strcpy(pilotes[nb_pilotes].ecurie, ecurie);

    pilotes[nb_pilotes].points = points;
    pilotes[nb_pilotes].numero = numero;
    pilotes[nb_pilotes].age = age;
    pilotes[nb_pilotes].actif = actif;


    // ajout du pilote dans les resultat des courses
    // ajouter le nouveau pilote dans tous les gp existants
    for (int i = 0; i < nb_grandprix; i++) {
        int idx = grandPrix[i].nombreResultat; // position à la fin
        strcpy(grandPrix[i].resultat[idx].nomPilote, nom);
        strcpy(grandPrix[i].resultat[idx].prenomPilote, prenom);
        strcpy(grandPrix[i].resultat[idx].nationnalitePilote, nationalite);
        strcpy(grandPrix[i].resultat[idx].tempsRealise, "0:00:00:000");
        grandPrix[i].resultat[idx].position = 0;
        grandPrix[i].resultat[idx].pointsObtenus = 0;
        grandPrix[i].nombreResultat++;
    }
    nb_pilotes++;
    printf("Nouveau pilote ajoute : %s %s (%s)\n", nom, prenom, nationalite);
}

void updatePointsOfPilote(int pilote, int editPoints) {
    // cette fonction modifie les points d'un pilote
    // puis elle additionne les points des 2 pilotes avec la meme écurie pour les additionner
    // et former les nouveaux points totaux de l'écurie
    // le parametre "pilote" est le choix - 1 dans le menu pilote et le parametre
    // "editPoints" est le nouveau nombre de points donné par l'utilisateur

    pilotes[pilote].points = editPoints;
    char* nomEcurie = pilotes[pilote].ecurie; // pour plus de simpliciter
    int pointTotal = 0;

    // si le nom de l'écurie du pilote est égale à son écurie alors on ajoutes les points du pilote
    for (int i = 0; i < nb_pilotes; i++) {
        if (strcmp(pilotes[i].ecurie, nomEcurie) == 0) {
            pointTotal += pilotes[i].points;
        }
    }

    // on boucle sur les écuries et si le nom de l'écurie est la même que celle
    // du pilote alors on lui ajoute les points des pilotes
    for (int i = 0; i < nb_ecurie; i++) {
        if (strcmp(nomEcurie, ecuries[i].Nom) == 0) {
            ecuries[i].Points = pointTotal;
        }
    }

    printf("Nombre de points du pilote %s %s modifier\n",
        pilotes[pilote].nom, pilotes[pilote].prenom);
    printf("Les points de l'ecurie %s sont maintenant de %d\n",
        nomEcurie, pointTotal);
}

void deletePilote(int index) {
    // cette fonction supprime un pilote de la liste
    // pour supprimer un pilote on décale juste les autres pilotes vers la gauche
    // le parametre "index" est le choix - 1 dans le menu
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

// ===== Affiche 1 pilote =====
void displayPilote(int index) {
    // cette fonction permet d'afficher les informations d'un seul pilote
    // le parametre "index" est le choix - 1 dans le menu
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

// ===== Affiche tous les pilotes =====
void displayTousPilotes() {
    // cette fonction permet d'afficher les informations de tous les pilotes
    for (int i = 0; i < nb_pilotes; i++) {
        displayPilote(i);
    }
}

// ===== autre fonction qui serve pour les inputs =====
int piloteExiste(const char* nom, const char* prenom) {
    // cette fonction permet de vérifier si un pilote existe, grace à un nom et prénom
    for (int i = 0; i < nb_pilotes; i++) {
        if (strcmp(pilotes[i].nom, nom) == 0 && strcmp(pilotes[i].prenom, prenom) == 0) {
            return i;
        }
    }
    return -1;
}

int numberPiloteAlreadyUse(int numeroPilote) {
    // cette fonction sert à vérifier si le numéro du pilote
    // donné lors de l'ajout d'un pilote est déjà utiliser
    // elle retourne 1 si le numero n'est pas pris et 0 si il est pris

    for (int i = 0; i < nb_pilotes; i++) {
        if (numeroPilote == pilotes[i].numero) {
            return 0;
        }
    }
    return 1;
}
