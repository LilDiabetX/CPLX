#include <stdlib.h>
#include <stdio.h>
#include "struct.h"

noeud *creer_racine(char c, int prio){
    noeud * racine = malloc(sizeof(noeud));
    if(racine == NULL){
        perror("Problème d'allocation.");
        exit(EXIT_FAILURE);
    }

    racine->clef = c;
    racine->priorite = prio;
    racine->fils_gauche = NULL;
    racine->fils_droit = NULL;

    return racine;
}

noeud *creer_noeud(char c, int prio, noeud *gauche, noeud *droit){
    noeud * new_noeud = malloc(sizeof(noeud));
    if(new_noeud == NULL){
        perror("Problème d'allocation.");
        exit(EXIT_FAILURE);
    }

    new_noeud->clef = c;
    new_noeud->priorite = prio;
    new_noeud->fils_gauche = gauche;
    new_noeud->fils_droit = droit;

    return new_noeud;
}

bool isLeaf(noeud *n){
    return n->fils_droit == NULL && n->fils_gauche == NULL;
}

void destroy_noeud(noeud *n){
    if(n->fils_gauche != NULL){
        destroy(n->fils_gauche);
    }
    if(n->fils_droit != NULL){
        destroy(n->fils_droit);
    }

    free(n);
}

arbre_cartesien *creer_arbre_vide(){
    arbre_cartesien *arbre = malloc(sizeof(arbre_cartesien));
    if(arbre == NULL){
        perror("Problème d'allocation.");
        exit(EXIT_FAILURE);
    }

    arbre->racine = NULL;
    
    return arbre;
}

void destroy_arbre(arbre_cartesien * a){
    if(a->racine != NULL){
        destroy_noeud(a->racine);
    }
    
    free(a);
}