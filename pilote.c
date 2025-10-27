#include <string.h>
#include "pilote.h"

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

    pilotes[nb_pilotes].numero = numero;
    pilotes[nb_pilotes].age = age;
    pilotes[nb_pilotes].actif = actif;

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

void displayPilote(int index) {
    printf("Nom : %s | Prenom : %s | Nationalite : %s | Ecurie : %s | Points : %d | Numero : %d | Age : %d | Actif : %d\n",
           pilotes[index].nom, pilotes[index].prenom, pilotes[index].nationalite,
           pilotes[index].ecurie, pilotes[index].points, pilotes[index].numero, pilotes[index].age, pilotes[index].actif);
}

void displayTousPilotes() {
    for (int i = 0; i < nb_pilotes; i++) {
        displayPilote(i);
    }
}

void menuDeletePilote() {
    int option;
    for (int i = 0; i < nb_pilotes; i++) {
        printf("%d. %s %s\n", i+1, pilotes[i].nom, pilotes[i].prenom);
    }
    printf("Quel pilote voulez vous supprimez : ");
    scanf("%d", &option);
    deletePilote(option-1);
}

void menuEditPoints() {
    int option, editPoint;
    for (int i = 0; i < nb_pilotes; i++) {
        printf("%d. %s %s | %d\n", i+1, pilotes[i].nom, pilotes[i].prenom, pilotes[i].points);
    }
    printf("A quel pilote voulez vous modifier les points : ");
    scanf("%d", &option);
    // option doit etre compris entre 0 et nb_pilote
    do {
        printf("Quel est le nouveau nombre de points : ");
        scanf("%d", &editPoint);
        if (editPoint < 0) {
            printf("Erreur : le nouveau nombre de points ne peut pas etre negatif\n");
        }
    } while (editPoint < 0);
    updatePointsOfPilote(option - 1, editPoint);
}

void mainMenu() {
    int choix;
    do {
        printf("\n=== MENU PRINCIPAL ===\n");
        printf("1. Menu pilote\n");
        printf("2. Quitter\n");
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                menuPilote();
                break;
            case 2:
                printf("Au revoir !");
                return;
            default:
                printf("Choix invalide !");
        }
    } while (choix != 2);
}

void menuPilote() {
    // menu qui va permettre de choisir entre ajouter / delete / edit points pilote
    int choix;
    do {
        printf("\n=== MENU PILOTE ===\n");
        printf("1. Ajouter un pilote\n");
        printf("2. Retour\n");
        printf("Votre choix : ");
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                menuNewPilote();  // on appelle la fonction d’ajout
                break;
            case 2:
                printf("Retour au menu principal...\n");
                break;
            default:
                printf("Choix invalide !\n");
                break;
        }
    } while (choix != 2);
}


void menuNewPilote() {
    char nom[50], prenom[50], nationalite[50], ecurie[50];
    int points, numero, age, actif;

    if (nb_pilotes >= MAX_PILOTE) {
        printf("Tableau de pilotes plein !\n");
        return;
    }

    printf("\n=== MENU D'AJOUT DE PILOTE ===\n");
    // saisie nom/prenom avec vérifications
    do {
        printf("Quel est le nom du pilote : ");
        scanf("%49s", nom);

        printf("Quel est le prenom du pilote : ");
        scanf("%49s", prenom);

        if (strlen(nom) == 0 || strlen(prenom) == 0) {
            printf("Erreur : le nom et le prénom ne doivent pas être vides.\n");
        }
        else if (piloteExiste(nom, prenom) != -1) {
            printf("Erreur : ce pilote existe déjà.\n");
        }


    } while (strlen(nom) == 0 || strlen(prenom) == 0 || piloteExiste(nom, prenom) != -1);



    printf("Quel est la nationalite du pilote : ");
    scanf("%s", nationalite);

    // creer fonction ecurieExiste dans ecurie.c
    printf("Quel est le nom de l'ecurie du pilote : ");
    scanf(" %[^\n]", ecurie); // l'espace avant : % -> clear le buffer et tant qu'on ne retourne pas a la ligne
                                    // alors on scan se que dit l'utilisateur
    do {
        printf("Quel est le nombre de point du pilote : ");
        scanf("%d", &points);
        if (points < 0) {
            printf("Erreur : le nombre de point doit etre positif\n");
        }
    } while (points < 0);


    do {
        printf("Quel est le numero du pilote : ");
        scanf("%d", &numero);
        if (numero <= 0 || numero >= 100) {
            printf("Erreur : le numero doit etre compris entre 1 et 99\n");
        }
    } while (numero <= 0 || numero >= 100);


    do {
        printf("Quel est l'age du pilote : ");
        scanf("%d", &age);

        if (age < 18 || age > 50) {
            printf("Erreur : l'age doit etre compris entre 18 et 50 ans\n");
        }

    } while (age < 18 || age > 50);


    do {
        printf("Est ce que le pilote est actif ? (1. Oui / 0. Non) : ");
        scanf("%d", &actif);
        if (actif != 1 && actif != 0) {
            printf("Erreur : veuillez entrer 1 (Actif) ou 0 (Non actif)\n");
        }
    } while (actif != 1 && actif != 0);


    newPilote(nom, prenom, nationalite, ecurie, points, numero, age, actif);
    printf("\nCreation reussi");
}