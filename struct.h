#ifndef STRUCT_H
#define STRUCT_H
#include<stdbool.h>

struct noeud{
    char clef;                    // Clef du noeud 
    int priorite;                 // Priorité du noeud
    struct noeud *pere;           // Père du noeud
    struct noeud *fils_gauche;    // Pointeur vers le fils gauche
    struct noeud *fils_droit;     // Pointeur vers le fils droit
};

struct arbre_cartesien{
    struct noeud *racine;         // Racine de l'arbre
};

typedef struct noeud noeud;
typedef struct arbre_cartesien arbre_cartesien;

extern noeud *creer_racine(char, int);
extern noeud *creer_feuille(char, int);
// extern noeud *creer_noeud(char, int, noeud *, noeud *, noeud *);
extern bool is_leaf(noeud *);
extern void destroy_noeud(noeud *);
extern arbre_cartesien *creer_arbre_vide();
extern noeud *recherche(arbre_cartesien *, noeud *);
extern bool insertion(arbre_cartesien *, noeud *);
extern void rotations(noeud *);
extern void rotation_droite(noeud *, noeud *);
extern void rotation_gauche(noeud *, noeud *);
extern bool suppression(arbre_cartesien *, noeud *);
extern void destroy_arbre(arbre_cartesien *);



#endif