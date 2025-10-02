#include <stdio.h>
#include <stdlib.h>
//Definition d'un noeud de la liste
typedef struct Noeud
{
    int data;
    struct Noeud *front;
    struct Noeud *back;
}node;

//______Definition d'une liste_____
typedef struct 
{
    int size;
    node *head;
}list;
//_____Creer un nouveau noeud_____
node *create_node(int data)
{
    node *new_node = (node*)malloc(sizeof(node));
    if (new_node == NULL)
    {
        printf("Erreur : Probleme d'allocation .\n");
        exit(1);
    }
    new_node->data = data;
    new_node->front = NULL;
    new_node->back = NULL;
    return new_node;
}
//______Fonction d'initialisation de la liste______
void initlist(list *li)
{
    li->head = NULL;
    li->size = 0;
}
//______Insertion en tête______ 
void insert_head(list* li, int data)
{
    node* new_node = create_node(data);

    if (li->head == NULL)
    {
        //liste vide
        new_node->back = new_node;
        new_node->front = new_node;
        li->head = new_node;
    }else
    {
        node* last = li->head->front; //celui qui precede la liste d'en tete c'est le dernier element.
        new_node->back = li->head;
        new_node->front = last;
        li->head->front = new_node;
        last->back = new_node;

        li->head = new_node;
    }
    li->size++;
    printf("Elément [%d] inséré en tête.\n", data);    
}
//______Insertion en Queue______

void insert_tail(list* li, int data)
{
    node* new_node = create_node(data);

    if (li->head == NULL)
    {
        //liste vide
        new_node->back = new_node;
        new_node->front = new_node;
        li->head = new_node;
    }else
    {
        node* last = li->head->front;
        last->back = new_node;
        new_node->front = last;
        new_node->back = li->head;
        li->head->front = new_node;

        li->head = new_node;
    }
    li->size++;
    printf("Elément [%d] inséré en queue.\n", data);    
}
//______Fonction d'affichage de la liste dans l'ordre_____

void display_list(list* li)
{
    if (li->head == NULL)
    {
        printf("La liste est vide.\n");
        return;
    }
    
    printf("La liste entrée est : ");
    node* current = li->head;

    do
    {
        printf("[%d] ",current->data);
        current = current->back;
    } while (current != li->head);
    printf("\n");
}
//______Fonction d'affichage de la liste dans l'ordre inverse_____
void display_Backside_list(list* li)
{
    if (li->head == NULL)
    {
        printf("La liste est vide.\n");
        return;
    }
    
    printf("La liste inversée est : ");
    node* last = li->head->front;
    node* current = last;

    do
    {
        printf("[%d] ",current->data);
        current = current->front;
    } while (current != last);
    printf("\n");
}
//_____Liberer la memoire______

void free_list(list* li)
{
    if (li->head == NULL)
    {
        return;
    }
    
    node* current = li->head;
    node* nextNode;

    do
    {
        nextNode = current->back;
        free(current);
        current = nextNode;
    } while (current != li->head);
    
}
//-------------FIN DES FONCTIONS--------------

int main()
{
    list liste;
    initlist(&liste);

    int choice, data;

    printf("====== Gestion d'une liste Doublement chainée Circulaire ======");

    do
    {
        printf("\nMenu 👨‍💼:\n");
        printf("1. Insérer en tête 👈\n");
        printf("2. Insérer en queue 👈\n");
        printf("3. Afficher votre liste dans l'ordre 👈\n");
        printf("4. Afficher votre liste dans l'ordre inverse 👈\n");
        printf("5. Taille de la liste 👈\n");
        printf("6. Quitter 👈\n");
        printf("Choix: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Entrer la valeur a inserer a l'en-tête 👉 ");
                scanf("%d", &data);
                insert_head(&liste, data);
                break;
            case 2:
                printf("Entrer la valeur a inserer en queue 👉 ");
                scanf("%d", &data);
                insert_tail(&liste, data);
                break;
            case 3:
                display_list(&liste);
                break;
            case 4:
                display_Backside_list(&liste);
                break;
            case 5:
                printf("Taille de la liste : %d\n", liste.size);
                break;
            case 6:
                printf("Au revoir!🖐️\n");
                break;
                break;
            default:
                printf("Choix invalide!❌\n");
        }
    } while (choice != 6);
    
    return 0;
}
