#include "jeu.h"
#include "plateau.h"
#include "ia.h"
#include <stdio.h>


int main() {
    EtatPartie partie;
    int mode_jeu = 0;

    initialiserPlateau();
    initialiser_partie(&partie);

    printf("--- BIENVENUE AUX ECHECS EN C ---\n");
    printf("1. Joueur vs Joueur\n");
    printf("2. Joueur vs IA\n");
    printf("Choix : ");
    if (scanf("%d", &mode_jeu) != 1) {
        mode_jeu = 1;  // Par défaut: mode 1v1
    }

    while (!partie.est_fini) {
        afficherPlateau();
        
        if (partie.tour_joueur == BLANC) {
            // Tour des BLANCS (toujours humain)
            if (executer_tour(&partie) != 0) {
                printf("Mouvement impossible. Reessayez.\n");
            }
        } else {
            // Tour des NOIRS
            if (mode_jeu == 2) {
                printf("L'IA reflechit (Profondeur 5)...\n");
                jouer_meilleur_coup_IA(5);
                partie.tour_joueur = BLANC; // On rend la main manuellement après l'IA
            } else {
                // Mode 2 joueurs : les NOIRS sont aussi humains
                if (executer_tour(&partie) != 0) {
                    printf("Mouvement impossible. Reessayez.\n");
                }
            }
        }
    }
    return 0;
}