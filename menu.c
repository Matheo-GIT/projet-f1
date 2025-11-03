#include "menu.h"
#include "pilote.h"
#include "ecurie.h"
#include "GrandPrix.h"
#include "classement.h"


void mainMenu() {
    int choix;
    do {
        printf("\n=== MENU PRINCIPAL ===\n");
        printf("1. Menu pilote\n");
        printf("2. Menu ecurie\n");
        printf("3. Menu Grand Prix\n");
        printf("4. Menu Classement\n");
        printf("5. Quitter\n");
        printf("Votre choix :");
        scanf(" %d", &choix);

        switch (choix) {
            case 1:
                menuPilote();
                break;
            case 2:
                menuEcurie();
                break;
            case 3:
                menuGrandPrix();
                break;
            case 4:
                menuClassement();
                break;
            case 5:
                printf("Au revoir !");
                return;
            default:
                printf("Choix invalide !");
        }
    } while (choix != 5);
}


// ============================================= MENU PILOTE =============================================


void menuPilote() {
    // menu qui va permettre de choisir entre ajouter / delete / edit points pilote
    int choix;
    do {
        printf("\n=== MENU PILOTE ===\n");
        printf("1. Ajouter un pilote\n");
        printf("2. Supprimer un pilote\n");
        printf("3. Modifier les points d'un pilote\n");
        printf("4. Afficher un pilote\n");
        printf("5. Afficher tous les pilotes\n");
        printf("6. Retour\n");
        printf("Votre choix : ");
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                menuNewPilote();
                break;
            case 2:
                menuDeletePilote();
                break;
            case 3:
                menuEditPointsPilote();
                break;
            case 4:
                menuDisplayPilote();
                break;
            case 5:
                displayTousPilotes();;
                break;
            case 6:
                printf("Retour au menu principal...\n");
                return; // return rien car fonction void et pas de break, le return quitte la boucle menuPilote et va dans mainMenu
            default:
                printf("Choix invalide !\n");
                break;
        }
    } while (choix != 6);
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

    // vérification des imputs de l'utilisateur
    } while (strlen(nom) == 0 || strlen(prenom) == 0 || piloteExiste(nom, prenom) != -1);



    printf("Quel est la nationalite du pilote : ");
    scanf("%s", nationalite);

    do {
        printf("Tous les nom d'ecurie :\n");
        for (int i = 0; i < nb_ecurie; i++) {
            printf(" %s |", ecuries[i].Nom);
        }
        printf("\n");
        printf("Quel est le nom de l'ecurie du pilote : ");
        scanf(" %[^\n]", ecurie); // l'espace avant : % -> clear le buffer et tant qu'on ne retourne pas a la ligne
                                        // alors on scan se que dit l'utilisateur
        if (ecurieExiste(ecurie) != 1) {
            printf("Erreur : cette ecurie n'existe pas\n");
        }
    } while (ecurieExiste(ecurie) != 1);

    do {
        printf("Quel est le nombre de point du pilote : ");
        scanf(" %d", &points);
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
        else if (numberPiloteAlreadyUse(numero) == 0) {
            printf("Erreur : le numero est deja pris\n");
        }
    } while (numero <= 0 || numero >= 100 || numberPiloteAlreadyUse(numero) == 0);


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

