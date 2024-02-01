#include <stdlib.h>
#include <stdio.h>
#include <graph.h>
#include "grille.h"
#include <unistd.h>

#define TAILLE_CASE 143
#define MARGE_INTERIEURE 2
#define MARGE_EXTERIEURE 4
#define GRILLE_X 290
#define GRILLE_Y 144
#define CYCLE 1000000L
/**
 * @brief Charger l'image en fonction du niveau choisi.
 *
 * @param niveau Représente le niveau que le joueur séléctionne : 1,2 ou 3.
 */
void activation_niveau(int niveau)
{
    char chemin_image_fond[50];
    sprintf(chemin_image_fond, "images/fondgrille%d.jpg", niveau);
    ChargerImageFond(chemin_image_fond);

    unsigned long suivant = Microsecondes() + CYCLE;

    ChargerImage("images/logo2.png", 30, -45, 0, 0, 1600, 900);
    ChargerImage("images/texte_sur_grille.png", 0, 0, 0, 0, 1600, 900);
}
/**
 * @brief Récupère la position de la souris et, si la souris est sur l'un des boutons "jouer" ou "quitter"
 * charge une image avec une couleur différente pour indiquer au joueur sa séléction. Si le joueur clique sur "jouer", les niveaux s'affichent et
 * s'il clique sur "quitter", l'interface graphique se ferme.
 *
 *
 * @return Un entier : soit 1 qui charge la grille de jeu si l'on appuie sur "jouer", soit 2 si le joueur clique sur "quitter"
 */
int affichage_menu()
{

    while (1)
    {

        SourisPosition();
        if ((_X >= 630) && (_X <= 970) && (_Y >= 350) && (_Y <= 443))
        {
            ChargerImage("images/bouton_play.png", 630, 350, 0, 0, 340, 93);
        }
        else
        {
            ChargerImage("images/bouton_play-modified.png", 630, 350, 0, 0, 340, 93);
        }

        if ((_X >= 630) && (_X <= 970) && (_Y >= 500) && (_Y <= 593))
        {
            ChargerImage("images/bouton_exit.png", 630, 500, 0, 0, 340, 93);
        }
        else
        {
            ChargerImage("images/bouton_exit-modified.png", 630, 500, 0, 0, 340, 93);
        }

        if (SourisCliquee())
        {

            if ((_X >= 630) && (_X <= 970) && (_Y >= 350) && (_Y <= 443))
            {
                return 1; // 1 = charger sélection de la grille
            }
            if ((_X >= 630) && (_X <= 970) && (_Y >= 500) && (_Y <= 593))
            {
                return 2; // 2 = fermer le jeu
            }
        }
    }
}
/**
 * @brief Charge les différents niveaux de notre jeu, récupère la position de la souris et affiche avec une surbrillance
 * les niveaux lorsque le joueur passe sa souris dessus. Si il clique sur l'un des trois niveaux, les niveaux correspondants sont chargés.
 *
 * @return 3 entiers : 1 pour le niveau facile, 2 pour le moyen et 3 pour le difficile.
 */
