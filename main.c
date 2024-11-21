#include "struct.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main(){
    /*
    noeud *a1 = creer_feuille(1, 5.);
    noeud *b1 = creer_feuille(2, 3.);
    noeud *c1 = creer_feuille(3, 8.);
    noeud *d1 = creer_feuille(4, 2.);
    noeud *e1 = creer_feuille(5, 6.);
    noeud *f1 = creer_feuille(6, 7.);
    noeud *g1 = creer_feuille(7, 9.);
    noeud *h1 = creer_feuille(8, 1.);
    noeud *i1 = creer_feuille(9, 10.);
    noeud *j1 = creer_feuille(10, 12.);
    /
    noeud *a2 = creer_feuille(1, 5.);
    noeud *b2 = creer_feuille(2, 3.);
    noeud *c2 = creer_feuille(3, 8.);
    noeud *d2 = creer_feuille(4, 2.);
    noeud *e2 = creer_feuille(5, 6.);
    noeud *f2 = creer_feuille(6, 7.);
    noeud *g2 = creer_feuille(7, 9.);
    noeud *h2 = creer_feuille(8, 1.);
    noeud *i2 = creer_feuille(9, 10.);
    noeud *j2 = creer_feuille(10, 12.);
    */
    noeud *a3 = creer_feuille(1, 5.);
    noeud *b3 = creer_feuille(2, 3.);
    noeud *c3 = creer_feuille(3, 8.);
    noeud *d3 = creer_feuille(4, 2.);
    noeud *e3 = creer_feuille(5, 6.);
    noeud *f3 = creer_feuille(6, 7.);
    noeud *g3 = creer_feuille(7, 9.);
    noeud *h3 = creer_feuille(8, 1.);
    noeud *i3 = creer_feuille(9, 10.);
    noeud *j3 = creer_feuille(10, 12.);
    
    // arbre_cartesien *arbre1 = creer_arbre_vide();
    // arbre_cartesien *arbre2 = creer_arbre_vide();
    arbre_cartesien *arbre3 = creer_arbre_vide();
    /*
    insertion(arbre1, a1);
    insertion(arbre1, b1);
    insertion(arbre1, c1);
    insertion(arbre1, d1);
    insertion(arbre1, e1);
    insertion(arbre1, f1);
    insertion(arbre1, g1);
    insertion(arbre1, h1);
    insertion(arbre1, i1);
    insertion(arbre1, j1);
    affiche(d1);
    printf("\n");
    affiche(i1);
    printf("\n");
    affiche(g1);
    printf("\n");
    /*
    insertion(arbre2, h2);
    insertion(arbre2, g2);
    insertion(arbre2, a2);
    insertion(arbre2, b2);
    insertion(arbre2, d2);
    insertion(arbre2, f2);
    insertion(arbre2, c2);
    insertion(arbre2, j2);
    insertion(arbre2, i2);
    insertion(arbre2, e2);
    affiche(h2);
    printf("\n");
    affiche(d2);
    printf("\n");
    affiche(i2);
    printf("\n");
    affiche(e2);
    printf("\n");
    affiche(b2);
    printf("\n");
    */
    insertion(arbre3, e3);
    insertion(arbre3, h3);
    insertion(arbre3, b3);
    insertion(arbre3, d3);
    insertion(arbre3, c3);
    insertion(arbre3, f3);
    insertion(arbre3, g3);
    insertion(arbre3, j3);
    insertion(arbre3, a3);
    insertion(arbre3, i3);
    affiche(h3);
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
    // printf("hauteur : %d\ntaille : %d\n", hauteurArbre(arbre1), tailleArbre(arbre1));
    // printf("hauteur : %d\ntaille : %d\n", hauteurArbre(arbre2), tailleArbre(arbre2));
    printf("hauteur : %d\ntaille : %d\n", hauteurArbre(arbre3), tailleArbre(arbre3));
    return(EXIT_SUCCESS);
}