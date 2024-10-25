#include <stdlib.h>
#include <stdio.h>
#include "struct.h"

/**
 * Crée un noeud racine d'un arbre cartésien
 * @param c clef du noeud
 * @param prio priorité du noeud
 * @return un noeud sans fils
 */
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

/**
 * Crée un noeud avec des fils
 * @param c clef du noeud
 * @param prio priorité du noeud
 * @param gauche fils gauche du noeud créé (peut être NULL)
 * @param droit fils droit du noeud créé (peut être NULL)
 * @return un noeud avec des fils
 */
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

/**
 * Vérifie si un noeud est une feuille (n'a pas de fils)
 * @param n noeud dont on veut savoir si c'est une feuille
 * @return true si le noeud est une feuille, false sinon
 */
bool isLeaf(noeud *n){
    return n->fils_droit == NULL && n->fils_gauche == NULL;
}

/**
 * Libère un noeud de la mémoire
 * @param n noeud à libérer de la mémoire
 */
void destroy_noeud(noeud *n){
    if(n->fils_gauche != NULL){
        destroy(n->fils_gauche);
    }
    if(n->fils_droit != NULL){
        destroy(n->fils_droit);
    }

    free(n);
}

/**
 * Créé un arbre vide
 * @return un arbre vide
 */
arbre_cartesien *creer_arbre_vide(){
    arbre_cartesien *arbre = malloc(sizeof(arbre_cartesien));
    if(arbre == NULL){
        perror("Problème d'allocation.");
        exit(EXIT_FAILURE);
    }

    arbre->racine = NULL;
    
    return arbre;
}

/**
 * Cherche un noeud dans un arbre selon sa clef
 * @param a arbre dans lequel rechercher le noeud
 * @param clef clef de recherche du noeud
 * @return le noeud avec la clef spécifiée s'il est dans l'arbre, NULL sinon
 */
noeud *recherche(arbre_cartesien *a, char clef){
    noeud *actuel = a->racine;
    while(actuel != NULL){
        if(actuel->clef == clef){
            return actuel;
        }
        else if(actuel->clef < clef){
            actuel = actuel->fils_droit;
        }
        else{
            actuel = actuel->fils_gauche;
        }
    }
    return NULL;
}

/**
 * Libère un arbre de la mémoire
 * @param a arbre à libérer de la mémoire
 */
void destroy_arbre(arbre_cartesien * a){
    if(a->racine != NULL){
        destroy_noeud(a->racine);
    }

    free(a);
}