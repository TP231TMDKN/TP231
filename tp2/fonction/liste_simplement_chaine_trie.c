#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

void afficher_liste(Node* head) {
    Node* current = head;
    while(current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

Node* inserer_tri(Node* head, int value) {
    Node* newNode = createNode(value);
    if (head == NULL || value < head->data) {
        newNode->next = head;
        return newNode;
    }
    Node* current = head;
    while (current->next != NULL && current->next->data < value)
        current = current->next;
    newNode->next = current->next;
    current->next = newNode;
    return head;
}

void menu_main() {
    Node* head = NULL;
    int choix, val;

    do {
        printf("\n===== MENU =====\n");
        printf("1. Inserer dans la liste simple triee\n");
        printf("2. Afficher la liste simple\n");
        printf("0. Quitter\n");
        printf("Votre choix : ");
        scanf("%d", &choix);

        switch (choix) {
        case 1:
            printf("Valeur a inserer : ");
            scanf("%d", &val);
            head = inserer_tri(head, val);
            break;

        case 2:
            afficher_liste(head);
            break;

        case 0:
            printf("Fin du programme.\n");
            break;

        default:
            printf("Choix invalide.\n");
        }
    } while (choix != 0);
}