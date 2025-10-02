#include <stdio.h>
#include <stdlib.h>

typedef struct Noued
{
    int val;
    struct Noued *next;
}Noued;

typedef struct Liste
{
    Noued *tete;
}Liste;

Noued* creer_Noued(int val){
    Noued* new = (Noued*)malloc(sizeof(Noued));
    new->val = val;
    new->next = NULL;
    return new;
}

void ajouter(Liste *li, int val ){
    Noued* new = creer_Noued(val);

    if (li->tete == NULL)
    {
        li->tete = new;
        new->next = li->tete;
    }else{
        Noued* last = li->tete;
        while (last->next != li->tete)
        {
            last = last->next;
        }
        last->next = new;
        new->next = li->tete;
        li->tete = new;
    }
}

void ajout_queu(Liste *li, int val){
    Noued* new = creer_Noued(val);
    if (li->tete == NULL)
    {
        li->tete = new;
        new->next = li->tete;
    }else{
        Noued* last = li->tete;
        while (last->next != li->tete)
        {
            last = last->next;
        }
        last->next = new;
        new->next = li->tete;
    }
}

void afficher(Liste *li){
    if (li->tete == NULL)
    {
        printf("liste vide");
    }else{
        Noued* current = li->tete;
        int i = 0;
        do {
            printf("la valeur [%d] est : [%d]", i, current->val);
            printf("\n");
            current = current->next;
            i++;
        } while (current != li->tete);
    }
}