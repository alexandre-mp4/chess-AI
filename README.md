# Chess AI - Polytech Marseille

Un jeu d'échecs en C avec une IA utilisant l'algorithme Minimax avec élagage Alpha-Bêta.

## Fonctionnalités

- ✅ Jeu d'échecs complet avec règles standard
- ✅ Mode 1v1 (deux joueurs humains)
- ✅ Mode Joueur vs IA (profondeur de recherche configurable)
- ✅ Algorithme Minimax avec élagage Alpha-Bêta
- ✅ Tables d'évaluation des positions (Square-Table)
- ✅ Détection d'échec et mat
- ✅ Affichage du plateau en temps réel
- ✅ Entrée en notation algébrique standard (ex: e2 e4)

## Installation et compilation

### Avec Makefile (recommandé)

```bash
# Compiler le projet
make

# Compiler et exécuter
make run

# Nettoyer les fichiers objet
make clean

# Nettoyer complètement
make distclean

# Recompiler de zéro
make rebuild

# Afficher l'aide
make help
```

### Compilation manuelle

```bash
gcc -Wall -Wextra -std=c99 -O2 main.c jeu.c plateau.c pieces.c ia.c -o chess
```

## Exécution

```bash
./chess
```

### Modes de jeu

1. **Joueur vs Joueur**: Mode pour deux joueurs humains
2. **Joueur vs IA**: Joueur contre l'IA (profondeur 5)

### Entrée

Les mouvements se font en notation algébrique:
- **Colonnes**: a-h (de gauche à droite)
- **Lignes**: 1-8 (de bas en haut)
- **Format**: `<case_depart> <case_arrivee>` (ex: `e2 e4`)

## Structure du code

```
main.c          - Point d'entrée du programme
jeu.c/jeu.h     - Logique du jeu, tours, échecs et mats
plateau.c/h     - Gestion du plateau et affichage
pieces.c/h      - Validation des mouvements
ia.c/ia.h       - Algorithme Minimax et évaluation
```

## Détails techniques

### Évaluation du plateau

Chaque pièce a une valeur de base:
- Pion: 100 points
- Cavalier: 320 points
- Fou: 330 points
- Tour: 500 points
- Dame: 900 points
- Roi: 20000 points

### Tables d'évaluation

Des tables de positionnement (Square-Table) ajustent l'évaluation selon la position de la pièce sur l'échiquier, encourageant des positions stratégiques.

### Algorithme Minimax

L'algorithme Minimax avec élagage Alpha-Bêta explore l'arbre des mouvements jusqu'à une profondeur définie pour trouver le meilleur coup.

## Compilation vérifiée

✅ **Pas d'erreurs**
✅ **Pas d'avertissements**
✅ **Code compilé avec**: `-Wall -Wextra -std=c99 -O2`

## Auteurs

- Alexandre
- Ziane
