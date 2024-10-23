#ifndef STRUCT_H
#define STRUCT_H
#include<stdbool.h>

struct noeud{
    char clef;                   // Clef du noeud 
    int priorite;                // Priorité du noeud
    struct noeud *pere;          // Pointeur vers le père, lui même pour la racine
    struct noeud *filsGauche;    // Pointeur vers le fils gauche
    struct noeud *filsDroit;     // Pointeur vers le fils droit
};

struct arbreCartesien{
    struct noeud *racine;        // Racine de l'arbre
};

typedef struct noeud noeud;
typedef struct arbreCartesien arbreCartesien;

extern noeud *creer_noeud(char, int, noeud *, noeud *, noeud *);
extern char get_key(noeud *);
extern int get_prio(noeud *);
extern noeud *get_pere(noeud *);
extern noeud *get_fils_gauche(noeud *);
extern noeud *get_fils_droit(noeud *);
extern void set_clef(noeud *, char);
extern void set_prio(noeud *, int);
extern void set_pere(noeud *, noeud *);
extern void set_fils_gauche(noeud *, noeud *);
extern void set_fils_droit(noeud *, noeud *);
extern bool is_leaf(noeud *);
extern void destroy_noeud(noeud *);
extern arbreCartesien *creer_arbre_vide();
extern bool ajoute_arbre(arbreCartesien *, noeud *);
extern bool supprime_arbre(arbreCartesien *, noeud *);
extern bool est_dans_arbre(arbreCartesien *, noeud *);
extern void destroy_arbre(arbreCartesien *);



#endif