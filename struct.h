#ifndef STRUCT_H
#define STRUCT_H
#include <stdbool.h>
#include <stdint.h>

struct noeud{
    uint32_t clef;                    // Clef du noeud 
    double priorite;                 // Priorité du noeud
    struct noeud *pere;           // Père du noeud
    struct noeud *fils_gauche;    // Pointeur vers le fils gauche
    struct noeud *fils_droit;     // Pointeur vers le fils droit
};

struct arbre_cartesien{
    struct noeud *racine;         // Racine de l'arbre
};

typedef struct noeud noeud;
typedef struct arbre_cartesien arbre_cartesien;

extern noeud *creer_feuille(uint32_t, double);
extern noeud *creer_noeud(char, int, noeud *, noeud *, noeud *);
extern bool is_leaf(noeud *);
extern noeud *get_fils_droit(noeud *);
extern noeud *get_fils_gauche(noeud *);
extern void destroy_noeud(noeud *);
extern arbre_cartesien *creer_arbre_vide();
bool isEmpty(arbre_cartesien *);
extern noeud *recherche(arbre_cartesien *, uint32_t);
extern bool insertion(arbre_cartesien *, noeud *);
extern void rotations(arbre_cartesien *, noeud *);
extern void rotation_droite(arbre_cartesien *, noeud *, noeud *);
extern void rotation_gauche(arbre_cartesien *, noeud *, noeud *);
extern bool suppression(arbre_cartesien *, uint32_t);
extern int tailleArbre(arbre_cartesien *);
extern int hauteurArbre(arbre_cartesien *);
extern bool equalsArbre(arbre_cartesien *, arbre_cartesien *);
extern bool equalsNoeud(noeud *, noeud *);
extern void affiche(noeud *);
extern void destroy_arbre(arbre_cartesien *);



#endif