void menuEditPointsPilote() {
    int option, editPoint;
    for (int i = 0; i < nb_pilotes; i++) {
        printf("%-3d %-11s %-9s | %d\n", i+1, pilotes[i].nom, pilotes[i].prenom, pilotes[i].points);
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

void menuDisplayPilote() {
    int choix;
    for (int i = 0; i < nb_pilotes; i++) {
        printf("%d. %s %s\n", i+1, pilotes[i].nom, pilotes[i].prenom);
    }
    do {
        printf("Quel pilote voulez vous afficher : ");
        scanf("%d", &choix);
        if (choix <= 0 || choix > nb_pilotes) {
            printf("Erreur : vous avez choisis un pilote en dehors de la liste\n");
        }
    } while (choix <= 0 || choix > nb_pilotes);

    displayPilote(choix - 1);
}


// ============================================= MENU ECURIE =============================================

void menuEcurie() {
    int choix;
    do {
        printf("\n=== MENU ECURIE ===\n");
        printf("1. Ajouter une ecurie\n");
        printf("2. Supprimer une ecurie\n");
        printf("3. Modifier les points d'une ecurie\n");
        printf("4. Afficher une ecurie\n");
        printf("5. Afficher toutes les ecuries\n");
        printf("6. Retour\n");
        printf("Votre choix : ");
        scanf("%d", &choix);
        switch (choix) {
            case 1:
                menuNewEcurie();
                break;
            case 2:
                menuDeleteEcurie();
                break;
            case 3:
                menuEditPointsEcurie();
                break;
            case 4:
                menuDisplayEcurie();
                break;
            case 5:
                displayTousEcurie();
                break;
            case 6:
                printf("Retour au menu principal...\n");
                return; // return rien car fonction void et pas de break, le return quitte la boucle menuPilote et va dans mainMenu
            default:
                printf("Choix invalide !\n");
                break;
        }
    } while (choix != 6);
}


void menuNewEcurie() {
    char nom[50], pays[50], directeur[50];
    int points, anneeCreation, actif;

    if (nb_ecurie >= MAX_PILOTE) {
        printf("Tableau d'ecurie plein !\n");
        return;
    }
    printf("\n=== MENU D'AJOUT D'ECURIE ===\n");
    do {
        if (nb_ecurie > 0) {
            printf("Tous les nom d'ecurie :\n");
            for (int i = 0; i < nb_ecurie; i++) {
                printf(" %s |", ecuries[i].Nom);
            }
            printf("\n");
            printf("Entrez le nom de l'ecurie : ");
            scanf(" %[^\n]", nom);
            if (ecurieExiste(nom) != 1) {
                printf("Cette ecurie n'existe pas\n");
            }
        }
        else {
            printf("Entrez le nom de l'ecurie : ");
            scanf(" %[^\n]", nom);
        }


    } while (ecurieExiste(nom) != 1);

    printf("Entrez le pays :");
    scanf(" %[^\n]", pays);

    printf("Entrez le directeur : ");
    scanf(" %[^\n]", directeur);

    do {
        printf("Entrez le nombre de points : ");
        scanf(" %d", &points);
        if (points < 0) {
            printf("Erreur : le nombre de points ne peux pas etre negatif\n");
        }
    } while (points < 0);

    do {
        printf("Entrez la date de creation de l'ecurie : ");
        scanf("%d", &anneeCreation);
        if (anneeCreation < 0) {
            printf("Erreur : la date de creation est invalide");
        }
    } while (anneeCreation < 0);

    do {
        printf("Est ce que l'ecurie est active ? (1. Oui / 0. Non) : ");
        scanf("%d", &actif);
        if (actif != 1 && actif != 0) {
            printf("Erreur : veuillez entrer 1 (Actif) ou 0 (Non actif)\n");
        }
    } while (actif != 1 && actif != 0);
    newEcurie(nom, pays, points, anneeCreation, directeur, actif);
}

void menuDeleteEcurie() {
    if (nb_ecurie == 0) {
        printf("Erreur : il n'y a pas d'ecurie\n");
        return;
    }
    int option;
    for (int i = 0; i < nb_ecurie; i++) {
        printf("%d. %s\n", i+1, ecuries[i].Nom);
    }
    printf("Quel ecurie voulez vous supprimez : ");
    scanf("%d", &option);
    deleteEcurie(option - 1);
}

void menuDisplayEcurie() {
    int choix;
    for (int i = 0; i < nb_ecurie; i++) {
        printf("%d. %s\n", i+1, ecuries[i].Nom);
    }
    do {
        printf("Quel ecurie voulez vous afficher : ");
        scanf(" %d", &choix);
        if (choix <= 0 || choix > nb_ecurie) {
            printf("Erreur : choix invalide\n");
        }
    } while (choix <= 0 || choix > nb_ecurie);
    displayEcurie(choix-1);
}

void menuEditPointsEcurie() {
    int choix, modifPoints;
    for (int i = 0; i < nb_ecurie; i++) {
        printf("%d. %-16s | Pts : %-3d\n", i+1, ecuries[i].Nom, ecuries[i].Points);
    }
    do {
        printf("De quel ecurie voulez vous modifier les points : ");
        scanf("%d", &choix);
        if (choix <= 0 || choix > nb_ecurie) {
            printf("Erreur : le choix de l'ecurie est invalide\n");
            // on re affiche le menu de choix
            for (int i = 0; i < nb_ecurie; i++) {
                printf("%d. %-16s | Pts : %-3d\n", i+1, ecuries[i].Nom, ecuries[i].Points);
            }
        }
    } while (choix <= 0 || choix > nb_ecurie);
    do {
        printf("Entrez le nouveau nombre de points : ");
        scanf("%d", &modifPoints);
        if (modifPoints < 0) {
            printf("Erreur : le nombre de points ne peux pas etre negatif");
        }
        else if (modifPoints == ecuries[choix - 1].Points) {
            printf("Erreur : le nombre de points ne peux pas etre egale a l'ancien");
        }
    } while (modifPoints < 0 || modifPoints == ecuries[choix - 1].Points);
    updatePointsOfEcurie(choix - 1, modifPoints);
}



// ============================================= MENU PILOTE =============================================

void menuGrandPrix() {
    int choix;
    do {
        printf("\n=== MENU GRAND PRIX ===\n");
        printf("1. Ajouter un Grand Prix\n");
        printf("2. Supprimer un Grand Prix\n");
        printf("3. Modifier les temps d'un Grand Prix\n");
        printf("4. Afficher les temps d'un Grand Prix\n");
        printf("5. Afficher un Grand Prix\n");
        printf("6. Afficher tous les Grand Prix\n");
        printf("7. Afficher les points des pilotes d'un Grand Prix\n");
        printf("8. Retour\n");
        printf("Votre choix : ");
        scanf(" %d", &choix);
        switch (choix) {
            case 1:
                menuNewGrandPrix();
                break;
            case 2:
                menuDeleteGrandPrix();
                break;
            case 3:
                updateResultGrandPrix();
                break;
            case 4:
                menuDisplayTempsGrandPrix();
                break;
            case 5:
                menuDisplayGrandPrix();
                break;
            case 6:
                displayTousGrandPrix();
                break;
            case 7:
                menuDisplayPointsPilotes();
                break;
            case 8:
                printf("Retour au menu principal...\n");
                return;
            default:
                printf("Choix invalide !\n");
                break;
        }
    } while (choix != 8);
}

void menuNewGrandPrix() {
    char nomCircuit[50], pays[50];
    int nombreTours;
    int jour, mois, annee;
    int heure, minute;
    int actif;

    printf("Entrez le nom du circuit : ");
    scanf(" %[^\n]", nomCircuit);

    printf("Entrez le pays : ");
    scanf(" %[^\n]", pays);

    do {
        printf("Entrez le nombre de tour du circuit : ");
        scanf(" %d", &nombreTours);
        if (nombreTours < 10 || nombreTours > 100) {
            printf("Erreur : le nombre de tour doit etre compris entre 10 et 100\n");
        }
    } while (nombreTours < 10 || nombreTours > 100);

    do {
        printf("1. Janvier | 2. Fevrier | 3. Mars | 4. Avril | 5. Mai | 6. Juin\n"
               "7. Juillet | 8. Aout | 9. Septembre | 10. Octobre | 11. Novembre | 12. Decembre\n");
        printf("Entrez le mois du Grand Prix : ");
        scanf(" %d", &mois);
        if (mois < 1 || mois > 12) {
            printf("Erreur : Vous avez entrez un mois invalide\n");
        }
    } while (mois < 1 || mois > 12);

    // initialisation des jours dans un mois pour plus de simpliciter dans la vérification
    int joursParMois[12] = {31,29,31,30,31,30,31,31,30,31,30,31};
    do {
        printf("Entrez le jour du Grand Prix : ");
        scanf(" %d", &jour);

        if (jour < 1 || jour > joursParMois[mois - 1]) {
            printf("Erreur : vous avez choisis un jour en dehors du mois\n");
        }
    } while (jour < 1 || jour > joursParMois[mois - 1]);

    do {
        printf("Entrez l'annee du Grand Prix (l'annee doit etre bissextile) : ");
        scanf(" %d", &annee);
        // si la fonction renvoie 0 -> erreur
        if (annee < 1900 || annee > 2100) {
            printf("Erreur : l'annee doit etre comprise entre 1900 et 2100\n");
        }
        else if (!estBissextile(annee)) {
            printf("Erreur : l'annee saisie n'est pas bissextile\n");
        }
    } while (!estBissextile(annee) || annee < 1900 || annee > 2100);

    do {
        printf("Entrez l'heure du Grand Prix : ");
        scanf(" %d", &heure);
        if (heure < 1 || heure > 23) {
            printf("Erreur : l'heure doit etre comprise entre 1 et 23\n");
        }
    } while (heure < 1 || heure > 23);

    do {
        printf("Entrez les minutes du Grand Prix : ");
        scanf(" %d", &minute);
        if (minute < 1 || minute > 59) {
            printf("Erreur : les minutes doivent etre comprises entre 1 et 59\n");
        }
    } while (minute < 1 || minute > 59);

    do {
        printf("Est ce que le Grand Prix est acitf (1. Oui | 0. Non) : ");
        scanf(" %d", &actif);
        if (actif != 1 && actif != 0) {
            printf("Erreur : veuillez entrer 1 (Actif) ou 0 (Non actif)\n");
        }
    } while (actif != 1 && actif != 0);

    newGrandPrix(nomCircuit, pays, nombreTours,
        (Date){jour, mois, annee}, (Heure){heure, minute}, actif);

}

void menuDisplayTempsGrandPrix() {
    if (nb_grandprix == 0) {
        printf("Erreur : aucun Grand Prix n'est enregistre\n");
        return;
    }

    int choix;
    do {
        printf("De quel Grand Prix voulez vous affichez les temps : \n");
        for (int i = 0; i < nb_grandprix; i++) {
            printf("%d. %-22s | %s\n", i + 1, grandPrix[i].nomCircuit, grandPrix[i].pays);
        }
        printf("Votre choix : ");
        scanf(" %d", &choix);
        if (choix < 0 || choix > nb_grandprix) {
            printf("Erreur : choix invalide\n");
        }
    } while (choix < 0 || choix > nb_grandprix);
    displayTempsPilotes(choix - 1);
}

void menuDisplayGrandPrix() {
    if (nb_grandprix == 0) {
        printf("Erreur : aucun Grand Prix n'est enregistre\n");
        return;
    }

    int choix;
    printf("Voici une liste de tous les grand prix qui existe : \n");
    for (int i = 0; i < nb_grandprix; i++) {
        printf("%d %-23s | %s\n", i + 1, grandPrix[i].nomCircuit, grandPrix[i].pays);
    }
    do {
        printf("Votre choix : ");
        scanf(" %d", &choix);
        if (choix <= 0 || choix > nb_grandprix) {
            printf("Erreur : choix invalide\n");
        }
    } while (choix <= 0 || choix > nb_grandprix);
    displayGrandPrix(choix - 1);
}

void menuDisplayPointsPilotes() {
    if (nb_grandprix == 0) {
        printf("Erreur : aucun Grand Prix n'est enregistre\n");
        return;
    }

    int choix;
    do {
        printf("Liste des Grand Prix : \n");
        for (int i = 0; i < nb_grandprix; i++) {
            printf("%d. %-22s | %s\n", i + 1, grandPrix[i].nomCircuit, grandPrix[i].pays);
        }
        printf("Votre choix : ");
        scanf(" %d", &choix);
        if (choix < 0 || choix > nb_grandprix) {
            printf("Erreur : choix invalide\n");
        }
    } while (choix < 1 || choix > nb_grandprix);
    displayPointsPilotes(choix - 1);
}


void menuDeleteGrandPrix() {
    if (nb_grandprix == 0) {
        printf("Erreur : aucun Grand Prix n'est enregistre\n");
        return;
    }

    int choix;
    do {
        printf("\n=== MENU SUPPRESSION DE GRAND PRIX ===\n");
        for (int i = 0; i < nb_grandprix; i++) {
            printf("%d. %s (%s)\n", i + 1, grandPrix[i].nomCircuit, grandPrix[i].pays);
        }
        printf("Quel grand Prix voulez vous supprimer : ");
        scanf(" %d", &choix);
        if (choix < 0 || choix > nb_grandprix) {
            printf("Erreur : choix invalide\n");
        }
    } while (choix < 0 || choix > nb_grandprix);
    deleteGrandPrix(choix - 1);
}



// =========================================== MENU CLASSEMENT =========================================
void menuClassement() {
    int choix;
    do {
        printf("\n=== MENU CLASSEMENT ===\n");
        printf("1. Afficher le classement de la course\n");
        printf("2. Afficher le classement general des pilotes\n");
        printf("3. Afficher le classement des ecurie\n");
        printf("4. Retour\n");
        printf("Votre choix : ");
        scanf(" %d", &choix);

        switch (choix) {
            case 1:
                menuDisplayClassementCourse();
                break;
            case 2:
                displayGeneralClassementPilote();
                break;
            case 3:
                displayClassementEcurie();
                break;
            case 4:
                printf("Retour au menu principal...\n");
                return; // return rien car fonction void et pas de break, le return quitte la boucle menuClassement et va dans mainMenu
            default:
                printf("Choix invalide !\n");
                break;
        }
    }while (choix != 4);
}

void menuDisplayClassementCourse() {
    if (nb_grandprix == 0) {
        printf("Erreur : aucun Grand Prix n'est enregistre\n");
        return;
    }

    int choix;
    do {
        for (int i = 0; i < nb_grandprix; i++) {
            printf("%d. %s (%s)\n", i + 1, grandPrix[i].nomCircuit, grandPrix[i].pays);
        }
        printf("Entrez l'indice du Grand Prix : ");
        scanf(" %d", &choix);
        if (choix < 0 || choix > nb_grandprix) {
            printf("Erreur : choix invalide\n");
        }

    } while (choix < 0 || choix > nb_grandprix);
    displayClassementCourse(choix - 1);
}






// ===== Autre fonction de gestion de l'input =====
int estBissextile(int annee) {
    // cette fonction calcule une annee pour savoir si elle est bissextile
    // elle renvoie 1 si elle est bissextile et 0 sinon

    // Une année est bissextile si :
    // - elle est divisible par 4
    // - mais pas par 100, sauf si elle est aussi divisible par 400

    if ((annee % 4 == 0 && annee % 100 != 0) || (annee % 400 == 0)) {
        return 1;
    }
    return 0;
}