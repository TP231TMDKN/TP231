#include <stdio.h>
#include <stdlib.h>

typedef struct dlist {
    int val;
    struct dlist *suiv;
    struct dlist *prev;
} dlist;

dlist *creerDNoed(int v) {
    dlist *noed = (dlist*)malloc(sizeof(dlist));
    noed->val = v;
    noed->suiv = NULL;
    noed->prev = NULL;
    return noed;
}

dlist* insertSortD(dlist *l, int v) {
    dlist *noed = creerDNoed(v);
    if (l == NULL || v < l->val) {
        noed->suiv = l;
        if (l != NULL) l->prev = noed;
        return noed;
    }
    dlist *p = l;
    while (p->suiv != NULL && p->suiv->val < v)
        p = p->suiv;
    noed->suiv = p->suiv;
    if (p->suiv != NULL) p->suiv->prev = noed;
    p->suiv = noed;
    noed->prev = p;
    return l;
}

void afficherDList(dlist *l) {
    printf("Liste double : ");
    while (l != NULL) {
        printf("%d <-> ", l->val);
        l = l->suiv;
    }
    printf("NULL\n");
}

void menu() {
    dlist *DL = NULL;
    int choix, val;

    do {
        printf("\n===== MENU =====\n");
        printf("1. Inserer dans la liste double triee\n");
        printf("2. Afficher la liste double\n");
        printf("0. Quitter\n");
        printf("Votre choix : ");
        scanf("%d", &choix);

        switch (choix) {
        case 1:
            printf("Valeur a inserer : ");
            scanf("%d", &val);
            DL = insertSortD(DL, val);
            break;

        case 2:
            afficherDList(DL);
            break;

        case 0:
            printf("Fin du programme.\n");
            break;

        default:
            printf("Choix invalide.\n");
        }
    } while (choix != 0);
}