int affichage_selection_grille()
{
    ChargerImageFond("images/image_fond_mario.png");
    ChargerImage("images/logo.png", 0, 0, 0, 0, 1600, 900);
    ChargerImage("images/lvl1-modified.png", 630, 300, 0, 0, 340, 93);
    ChargerImage("images/lvl2-modified.png", 630, 450, 0, 0, 340, 93);
    ChargerImage("images/lvl3-modified.png", 630, 600, 0, 0, 340, 93);

    while (1)
    {
        SourisPosition();
        if ((_X >= 630) && (_X <= 970) && (_Y >= 300) && (_Y <= 423))
        {
            ChargerImage("images/lvl1.png", 630, 300, 0, 0, 340, 93);
        }
        else
        {
            ChargerImage("images/lvl1-modified.png", 630, 300, 0, 0, 340, 93);
        }

        if ((_X >= 630) && (_X <= 970) && (_Y >= 450) && (_Y <= 573))
        {
            ChargerImage("images/lvl2.png", 630, 450, 0, 0, 340, 93);
        }
        else
        {
            ChargerImage("images/lvl2-modified.png", 630, 450, 0, 0, 340, 93);
        }

        if ((_X >= 630) && (_X <= 970) && (_Y >= 600) && (_Y <= 723))
        {
            ChargerImage("images/lvl3.png", 630, 600, 0, 0, 340, 93);
        }
        else
        {
            ChargerImage("images/lvl3-modified.png", 630, 600, 0, 0, 340, 93);
        }

        if (SourisCliquee() == 1)
        {

            if ((_X >= 630) && (_X <= 970) && (_Y >= 300) && (_Y <= 423))
            {
                return 1;
            }
            if ((_X >= 630) && (_X <= 970) && (_Y >= 450) && (_Y <= 573))
            {
                return 2;
            }
            if ((_X >= 630) && (_X <= 970) && (_Y >= 600) && (_Y <= 723))
            {
                return 3;
            }
        }
    }
}
/**
 * @brief Vérifie si la position de la souris est à l'intérieur d'une case.
 *
 * @param x1 Correspond à la coordonnée X en haut à gauche de la case
 * @param y1 Correspond à la coordonnée Y en haut à gauche de la case
 * @param x2 Correspond à la coordonnée X en bas à droite de la case
 * @param y2 Correspond à la coordonnée Y en bas à droite de la case
 * @param x Correspond à la position X de la souris
 * @param y Correspond à la position Y de la souris
 * @return 1 si le joueur se trouve dans la case, 0 sinon.
 */
int clic_dans_case(int x1, int y1, int x2, int y2, int x, int y)
{
    if (x > x1 && x < x2 && y > y1 && y < y2)
        return 1;

    return 0;
}
/**
 * @brief Permet de savoir si un joueur a cliqué sur une des cases de la grille.
 *
 * @param coordX Correspond à la coordonnée X de la case.
 * @param coordY Correspond à la coordonnée Y de la case.
 * @param clicX Correspond à la coordonnée X quand le joueur clique sur la case avec la souris.
 * @param clicY Correspond à la coordonnée Y quand le joueur clique sur la case avec la souris.
 * @param taille_grille correspond à la taille de la grille choisie par le joueur (3 grilles différentes possibles).
 * @return numéro de la case sur laquelle le joueur a cliqué et -1 si le clic n'est pas à l'intérieur de l'une des cases de la grille.
 */
int recuperer_case_cliqueee(int *coordX, int *coordY, int clicX, int clicY, int taille_grille)
{
    int numero_case_cliquee = -1;
    int i = 0;

    while (i < taille_grille && numero_case_cliquee == -1)
    {
        if (clic_dans_case(coordX[i], coordY[i], coordX[i] + TAILLE_CASE, coordY[i] + TAILLE_CASE, clicX, clicY))
        {
            numero_case_cliquee = i;
        }
        i++;
    }
    return numero_case_cliquee;
}
/**
 * @brief Affiche la grille de jeu et gère le déroulement de la partie (gestion des évènements et du temps).
 *
 * @param grille_de_jeu Représente un tableau d'entiers, ceux-ci représentent les numéros des images à afficher dans les cases
 * @param tableau_numeros_sprites Contient les numéros des sprites
 * @param coordX Correspond aux coordonnées X des cases de la grille de jeu
 * @param coordY Correspond aux coordonnées Y des cases de la grille de jeu
 * @param lignes Correspond au nombre de lignes de la grille de jeu.
 * @param colonnes Correspond au nombre de colonnes de la grille de jeu.
 */
