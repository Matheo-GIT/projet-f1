#include "GrandPrix.h"
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
        10, // <- nb de pilote
        1
    }
};
int nb_grandprix = 1;
int nb_resultat = 1;


void newGrandPrix(const char* nomCircuit, const char* pays, int nombreTours,
                  Date date, Heure horaire, int nombreResultat, int actif) {

    strcpy(grandPrix[nb_grandprix].nomCircuit, nomCircuit);
    strcpy(grandPrix[nb_grandprix].pays, pays);
    grandPrix[nb_grandprix].nombreTours = nombreTours;
    grandPrix[nb_grandprix].date = date;
    grandPrix[nb_grandprix].horaire = horaire;
    grandPrix[nb_grandprix].nombreResultat = nombreResultat;
    grandPrix[nb_grandprix].actif = actif;

    // Copie des résultats
    for (int i = 0; i < nombreResultat; i++) {
        grandPrix[nb_grandprix].resultat[i] = resultat[i];
    }

    // nb_resultat + 1 car nouveau grand prix donc un resultat en plus
    // je doit mettre tous les pilotes dedans
    for (int i = 0; i < nb_pilotes; i++) {
        strcpy(resultat[nb_grandprix].nomPilote, pilotes[i].nom);
        strcpy(resultat[nb_grandprix].prenomPilote, pilotes[i].prenom);
        strcpy(resultat[nb_grandprix].nationnalitePilote, pilotes[i].nationalite);
        resultat[nb_grandprix].position = i + 1;
        strcpy(resultat[nb_grandprix].tempsRealise, "0:00:00:000");
    }

    nb_grandprix++;
}

void updateResultGranPrix() {
    int h, m, s, ms;
    char nv_temps[20];
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
        strcpy(resultat[i].prenomPilote, nv_temps);
    }
}

void deleteGrandPrix(int indexGranPrix) {
    if (indexGranPrix < 0 || indexGranPrix >= nb_grandprix) {
        printf("Erreur : index invalide\n");
        return;
    }
    printf("Le Grand Prix %s va etre supprimer\n", grandPrix[indexGranPrix].nomCircuit);
    for (int i = indexGranPrix; i < nb_grandprix - 1; i++) {
        grandPrix[i] = grandPrix[i + 1];
    }
    nb_grandprix--;
    printf("Grand Prix supprimer avec succes\n");
}


void displayGrandPrix() {
    if (nb_grandprix == 0) {
        printf("Aucun Grand Prix n'est enregistré.\n");
        return;
    }

    for (int i = 0; i < nb_grandprix; i++) {
        GrandPrix* gp = &grandPrix[i];

        printf("\n=== Grand Prix %d ===\n", i+1);
        printf("Circuit : %s | Pays : %s | Tours : %d\n", gp->nomCircuit, gp->pays, gp->nombreTours);
        printf("Date : %02d/%02d/%d | Horaire : %02d:%02d\n",
               gp->date.jour, gp->date.mois, gp->date.annee,
               gp->horaire.heures, gp->horaire.minutes);
        printf("Nombre de resultats : %d\n", gp->nombreResultat);
        printf("Actif : %s\n", gp->actif ? "Oui" : "Non"); // si actif=1 alors affiche "Oui" sinon affiche "Non"

        // peut etre afficher le classement des grandpris ?
    }
}


void displayTempsPilotes(int numGrandPrix) {
    printf("Affichage des temps pour le Grand Prix a %s\n", grandPrix[numGrandPrix - 1].pays);
    for (int i = 0; i < nb_pilotes; i++) {
        printf("%d. %-10s %-10s | Tps : %s\n", i + 1, pilotes[i].prenom, pilotes[i].nom, resultat[numGrandPrix - 1].tempsRealise);
    }
}