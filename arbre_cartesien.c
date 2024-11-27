#include <stdlib.h>
#include <stdio.h>
#include "struct.h"

/**
 * Affiche les clefs des noeuds d'un sous arbre selon un parcours préfixe
 * @param n racine du sous arbre
 */
void affiche(noeud *n){
    printf("actuel : %d pere : %d\n", n->clef, n->pere->clef);
    if(n->fils_gauche != NULL){
        affiche(n->fils_gauche);
    }
    if(n->fils_droit != NULL){
        affiche(n->fils_droit);
    }
}

/**
 * Crée un noeud sans fils et sans père
 * @param c clef du noeud
 * @param prio priorité du noeud
 * @return un noeud avec des fils
 */
noeud *creer_feuille(uint32_t c, double prio){
    noeud * new_noeud = malloc(sizeof(noeud));
    if(new_noeud == NULL){
        perror("Problème d'allocation.");
        exit(EXIT_FAILURE);
    }

    new_noeud->clef = c;
    new_noeud->priorite = prio;
    new_noeud->pere = NULL;
    new_noeud->fils_gauche = NULL;
    new_noeud->fils_droit = NULL;

    return new_noeud;
}

/**
 * Crée un noeud avec des fils
 * @param c clef du noeud
 * @param prio priorité du noeud
 * @param pere père du noeud
 * @param gauche fils gauche du noeud créé (peut être NULL)
 * @param droit fils droit du noeud créé (peut être NULL)
 * @return un noeud avec des fils
 */
