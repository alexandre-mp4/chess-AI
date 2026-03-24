#ifndef JEU_H
#define JEU_H

#include "pieces.h"
#include "plateau.h"

typedef struct EtatPartie_t {
    Couleur tour_joueur;
    int est_fini;
    int en_echec;
} EtatPartie;

void initialiser_partie(EtatPartie *partie);
int executer_tour(EtatPartie *partie);
int est_echec(Couleur c);
int est_mat(EtatPartie *partie);

#endif