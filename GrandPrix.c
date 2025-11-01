#include "GrandPrix.h"
#include "pilote.h"
#include <string.h>

ResultatCourse resultat[MAX_RESULTATS] = {
    {"Verstappen", "Max", "Pays-Bas", 1, "1:44:12.456", 25},
    {"Leclerc", "Charles", "Monaco", 2, "1:44:18.234", 18},
    {"Hamilton","Lewis", "Royaume-Uni", 3, "1:44:25.678", 15},
    {"Norris", "Lando", "Royaume-Uni", 4, "1:44:32.123", 12},
    {"Sainz", "Carlos", "Espagne", 5, "1:44:39.456", 10},
    {"Russell", "George", "Royaume-Uni", 6, "1:44:45.789", 8},
    {"Perez", "Sergio", "Mexique", 7, "1:44:52.234", 6},
    {"Alonso", "Fernando", "Espagne", 8, "1:44:58.567", 4},
    {"Piastri", "Oscar", "Australie", 9, "1:45:04.890", 2},
    {"Stroll", "Lance", "Canada", 10,"1:45:11.123", 1}
};
// quand un pilote est creer il est ajouter ici
// quand je creer un grand prix je doit ajouter 1 a resultat et créer le tableau

GrandPrix grandPrix[MAX_GRANDPRIX] = {
    {
        "Circuit de Monaco",
        "Monaco",
        78,
        {26, 5, 2024},
        {15, 0},
        {
                {"Verstappen", "Max", "Pays-Bas", 1, "1:44:12.456", 25},
                {"Leclerc", "Charles", "Monaco", 2, "1:44:18.234", 18},
                {"Hamilton","Lewis", "Royaume-Uni", 3, "1:44:25.678", 15},
                {"Norris", "Lando", "Royaume-Uni", 4, "1:44:32.123", 12},
                {"Sainz", "Carlos", "Espagne", 5, "1:44:39.456", 10},
                {"Russell", "George", "Royaume-Uni", 6, "1:44:45.789", 8},
                {"Perez", "Sergio", "Mexique", 7, "1:44:52.234", 6},
                {"Alonso", "Fernando", "Espagne", 8, "1:44:58.567", 4},
                {"Piastri", "Oscar", "Australie", 9, "1:45:04.890", 2},
                {"Stroll", "Lance", "Canada", 10,"1:45:11.123", 1}
        },
        10,
        1
    },
{
    "Circuit de Silverstone",
    "Royaume-Uni",
    52,
    {7, 7, 2024},
    {14, 30},
    {{"Hamilton","Lewis", "Royaume-Uni", 1, "1:28:32.456", 25},
            {"Russell", "George", "Royaume-Uni", 2, "1:28:40.789", 18},
            {"Verstappen", "Max", "Pays-Bas", 3, "1:28:45.123", 15},
            {"Leclerc", "Charles", "Monaco", 4, "1:28:50.456", 12},
            {"Sainz", "Carlos", "Espagne", 5, "1:28:55.789", 10},
            {"Perez", "Sergio", "Mexique", 6, "1:29:00.234", 8},
            {"Alonso", "Fernando", "Espagne", 7, "1:29:05.567", 6},
            {"Piastri", "Oscar", "Australie", 8, "1:29:10.890", 4},
            {"Norris", "Lando", "Royaume-Uni", 9, "1:29:15.123", 2},
            {"Stroll", "Lance", "Canada", 10,"1:29:20.456", 1}
        },
        10,
        1
    },
{
    "Circuit de Monza",
    "Italie",
    53,
    {1, 9, 2024},
    {15, 0},
    {
            {"Verstappen", "Max", "Pays-Bas", 1, "1:21:12.123", 25},
            {"Leclerc", "Charles", "Monaco", 2, "1:21:18.456", 18},
            {"Hamilton","Lewis", "Royaume-Uni", 3, "1:21:25.789", 15},
            {"Russell", "George", "Royaume-Uni", 4, "1:21:32.123", 12},
            {"Sainz", "Carlos", "Espagne", 5, "1:21:38.456", 10},
            {"Perez", "Sergio", "Mexique", 6, "1:21:44.789", 8},
            {"Alonso", "Fernando", "Espagne", 7, "1:21:51.123", 6},
            {"Norris", "Lando", "Royaume-Uni", 8, "1:21:57.456", 4},
            {"Piastri", "Oscar", "Australie", 9, "1:22:03.789", 2},
            {"Stroll", "Lance", "Canada", 10, "1:22:10.123", 1},
    },
    10,
    1
    }

};
int nb_grandprix = 3;
int nb_resultat = 3;