// Uniquement utilisé pour du debug
noeud *creer_noeud(char c, double prio, noeud *pere, noeud *gauche, noeud *droit){
    noeud * new_noeud = malloc(sizeof(noeud));
    if(new_noeud == NULL){
        perror("Problème d'allocation.");
        exit(EXIT_FAILURE);
    }

    new_noeud->clef = c;
    new_noeud->priorite = prio;
    new_noeud->pere = pere;
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
 * renvoie le fils droit d'un noeud
 * @param n noeud dont on veut le fils droit
 * @return renvoie le fils droit du noeud
 */
noeud *get_fils_droit(noeud *n){
    if(n == NULL){
        return NULL;
    }
    else return n->fils_droit;
}

/**
 * renvoie le fils gauche d'un noeud
 * @param n noeud dont on veut le fils gauche
 * @return renvoie le fils gauche du noeud
 */
noeud *get_fils_gauche(noeud *n){
    if(n == NULL){
        return NULL;
    }
    else return n->fils_gauche;
}

/**
 * Libère un noeud de la mémoire
 * @param n noeud à libérer de la mémoire
 */
void destroy_noeud(noeud *n){
    if(n->fils_gauche != NULL){
        destroy_noeud(n->fils_gauche);
    }
    if(n->fils_droit != NULL){
        destroy_noeud(n->fils_droit);
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
noeud *recherche(arbre_cartesien *a, uint32_t clef){
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
 * Vérifie si un arbre est vide
 * @param a arbre à tester
 * @return true si l'arbre est vide false sinon
 */
bool isEmpty(arbre_cartesien *a){
    return a->racine == NULL;
}

/**
 * Insère un noeud dans un arbre cartésien en fonction de sa clef et de sa priorité
 * @param a arbre cartésien dans lequel on veut insérer le noeud
 * @param n noeud à insérer
 * @return true si on a réussi à insérer le noeud, false sinon
 */
bool insertion(arbre_cartesien *a, noeud *n){
    if(!isLeaf(n)){
        return false;
    }
    if(isEmpty(a)){
        a->racine = n;
        n->pere = n;
        return true;
    }
    noeud *actuel = a->racine;
    while(!isLeaf(actuel)){
        if(actuel->clef == n->clef){
            return false;
        }
        else if(actuel->clef > n->clef && actuel->fils_gauche != NULL){
            actuel = actuel->fils_gauche;
        }
        else if(actuel->clef < n->clef && actuel->fils_droit != NULL){
            actuel = actuel->fils_droit;
        }
        else if(actuel->clef > n->clef){
            actuel->fils_gauche = n;
            n->pere = actuel;
            rotations(a, n);
            return true;
        }
        else if(actuel->clef < n->clef){
            actuel->fils_droit = n;
            n->pere = actuel;
            rotations(a, n);
            return true;
        }
    }
    if(actuel->clef == n->clef){
        return false;
    }
    else if(actuel->clef > n->clef){
        actuel->fils_gauche = n;
        n->pere = actuel;
    }
    else if(actuel->clef < n->clef){
        actuel->fils_droit = n;
        n->pere = actuel;
    }
    rotations(a, n);
    return true;
}

/**
 * effectue les rotations nécessaires pour conserver la propriété de tas de l'arbre cartésien dans lequel se trouve le noeud
 * @param n noeud à partir duquel on veut effectuer les rotations
 */
void rotations(arbre_cartesien *a, noeud *n){
    noeud *parent = n->pere;
    while(parent->priorite > n->priorite){
        if(parent->fils_gauche == n){
            rotation_droite(a, parent, n);
        }
        else{
            rotation_gauche(a, parent, n);
        }
        parent = n->pere;
    }
}

/**
 * effectue une rotation vers la droite du sous arbre
 * @param pere racine du sous arbre
 * @param n fils avec lequel effectuer la rotation
 */
void rotation_droite(arbre_cartesien *a, noeud *pere, noeud *n){
    if(pere->pere != pere){
        n->pere = pere->pere;
        if(pere->pere->fils_droit == pere){
            pere->pere->fils_droit = n;
        }
        else{
            pere->pere->fils_gauche = n;
        }
    }
    else{
        n->pere = n;
        a->racine = n;
    }
    pere->pere = n;
    pere->fils_gauche = n->fils_droit;
    if(pere->fils_gauche != NULL){
        pere->fils_gauche->pere = pere;
    }
    n->fils_droit = pere;  
}

/**
 * effectue une rotation vers la gauche du sous arbre
 * @param pere racine du sous arbre
 * @param n fils avec lequel effectuer la rotation
 */
void rotation_gauche(arbre_cartesien *a, noeud *pere, noeud *n){
    if(pere->pere != pere){
        n->pere = pere->pere;
        if(pere->pere->fils_droit == pere){
            pere->pere->fils_droit = n;
        }
        else{
            pere->pere->fils_gauche = n;
        }
    }
    else{
        n->pere = n;
        a->racine = n;
    }
    pere->pere = n;
    pere->fils_droit = n->fils_gauche;
    if(pere->fils_droit != NULL){
        pere->fils_droit->pere = pere;
    }
    n->fils_gauche = pere;
}

/**
 * supprime un noeud d'un arbre cartésien en conservant les propriétés d'arbre de recherche et de tas
 * @param a arbre duquel on veut supprimer un noeud
 * @param c clef du noeud qu'on veut supprimer
 * @return true si on a supprimé le noeud de l'arbre, false sinon
 */
bool suppression(arbre_cartesien *a, uint32_t c){
    noeud *n = recherche(a, c);
    if(n == NULL){
        return false;
    }
    while(!isLeaf(n)){
        if(n->fils_gauche != NULL && n->fils_droit != NULL){
            if(n->fils_gauche->priorite < n->fils_droit->priorite){
                rotation_droite(a, n, n->fils_gauche);
            }
            else{
                rotation_gauche(a, n, n->fils_droit);
            }
        }
        else if(n->fils_gauche != NULL){
            rotation_droite(a, n, n->fils_droit);
        }
        else{
            rotation_gauche(a, n, n->fils_droit);
        }
    }
    if(n->pere->fils_gauche == n){
        n->pere->fils_gauche = NULL;
    }
    else{
        n->pere->fils_droit = NULL;
    }
    destroy_noeud(n);
    return true;
}

/**
 * valeur max entre deux entiers
 * @param a premier entier à comparer
 * @param b second entier à comparer
 * @return renvoie la plus grande valeur entre les deux entiers
 */
int max(int a, int b){
    if(a > b){
        return a;
    }
    return b;
}

/**
 * Calcule récursivement la hauteur d'un sous arbre
 * @param n racine du sous arbre
 * @param acc accumulateur stockant la hauteur déjà calculée
 * @return renvoie la hauteur d'un noeud dans un arbre
 */
int hauteurNoeud(noeud *n, int acc){
    if(isLeaf(n)){
        return 1 + acc;
    }
    if(n->fils_gauche != NULL && n->fils_droit != NULL){
        return max(hauteurNoeud(n->fils_gauche, acc + 1), hauteurNoeud(n->fils_droit, acc + 1));
    }
    if(n->fils_droit != NULL){
        return hauteurNoeud(n->fils_droit, acc + 1);
    }
    if(n->fils_gauche != NULL){
        return hauteurNoeud(n->fils_gauche, acc + 1);
    }
}

/**
 * Calcule la hauteur d'un arbre
 * @param a arbre dont on veut calculer la hauteur
 * @return renvoie la hauteur de l'arbre
 */
int hauteurArbre(arbre_cartesien *a){
    if(a->racine == NULL){
        return 0;
    }
    return hauteurNoeud(a->racine, 0);
}

/**
 * Calcule le nombre de noeud dans un sous arbre
 * @param n noeud racine du sous arbre
 * @return renvoie la taille d'un sous arbre
 */
int nbNoeuds(noeud *n){
    if(isLeaf(n)){
        return 1;
    }
    if(n->fils_droit != NULL && n->fils_gauche != NULL){
        return 1 + nbNoeuds(n->fils_droit) + nbNoeuds(n->fils_gauche);
    }
    if(n->fils_droit != NULL){
        return 1 + nbNoeuds(n->fils_droit);
    }
    if(n->fils_gauche != NULL){
        return 1 + nbNoeuds(n->fils_gauche);
    }
}


/**
 * Calcule la taille d'un arbre
 * @param a arbre dont on veut calculer la taille
 * @return renvoie la taille d'un arbre
 */
int tailleArbre(arbre_cartesien *a){
    if(a->racine == NULL){
        return 0;
    }
    return nbNoeuds(a->racine);
}

/**
 * Vérifie que deux arbre sont identiques
 * @param a1 premier arbre à comparer
 * @param a2 second arbre à comparer
 * @return true si les deux arbres sont identiques
 */
bool equalsArbre(arbre_cartesien *a1, arbre_cartesien *a2){
    if(a1->racine == NULL && a2->racine == NULL){
        return true;
    }
    else if((a1->racine != NULL && a2->racine == NULL) || (a1->racine == NULL && a2->racine != NULL)){
        return false;
    }
    else{
        return equalsNoeud(a1->racine, a2->racine);
    }
}

/**
 * vérifie que deux noeuds et leurs descendants sont identiques
 * @param n1 premier noeud à comparer
 * @param n2 second noeud à comparer
 * @return renvoie true si les noeuds et leurs descendants sont identiques, false sinon
 */
bool equalsNoeud(noeud *n1, noeud *n2){
    if(n1 == NULL && n2 == NULL){
        return true;
    }
    if((n1 == NULL && n2 != NULL) || (n1 != NULL && n2 == NULL)){
        return false;
    }
    if(n1->clef != n2->clef || n1->priorite != n2->priorite){
        return false;
    }
    return equalsNoeud(n1->fils_gauche, n2->fils_gauche) && equalsNoeud(n1->fils_droit, n2->fils_droit);
}

/**
 * Libère un arbre de la mémoire
 * @param a arbre à libérer de la mémoire
 */
void destroy_arbre(arbre_cartesien *a){
    if(a->racine != NULL){
        destroy_noeud(a->racine);
    }
    free(a);
}
