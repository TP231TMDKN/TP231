#include <stdio.h>
#include <stdlib.h>
#include "del_occurence_liste.c"
#include "Liste_doublement_chaine_circulaire.c"
#include "liste_doublement_chaine_trie.c"
#include "liste_simplement_chainee_circulaire.c"
#include "liste_simplement_chaine_trie.c"

void menuTache2();
void menuTache3();
void menuTache4();
void menuTache5();
void appel();

int main() {
    int choix;

    printf("Exercice INF 231 du jeudi 25 septembre 2025\n");
    printf("Implementation des operations sur les listes chainees\n\n");

    do {
        printf("==== MENU PRINCIPAL ====\n");
        printf("1. Liste doublement chainee circulaire\n");
        printf("2. Tache 2: Insertion liste simplement chainee triee\n");
        printf("3. Tache 3: Insertion liste doublement chainee triee\n");
        printf("4. Tache 4: Liste simplement chainee circulaire\n");
        printf("5. Tache 5: Liste doublement chainee circulaire\n");
        printf("0. Quitter\n");
        printf("Choix: ");
        scanf("%d", &choix);

        switch(choix) {
            case 1:
                appel();
                break;
            case 2:
                menuTache2();
                break;
            case 3:
                menuTache3();
                break;
            case 4:
                menuTache4();
                break;
            case 5:
                menuTache5();
                break;
            case 0:
                printf("Au revoir!\n");
                break;
            default:
                printf("Choix invalide!\n");
        }
    } while(choix != 0);

    return 0;
}