Tache 3: Liste doublement chainée avec insertion dans une liste trié

Tructure de ma liste doublement chainée
// Définition de la structure d'une liste doublement chaînée
typedef struct Liste {
    int value;
    struct Liste *prev;
    struct Liste *next;
} Liste;


// Création d'un nouveau noeud
Liste* creer_noeud(int val) {
    Liste* new_noeud = (Liste*)malloc(sizeof(Liste));
    if (!new_noeud) {
        printf("Erreur de création du noeud.\n");
        exit(1);
    }
    new_noeud->value = val;
    new_noeud->prev = NULL;
    new_noeud->next = NULL;
    return new_noeud;
}

// Ajout au début
void ajout_debut(Liste **tete, int val) {
    Liste* nouveau = creer_noeud(val);
    if (*tete != NULL) {
        nouveau->next = *tete;
        (*tete)->prev = nouveau;
    }
    *tete = nouveau;
}

// Ajout à la fin
void ajout_fin(Liste **tete, int val) {
    Liste* nouveau = creer_noeud(val);
    if (*tete == NULL) {
        *tete = nouveau;
        return;
    }
    Liste* tmp = *tete;
    while (tmp->next != NULL) {
        tmp = tmp->next;
    }
    tmp->next = nouveau;
    nouveau->prev = tmp;
}

// Affichage de la liste
void afficher_liste(Liste *tete) {
    Liste* tmp = tete;
    while (tmp != NULL) {
        printf("%d -> ", tmp->value);
        tmp = tmp->next;
    }
    printf("NULL\n");
}

// Tri à bulle (en échangeant les valeurs)
void tri_bulle(Liste *tete) {
    if (tete == NULL) return;

    int permuter;
    Liste *tmp;

    do {
        permuter = 0;
        tmp = tete;

        while (tmp->next != NULL) {
            if (tmp->value > tmp->next->value) {
                // Échange des valeurs
                int temp = tmp->value;
                tmp->value = tmp->next->value;
                tmp->next->value = temp;
                permuter = 1;
            }
            tmp = tmp->next;
        }
    } while (permuter);
}

// Libération de la mémoire
void liberer_liste(Liste **tete) {
    Liste* tmp = *tete;
    while (tmp != NULL) {
        Liste* suivant = tmp->next;
        free(tmp);
        tmp = suivant;
    }
    *tete = NULL;
}

Mon programme permet à l'utilisateur d'inserer n valeurs de son choix, puis il le trie  de maniere croissante grace au trie a bulle, puis grace au fonction inserer en tete et en queu l'utilisateur poura inserer les valeurs de son choix.
Dans le "main" nous avons un Menu qui permettra a l'utilisateur de faire certain tache comme:
1. remplir une liste
2. inserer un element en tete
3. inserer un element en queu
4. affichage de la liste

pour cela j'ai utilisé un jeu de commande qui permet d'entrée dans un choix quelconque ou d'en resortir si l'utilisateur le veux bien.
ce jeu utilise une fonction << do{...}while et la fonction goto>> comme le montre ce bout de code si dessous:

int main(void) {
    int choix, n, val, retour;
    Liste *tete = NULL;

    do { M:
        printf("\n\t=== BIENVENUE DANS MA LISTE DOUBLEMENT CHAINEE ===\n");
        printf("1. Remplir la liste\n");
        printf("2. Ajouter au debut\n");
        printf("3. Ajouter a la fin\n");
        printf("4. Afficher la liste\n");
        printf("0. Quitter\n");
        printf("Faites votre choix : ");
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                i:
                printf("Entrez la taille de la liste : ");
                scanf("%d", &n);
                for (int i = 0; i < n; i++) {
                    printf("Entrez la valeur %d : ", i + 1);
                    scanf("%d", &val);
                    ajout_fin(&tete, val);
                }
                tri_bulle(tete);
                printf("Liste triee avec succes.\n");
                // pour le jeux de fonction de retour

                do {
                    printf("voulez retourner?\n");
                    printf("entre 1 pour Rester & 0 pour retourner: ");
                    scanf("%d", &retour);
                    printf("\n");
                   if (retour == 1) {
                       goto i;
                   }else {
                       goto M;
                   }
                }while (retour ==0 );
                break;

            case 2:
                d:
                printf("Entrez la valeur a ajouter au debut : ");
                scanf("%d", &val);
                ajout_debut(&tete, val);
                printf("Ajout reussi.\n");

                do {
                    printf("voulez retourner?\n");
                    printf("entre 1 pour Rester & 0 pour retourner: ");
                    scanf("%d", &retour);
                    printf("\n");
                    if (retour == 1) {
                        goto d;
                    }else {
                        goto M;
                    }
                }while (retour ==0 );
                break;

            case 3:
                r:
                printf("Entrez la valeur a ajouter à la fin : ");
                scanf("%d", &val);
                ajout_fin(&tete, val);
                printf("Ajout reussi.\n");

                do {
                    printf("voulez retourner?\n");
                    printf("entre 1 pour Rester & 0 pour retourner: ");
                    scanf("%d", &retour);
                    printf("\n");
                    if (retour == 1) {
                        goto r;
                    }else {
                        goto M;
                    }
                }while (retour ==0 );
                break;

            case 4:
                // cest pour un repere
                p:
                printf("Affichage de la liste :\n");
                afficher_liste(tete);

                do {
                    printf("voulez retourner?\n");
                    printf("entre 1 pour Rester & 0 pour retourner: ");
                    scanf("%d", &retour);
                    printf("\n");
                    if (retour == 1) {
                        goto p;
                    }else {
                        goto M;
                    }
                }while (retour ==0 );
                break;
le <<SWITCH>> me permet de facilité la selection des differents choix fais par l'utilisateur que d'utilisé les iterations comme << if...else>>
elle me permet de mettre tout ça de façon ordonnée sans trop d'erreur de syntaxe et facile à lire et a debugger
