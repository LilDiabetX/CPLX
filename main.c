#include "struct.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main(){
    noeud *a = creer_feuille(1, 5.);
    noeud *b = creer_feuille(2, 3.);
    noeud *c = creer_feuille(3, 8.);
    noeud *d = creer_feuille(4, 2.);
    noeud *e = creer_feuille(5, 6.);
    noeud *f = creer_feuille(6, 7.);
    noeud *g = creer_feuille(7, 9.);
    noeud *h = creer_feuille(8, 1.);
    noeud *i = creer_feuille(9, 10.);
    noeud *j = creer_feuille(10, 12.);
    arbre_cartesien *arbre = creer_arbre_vide();
    insertion(arbre, a);
    insertion(arbre, b);
    insertion(arbre, c);
    insertion(arbre, d);
    insertion(arbre, e);
    insertion(arbre, f);
    insertion(arbre, g);
    insertion(arbre, h);
    insertion(arbre, i);
    insertion(arbre, j);
    affiche(h);
    printf("\n");
    
    // srand(time(NULL));
    // insertion(arbre, racine);
    /*
    for(int i = 1; i < 1000000; i++){
        double prio = random();
        noeud *n = creer_feuille(i, prio);
        if(!insertion(arbre, n)){
            printf("echec d'insertion %d\n", i);
            return(EXIT_FAILURE);
        }
    }
    printf("réussite\n");
    */
    //affiche(a);
    printf("hauteur : %d\ntaille : %d\n", hauteurArbre(arbre), tailleArbre(arbre));
    return(EXIT_SUCCESS);
}