void newGrandPrix(const char* nomCircuit, const char* pays, int nombreTours,
                  Date date, Heure horaire, int actif) {

    strcpy(grandPrix[nb_grandprix].nomCircuit, nomCircuit);
    strcpy(grandPrix[nb_grandprix].pays, pays);
    grandPrix[nb_grandprix].nombreTours = nombreTours;
    grandPrix[nb_grandprix].date = date;
    grandPrix[nb_grandprix].horaire = horaire;
    grandPrix[nb_grandprix].actif = actif;
    grandPrix[nb_grandprix].nombreResultat = nb_pilotes; // un résultat par pilote

    // pour chaque pilote on créer un résultat vide dans le GP
    for (int i = 0; i < nb_pilotes; i++) {
        strcpy(grandPrix[nb_grandprix].resultat[i].nomPilote, pilotes[i].nom);
        strcpy(grandPrix[nb_grandprix].resultat[i].prenomPilote, pilotes[i].prenom);
        strcpy(grandPrix[nb_grandprix].resultat[i].nationnalitePilote, pilotes[i].nationalite);
        grandPrix[nb_grandprix].resultat[i].position = 0;
        strcpy(grandPrix[nb_grandprix].resultat[i].tempsRealise, "0:00:00:000");
        grandPrix[nb_grandprix].resultat[i].pointsObtenus = 0;
    }
    printf("Nouveau Grand Prix ajoute : %s (%s), %d tours le %02d/%02d/%d a %02d:%02d\n",
           nomCircuit, pays, nombreTours, date.jour, date.mois, date.annee, horaire.heures, horaire.minutes);
    nb_grandprix++;
}

void updateResultGranPrix() {
    int h, m, s, ms;
    char nv_temps[20];
    int position = 0;
    int positionPrise[MAX_RESULTATS] = {0};

    // afficher chaque pilote et demander sa position / son temps / les points sont calculer en fonction de la position
    for (int i = 0; i < nb_pilotes; i++) {
        printf("%d. %-10s %-10s | Tps : %s\n", i + 1, resultat[i].prenomPilote, resultat[i].nomPilote,
            resultat[i].tempsRealise);
        // demande le tps du pilote + verif si mise en forme correct
        do {
            printf("Entrez le nouveau temps de %s : ", resultat[i].nomPilote);
            scanf("%19s", nv_temps);

            // sscanf vérifie le nombre d'entrer reçu
            if (sscanf(nv_temps, "%d:%d:%d:%d", &h, &m, &s, &ms) != 4) {
                // si on est different de 4 c'est qu'on a rate
                printf("Format invalide ! Essayez encore (ex: 1:23:45:678)\n");
            }
        } while (sscanf(nv_temps, "%d:%d:%d:%d", &h, &m, &s, &ms) != 4);
        strcpy(resultat[i].tempsRealise, nv_temps);

        do {
            printf("Entrez la position du pilote \"%s %s\": ", resultat[i].prenomPilote, resultat[i].nomPilote);
            scanf("%d%*c", &position); // %*c "mange" le retour a la ligne donc clear le buffer

            if (position <= 0 ||position > nb_pilotes) {
                printf("Position invalide : la position doit etre compris entre 1 et %d\n", nb_pilotes);
            }
            // si positionPrise[position - 1] == 1
            else if (positionPrise[position - 1]) {
                printf("Cette positon est deja prise\n");
            }
        } while (position <= 0 || position > nb_pilotes || positionPrise[position - 1]);

        resultat[i].position = position;
        positionPrise[position - 1] = 1; // marquer comme utilisée

        // attributions des points selon la position
        switch (position) {
            case 1: resultat[i].pointsObtenus = 25; break;
            case 2: resultat[i].pointsObtenus = 18; break;
            case 3: resultat[i].pointsObtenus = 15; break;
            case 4: resultat[i].pointsObtenus = 12; break;
            case 5: resultat[i].pointsObtenus = 10; break;
            case 6: resultat[i].pointsObtenus = 8; break;
            case 7: resultat[i].pointsObtenus = 6; break;
            case 8: resultat[i].pointsObtenus = 4; break;
            case 9: resultat[i].pointsObtenus = 2; break;
            case 10: resultat[i].pointsObtenus = 1; break;
            default: resultat[i].pointsObtenus = 0; break;
        }
    }

}

void deleteGrandPrix(int indexGranPrix) {
    if (indexGranPrix < 0 || indexGranPrix >= nb_grandprix) {
        printf("Erreur : index invalide\n");
        return;
    }
    // delete le grand prix
    printf("\nLe Grand Prix \"%s\" va etre supprimer\n", grandPrix[indexGranPrix].nomCircuit);
    printf("Les resultats du Grand Prix \"%s\" vont etre supprimer\n\n", grandPrix[indexGranPrix].nomCircuit);
    for (int i = indexGranPrix; i < nb_grandprix - 1; i++) {
        grandPrix[i] = grandPrix[i + 1];
    }

    // delete les résultats du grand prix
    for (int i = indexGranPrix; i < nb_resultat - 1; i++) {
        resultat[i] = resultat[i + 1];
    }


    nb_grandprix--;
    nb_resultat--;
    printf("Grand Prix supprimer avec succes\n");
    printf("Resultat supprimer avec succes\n\n");
}


