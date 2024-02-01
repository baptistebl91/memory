#include <stdlib.h>
#include <stdio.h>
#include <graph.h>
#include <time.h>
// Définitions de constantes correspondantes aux tailles d'une case présente sur la grille de jeu.
#define TAILLE_CASE 143
#define MARGE_INTERIEURE 2
#define MARGE_EXTERIEURE 4
#define GRILLE_X 290
#define GRILLE_Y 144
/**
 * @brief Génère un tableau d'entiers qui double le numéro de chaque image pour représenter une paire. A chaque fois que l'on rentre dans la boucle,
 * le compteur augmente et on remplit une case à l'index actuel et au suivant permettant de générer des cases doublées.
 *
 * @param grille_de_jeu Tableau d'entiers qui va contenir les paires.
 * @param taille_grille correspond à la taille de la grille choisie par le joueur (3 grilles différentes possibles).
 */

void generer_grille_de_jeu(int *grille_de_jeu, int taille_grille)
{

    int compteur = 0;
    for (int i = 0; i < taille_grille; i += 2)
    {

        grille_de_jeu[i] = compteur;
        grille_de_jeu[i + 1] = compteur;
        compteur++;
    }
}
/**
 * @brief Mélange la grille générée précédemment.
 *
 * @param grille_de_jeu Représente un tableau d'entiers, ceux-ci représentent les numéros des images à afficher dans les cases.
 * @param taille_grille correspond à la taille de la grille choisie par le joueur (3 grilles différentes possibles).
 */
void melanger_grille_de_jeu(int *grille_de_jeu, int taille_grille)
{
    for (int i = 0; i < taille_grille - 1; i++)
    {
        int j = i + rand() / (RAND_MAX / (taille_grille - i) + 1);
        int tmp = grille_de_jeu[j]; // échange avec tmp car sinon écrasement des valeurs.
        grille_de_jeu[j] = grille_de_jeu[i];
        grille_de_jeu[i] = tmp;
    }
}
/**
 * @brief
 *
 * @param coordX Correspond aux coordonnées X des cases de la grille de jeu
 * @param coordY Correspond aux coordonnées Y des cases de la grille de jeu
 * @param taille_grille correspond à la taille de la grille choisie par le joueur (3 grilles différentes possibles).
 * @param nb_colonnes le nombre de colonnes de la grille de jeu qui varie en fonction de la taille de la grille.
 */
void generer_coordonnees_cases(int *coordX, int *coordY, int taille_grille, int nb_colonnes)
{
    for (int i = 0; i < taille_grille; i++)
    {
        if (i == 0)
        {
            coordX[0] = GRILLE_X + MARGE_EXTERIEURE;
            coordY[0] = GRILLE_Y + MARGE_EXTERIEURE;
        }
        else if (i % nb_colonnes == 0)
        {
            coordX[i] = GRILLE_X + MARGE_EXTERIEURE;
            coordY[i] = coordY[i - 1] + TAILLE_CASE + MARGE_INTERIEURE;
        }
        else
        {
            coordX[i] = coordX[i - 1] + TAILLE_CASE + MARGE_INTERIEURE;
            coordY[i] = coordY[i - 1];
        }
    }
}
/**
 * @brief Charge les sprites numérotés correspondants avec les cases de la grille de jeu
 *
 * @param tableau_numeros_sprites charge les sprites correspondants à la taille de la grille / 2.
 * @param taille_grille correspond à la taille de la grille choisie par le joueur (3 grilles différentes possibles).
 */
void charger_numero_sprites(int *tableau_numeros_sprites, int taille_grille)
{

    int taille_tableau = taille_grille / 2;

    for (int i = 0; i < taille_tableau; i++)
    {
        char chemin_sprite[50];

        sprintf(chemin_sprite, "images/%d.png", i);
        tableau_numeros_sprites[i] = ChargerSprite(chemin_sprite);

        if (tableau_numeros_sprites[i] == -1)
        {
            fprintf(stderr, "Erreur lors du chargement du Sprite %s.\n", chemin_sprite);
        }
    }
}