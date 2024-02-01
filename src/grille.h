#ifndef GRILLE_H
#define GRILLE_H

void generer_grille_de_jeu(int *grille_de_jeu, int taille_grille);
void melanger_grille_de_jeu(int *grille_de_jeu, int taille_grille);
void generer_coordonnees_cases(int *coordX, int *coordY, int taille_grille, int nb_colonnes);
void charger_numero_sprites(int *tableau_numeros_sprites, int taille_grille);

#endif