// ===== Affiche 1 grand prix =====
void displayGrandPrix(int indexGrandPrix) {
    if (nb_grandprix == 0) {
        printf("Aucun Grand Prix n'est enregistre\n");
        return;
    }

    printf("\n=== Grand Prix %d ===\n", indexGrandPrix + 1);
    printf("Circuit : %s | Pays : %s | Tours : %d\n", grandPrix[indexGrandPrix].nomCircuit,
        grandPrix[indexGrandPrix].pays, grandPrix[indexGrandPrix].nombreTours);

    printf("Date : %02d/%02d/%d | Horaire : %02d:%02d\n",
           grandPrix[indexGrandPrix].date.jour, grandPrix[indexGrandPrix].date.mois, grandPrix[indexGrandPrix].date.annee,
           grandPrix[indexGrandPrix].horaire.heures, grandPrix[indexGrandPrix].horaire.minutes);
    printf("Nombre de resultats : %d\n", grandPrix[indexGrandPrix].nombreResultat);
    // si actif=1 alors affiche "Oui" sinon affiche "Non"
    printf("Actif : %s\n", grandPrix[indexGrandPrix].actif ? "Oui" : "Non");

}

// ===== Affiche tous les grand prix =====
void displayTousGrandPrix() {
    if (nb_grandprix == 0) {
        printf("Aucun Grand Prix n'est enregistre\n");
        return;
    }

    for (int i = 0; i < nb_grandprix; i++) {

        printf("\n=== Grand Prix %d ===\n", i+1);
        printf("Circuit : %s | Pays : %s | Tours : %d\n",
            grandPrix[i].nomCircuit, grandPrix[i].pays, grandPrix[i].nombreTours);
        printf("Date : %02d/%02d/%d | Horaire : %02d:%02d\n",
               grandPrix[i].date.jour, grandPrix[i].date.mois, grandPrix[i].date.annee,
               grandPrix[i].horaire.heures, grandPrix[i].horaire.minutes);
        printf("Nombre de resultats : %d\n", grandPrix[i].nombreResultat);
        // si actif=1 alors affiche "Oui" sinon affiche "Non"
        printf("Actif : %s\n", grandPrix[i].actif ? "Oui" : "Non");

    }
}

void displayTempsPilotes(int numGrandPrix) {
    // cette fonction affiche le temps de tous les pilotes (même si ils ont pas couru)
    // vu qu'on appelle la fonction dans le menu en faisant : "choix - 1" on a pas besoin de faire
    // -1 partout en appelant le nom du circuit etc...

    printf("\n=== Temps des pilotes pour le Grand Prix de %s | %s ===\n",
           grandPrix[numGrandPrix].nomCircuit, grandPrix[numGrandPrix].pays); // on aurait pus utiliser un pointeur à la place de tout re ecrire
                                                                // mais je prefere comme ça car lors du débugage c'est plus simple de comprendre
                                                                // GrandPrix* gp = &grandPrix[index]; donc gp->resultat[i].position

    for (int i = 0; i < grandPrix[numGrandPrix].nombreResultat; i++) {
        // strcmp retourne 0 si les chaînes sont identiques sinon retourne > 0
        if (strcmp(grandPrix[numGrandPrix].resultat[i].tempsRealise, "0:00:00:000") == 0) {
            printf("%-10s %-10s | Tps : %s (n'a pas couru)\n",
               grandPrix[numGrandPrix].resultat[i].prenomPilote,
               grandPrix[numGrandPrix].resultat[i].nomPilote,
               grandPrix[numGrandPrix].resultat[i].tempsRealise);
        }
        else {
            printf("%-10s %-10s | Tps : %s\n",
                   grandPrix[numGrandPrix].resultat[i].prenomPilote,
                   grandPrix[numGrandPrix ].resultat[i].nomPilote,
                   grandPrix[numGrandPrix].resultat[i].tempsRealise);
        }
    }
}

void displayPointsPilotes(int numGrandPrix) {
    // cette fonction affiche le nombre de points de chaque pilote en fonction de leur position

    // il faut que je boucle sur le nombre de pilote et que suivant leur position j'affiche
    // le bon nombre de point

    for (int i = 0; i < nb_pilotes; i++) {
        printf("%-10s %-10s | Points : %d\n",
            grandPrix[numGrandPrix].resultat[i].prenomPilote,
            grandPrix[numGrandPrix].resultat[i].nomPilote,
            grandPrix[numGrandPrix].resultat[i].pointsObtenus);
    }



}