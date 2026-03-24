# Makefile pour le projet d'Échecs en C
# Simple et efficace pour compiler le projet

# Compilateur et options
CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -O2
LDFLAGS = 

# Fichiers source
SOURCES = main.c jeu.c plateau.c pieces.c ia.c
OBJECTS = $(SOURCES:.c=.o)
EXECUTABLE = chess

# Cibles principales
all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) -o $@ $^
	@echo "✓ Compilation réussie: $(EXECUTABLE)"

# Compilation des fichiers objet
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Nettoyer les fichiers compilés
clean:
	rm -f $(OBJECTS)
	@echo "✓ Fichiers objet supprimés"

# Nettoyer complètement (objet + exécutable)
distclean: clean
	rm -f $(EXECUTABLE)
	@echo "✓ Tout supprimé (fichiers objet + exécutable)"

# Rebuild: nettoyer puis recompiler
rebuild: distclean all

# Exécuter le programme
run: $(EXECUTABLE)
	./$(EXECUTABLE)

# Aide
help:
	@echo "Makefile pour Chess-AI"
	@echo "======================"
	@echo "make          - Compiler le projet"
	@echo "make clean    - Supprimer les fichiers .o"
	@echo "make distclean - Supprimer tous les fichiers générés"
	@echo "make rebuild  - Recompiler de zéro"
	@echo "make run      - Compiler et exécuter"
	@echo "make help     - Afficher cette aide"

# Déclaration des cibles sans fichiers
.PHONY: all clean distclean rebuild run help
