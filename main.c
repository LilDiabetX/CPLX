#include "struct.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <assert.h>

int main(){
    // Exercice 1.e   
    noeud *a4 = creer_feuille(1, 5.);
    noeud *b4 = creer_feuille(2, 3.);
    noeud *c4 = creer_feuille(3, 8.);
    noeud *d4 = creer_feuille(4, 2.);
    noeud *e4 = creer_feuille(5, 6.);
    noeud *f4 = creer_feuille(6, 7.);
    noeud *g4 = creer_feuille(7, 9.);
    noeud *h4 = creer_feuille(8, 1.);
    noeud *i4 = creer_feuille(9, 10.);
    noeud *j4 = creer_feuille(10, 12.);

    arbre_cartesien *arbre4 = creer_arbre_vide();
    h4->pere = h4;
    d4->pere = h4;
    i4->pere = h4;
    h4->fils_gauche = d4;
    h4->fils_droit = i4;
    b4->pere = d4;
    e4->pere = d4;
    d4->fils_gauche = b4;
    d4->fils_droit = e4;
    j4->pere = i4;
    i4->fils_droit = j4;
    a4->pere = b4;
    c4->pere = b4;
    b4->fils_gauche = a4;
    b4->fils_droit = c4;
    f4->pere = e4;
    e4->fils_droit = f4;
    g4->pere = f4;
    f4->fils_droit = g4;
    arbre4->racine = h4;

    // Exercice 2
    printf("Exercice 2\n");
    noeud *n = recherche(arbre4, 50);
    assert(n == NULL);
    n = recherche(arbre4, 1);
    assert(n == a4);

    // Exercice 3.d.1
    printf("\nExercice 3.d.1\n");
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

    arbre_cartesien *arbre1 = creer_arbre_vide();

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

    bool verif = equalsArbre(arbre1, arbre4);
    assert(verif == true);
    printf("hauteur : %d\ntaille : %d\n", hauteurArbre(arbre1), tailleArbre(arbre1));
    destroy_arbre(arbre1);
    
    // Exercice 3.d.2
    printf("\nExercice 3.d.2\n");
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

    arbre_cartesien *arbre2 = creer_arbre_vide();

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
    
    verif = equalsArbre(arbre1, arbre4);
    assert(verif == true);
    printf("hauteur : %d\ntaille : %d\n", hauteurArbre(arbre2), tailleArbre(arbre2));
    destroy_arbre(arbre2);
    
    // Exercice 3.d.3 + 4.d
    printf("\nExercice 3.d.3\n");
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

    noeud *b6 = creer_feuille(2, 3.);
    noeud *c6 = creer_feuille(3, 8.);
    noeud *d6 = creer_feuille(4, 2.);
    noeud *e6 = creer_feuille(5, 6.);
    noeud *f6 = creer_feuille(6, 7.);
    noeud *g6 = creer_feuille(7, 9.);
    noeud *i6 = creer_feuille(9, 10.);

    arbre_cartesien *arbre3 = creer_arbre_vide();
    arbre_cartesien *arbre6 = creer_arbre_vide();

    d6->pere = d6;
    d6->fils_gauche = b6;
    d6->fils_droit = e6;
    b6->pere = d6;
    e6->pere = d6;
    b6->fils_droit = c6;
    c6->pere = b6;
    e6->fils_droit = f6;
    f6->pere = e6;
    f6->fils_droit = g6;
    g6->pere = f6;
    g6->fils_droit = i6;
    i6->pere = g6;
    arbre6->racine = d6;

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

    verif = equalsArbre(arbre1, arbre4);
    assert(verif == true);
    printf("hauteur : %d\ntaille : %d\n", hauteurArbre(arbre3), tailleArbre(arbre3));
    
    printf("\nExercice 4.d\n");
    suppression(arbre3, 1);
    suppression(arbre3, 10);
    suppression(arbre3, 8);

    verif = equalsArbre(arbre3, arbre6);
    assert(verif == true);
    printf("hauteur : %d\ntaille : %d\n", hauteurArbre(arbre3), tailleArbre(arbre3));
    destroy_arbre(arbre3);
    destroy_arbre(arbre4);
    
    // Exercice 5
    printf("\nExercice 5\n");
    srand(time(NULL));
    arbre_cartesien *arbre5 = creer_arbre_vide();
    double prio = (rand() % 1000000) / 1000000.0;
    noeud *racine = creer_feuille(0, prio);
    insertion(arbre5, racine);
    for(int i = 1; i < 1000000; i++){
        prio = (rand() % 1000000) / 1000000.0;
        noeud *n = creer_feuille(i, prio);
        if(!insertion(arbre5, n)){
            printf("echec d'insertion %d\n", i);
            return(EXIT_FAILURE);
        }
    }
    printf("réussite d'insertion\n");
    printf("hauteur : %d\ntaille : %d\n", hauteurArbre(arbre5), tailleArbre(arbre5));
    destroy_arbre(arbre5);
    
    return(EXIT_SUCCESS);
}