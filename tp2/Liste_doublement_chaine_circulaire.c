#include <stdio.h>
#include <stdlib.h>

typedef struct Noeud
{
    int data;
    struct Noeud *front;
    struct Noeud *back;
}node;

typedef struct 
{
    int size;
    node *head;
}list;

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

void initlist(list *li)
{
    li->head = NULL;
    li->size = 0;
}

void insert_head(list* li, int data)
{
    node* new_node = create_node(data);

    if (li->head == NULL)
    {
        new_node->back = new_node;
        new_node->front = new_node;
        li->head = new_node;
    }else
    {
        node* last = li->head->front;
        new_node->back = li->head;
        new_node->front = last;
        li->head->front = new_node;
        last->back = new_node;

        li->head = new_node;
    }
    li->size++;
    printf("Element [%d] insere en tete.\n", data);    
}

void insert_tail(list* li, int data)
{
    node* new_node = create_node(data);

    if (li->head == NULL)
    {
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
    printf("Element [%d] insere en queue.\n", data);    
}

void display_list(list* li)
{
    if (li->head == NULL)
    {
        printf("La liste est vide.\n");
        return;
    }
    
    printf("La liste entree est : ");
    node* current = li->head;

    do
    {
        printf("[%d] ",current->data);
        current = current->back;
    } while (current != li->head);
    printf("\n");
}

void display_Backside_list(list* li)
{
    if (li->head == NULL)
    {
        printf("La liste est vide.\n");
        return;
    }
    
    printf("La liste inversee est : ");
    node* last = li->head->front;
    node* current = last;

    do
    {
        printf("[%d] ",current->data);
        current = current->front;
    } while (current != last);
    printf("\n");
}

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

void appel(){
    list liste;
    initlist(&liste);

    int choice, data;

    printf("====== Gestion d'une liste Doublement chainee Circulaire ======");

    do
    {
        printf("\nMenu :\n");
        printf("1. Inserer en tete\n");
        printf("2. Inserer en queue\n");
        printf("3. Afficher votre liste dans l'ordre\n");
        printf("4. Afficher votre liste dans l'ordre inverse\n");
        printf("5. Taille de la liste\n");
        printf("6. Quitter\n");
        printf("Choix: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Entrer la valeur a inserer a l'en-tete : ");
                scanf("%d", &data);
                insert_head(&liste, data);
                break;
            case 2:
                printf("Entrer la valeur a inserer en queue : ");
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
                printf("Au revoir!\n");
                break;
            default:
                printf("Choix invalide!\n");
        }
    } while (choice != 6);
    
}