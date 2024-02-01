#include <stdlib.h>
#include <stdio.h>
#include <graph.h>
#include <time.h>
#include "interface.h"
#include "grille.h"

int main()
{
  int *grille_de_jeu, *coord_x, *coord_y, *tableau_numeros_sprites;
  srand(time(NULL));

  InitialiserGraphique();
  CreerFenetre(0, 0, 1600, 900);
  ChargerImageFond("images/image_fond_mario.png");                          // Affiche l'image de fond avec le mario
  ChargerImage("images/logo.png", 0, 0, 0, 0, 1600, 900);                   // Affiche l'image "Super Jeu de paires"
  ChargerImage("images/bouton_play-modified.png", 630, 350, 0, 0, 340, 93); // Charge le bouton "play"
  ChargerImage("images/bouton_exit-modified.png", 630, 500, 0, 0, 340, 93); // Affiche le bouton "exit"

  int code_retour = affichage_menu();
  if (code_retour == 1)
  {
    // Variables permettant le choix du niveau
    int colonnes, lignes;
    // affichage_selection_grille offre 3 possibilités, le niveau correspond soit à 1, 2 ou 3.
    int niveau = affichage_selection_grille();

    if (niveau == 1)
    {
      colonnes = 4;
      lignes = 4;
    }
    else if (niveau == 2)
    {
      colonnes = 6;
      lignes = 4;
    }
    else if (niveau == 3)
    {
      colonnes = 7;
      lignes = 4;
    }
    // On indique ici que la taille de la grille est composée de variables lignes et colonnes
    int taille_grille = lignes * colonnes;
    // On réserve de la mémoire correspondant à la variable taille_grille en fonction du choix du joueur)
    grille_de_jeu = (int *)malloc(taille_grille * sizeof(int));
    coord_x = (int *)malloc(taille_grille * sizeof(int));
    coord_y = (int *)malloc(taille_grille * sizeof(int));
    tableau_numeros_sprites = (int *)malloc((taille_grille / 2) * sizeof(int));
    // On affiche ici la grille correspondante grâce à la fonction activation_niveau()
    activation_niveau(niveau);
    // Ici on fait appel à la fonction affichage_grille qui s'occupe de toute la gestion de la partie une fois le niveau lancé
    affichage_grille(grille_de_jeu, tableau_numeros_sprites, coord_x, coord_y, lignes, colonnes);
  }
  else
  {
    return EXIT_SUCCESS;
  }

  FermerGraphique();
  // Pour chaque malloc effectué, un free est nécessaire.
  free(grille_de_jeu);
  free(coord_x);
  free(coord_y);
  free(tableau_numeros_sprites);

  return EXIT_SUCCESS;
}