void affichage_grille(int *grille_de_jeu, int *tableau_numeros_sprites, int *coordX, int *coordY, int lignes, int colonnes)
{
    int taille_grille = lignes * colonnes;
    generer_grille_de_jeu(grille_de_jeu, taille_grille);
    melanger_grille_de_jeu(grille_de_jeu, taille_grille);
    generer_coordonnees_cases(coordX, coordY, taille_grille, colonnes);
    charger_numero_sprites(tableau_numeros_sprites, taille_grille);

    int premier_choix = -1, second_choix = -1;
    int premier_retourner = -1, second_retourner = -1;
    int premier_position = 0, second_position = 0;
    int case_vide = ChargerSprite("images/case-brique.png");
    int nombre_paire = taille_grille / 2;
    int tab[nombre_paire];
    int fin_verification = 1;

    unsigned long suivant;
    int n = 0;
    int minute = 0;
    int triche = 0;
    int T = 0;

    while (1)
    {

        if (ToucheEnAttente() == 1)
        {
            int touche_presser = Touche();
            if (touche_presser == XK_t)
            {
                if (triche == 0)
                {
                    CopierZone(0, 2, 0, 0, 1600, 900, 0, 0);
                    triche = 1;
                    while (T != taille_grille)
                    {
                        AfficherSprite(tableau_numeros_sprites[grille_de_jeu[T]], coordX[T], coordY[T]);
                        T++;
                    }
                }
                else
                {
                    EffacerEcran(CouleurParNom("white"));
                    CopierZone(2, 0, 0, 0, 1600, 900, 0, 0);
                    triche = 0;
                    T = 0;
                }
            }
        }

        if (triche == 0)
        {
            if (Microsecondes() > suivant)
            {
                n++;
                char buf[100];
                if (n >= 60)
                {
                    n = 0;
                    minute++;
                }
                SourisPosition();
                ChargerImage("images/cache_timer.png", 0, 0, 0, 0, 1600, 900);
                snprintf(buf, 100, "temps: %02d:%02d", minute, n);
                EcrireTexte(1400, 36, buf, 2);
                suivant = Microsecondes() + CYCLE;
            }

            if (SourisCliquee())
            {
                int numero_case_cliquee = recuperer_case_cliqueee(coordX, coordY, _X, _Y, taille_grille);

                if (numero_case_cliquee != -1)
                {
                    if (tab[tableau_numeros_sprites[grille_de_jeu[numero_case_cliquee]]] != 1)
                    {
                        if (premier_choix == 0 && second_choix == -1)
                        {
                            if (premier_position != numero_case_cliquee)
                            {
                                second_position = numero_case_cliquee;
                                second_choix = 0;
                                second_retourner = tableau_numeros_sprites[grille_de_jeu[numero_case_cliquee]];
                            }
                        }

                        if (premier_choix == -1)
                        {
                            premier_position = numero_case_cliquee;
                            premier_choix = 0;
                            premier_retourner = tableau_numeros_sprites[grille_de_jeu[numero_case_cliquee]];
                        }

                        AfficherSprite(tableau_numeros_sprites[grille_de_jeu[numero_case_cliquee]], coordX[numero_case_cliquee], coordY[numero_case_cliquee]);

                        if (premier_choix == 0 && second_choix == 0)
                        {
                            if (premier_retourner == second_retourner)
                            {
                                tab[premier_retourner] = 1;
                                LibererSprite(second_retourner);

                                while (tab[fin_verification] == 1)
                                {
                                    if (fin_verification == nombre_paire)
                                    {
                                        ChargerImage("images/victory-screen.png", 0, 0, 0, 0, 1600, 900);
                                    }
                                    else
                                        fin_verification++;
                                }
                            }
                            else
                            {
                                int temps_attente = 0;
                                while (temps_attente != 1)
                                {
                                    temps_attente++;
                                    usleep(1 * 1000 * 1000);
                                }
                                AfficherSprite(case_vide, coordX[premier_position], coordY[premier_position]);
                                AfficherSprite(case_vide, coordX[second_position], coordY[second_position]);
                            }

                            premier_choix = -1;
                            second_choix = -1;
                            premier_retourner = -1;
                            second_retourner = -1;
                        }
                    }
                }
            }
        }
    }
}
