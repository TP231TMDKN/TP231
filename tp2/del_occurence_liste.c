#include <stdio.h>
#include <stdlib.h>

typedef struct noeud {
    int data;
    struct noeud* next;
} noeud;

typedef struct Dnoeud {
    int data;
    struct Dnoeud* next;
    struct Dnoeud* prev;
} Dnoeud;

noeud* createnoeud(int value) {
    noeud* newnoeud = (noeud*)malloc(sizeof(noeud));
    newnoeud->data = value;
    newnoeud->next = NULL;
    return newnoeud;
}

Dnoeud* createDnoeud(int value) {
    Dnoeud* newnoeud = (Dnoeud*)malloc(sizeof(Dnoeud));
    newnoeud->data = value;
    newnoeud->next = newnoeud->prev = NULL;
    return newnoeud;
}

noeud* insertSorted(noeud* head, int value) {
    noeud* newnoeud = createnoeud(value);
    if (head == NULL || value < head->data) {
        newnoeud->next = head;
        return newnoeud;
    }
    noeud* current = head;
    while (current->next != NULL && current->next->data < value)
        current = current->next;
    newnoeud->next = current->next;
    current->next = newnoeud;
    return head;
}

Dnoeud* insertSortedD(Dnoeud* head, int value) {
    Dnoeud* newnoeud = createDnoeud(value);
    if (head == NULL) return newnoeud;

    if (value < head->data) {
        newnoeud->next = head;
        head->prev = newnoeud;
        return newnoeud;
    }

    Dnoeud* current = head;
    while (current->next != NULL && current->next->data < value)
        current = current->next;

    newnoeud->next = current->next;
    if (current->next != NULL) 
        current->next->prev = newnoeud;
    current->next = newnoeud;
    newnoeud->prev = current;

    return head;
}

noeud* insertHeadCircular(noeud* head, int value) {
    noeud* newnoeud = createnoeud(value);
    if (head == NULL) {
        newnoeud->next = newnoeud;
        return newnoeud;
    }
    noeud* tail = head;
    while (tail->next != head) 
        tail = tail->next;
    newnoeud->next = head;
    tail->next = newnoeud;
    return newnoeud;
}

noeud* insertTailCircular(noeud* head, int value) {
    noeud* newnoeud = createnoeud(value);
    if (head == NULL) {
        newnoeud->next = newnoeud;
        return newnoeud;
    }
    noeud* tail = head;
    while (tail->next != head) 
        tail = tail->next;
    tail->next = newnoeud;
    newnoeud->next = head;
    return head;
}

Dnoeud* insertHeadDCircular(Dnoeud* head, int value) {
    Dnoeud* newnoeud = createDnoeud(value);
    if (head == NULL) {
        newnoeud->next = newnoeud->prev = newnoeud;
        return newnoeud;
    }
    Dnoeud* tail = head->prev;
    newnoeud->next = head;
    newnoeud->prev = tail;
    head->prev = newnoeud;
    tail->next = newnoeud;
    return newnoeud;
}

Dnoeud* insertTailDCircular(Dnoeud* head, int value) {
    Dnoeud* newnoeud = createDnoeud(value);
    if (head == NULL) {
        newnoeud->next = newnoeud->prev = newnoeud;
        return newnoeud;
    }
    Dnoeud* tail = head->prev;
    tail->next = newnoeud;
    newnoeud->prev = tail;
    newnoeud->next = head;
    head->prev = newnoeud;
    return head;
}

void printList(noeud* head) {
    noeud* current = head;
    while(current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

void printDList(Dnoeud* head) {
    Dnoeud* temp = head;
    while(temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void printCircularList(noeud* head) {
    if(head != NULL) {
        noeud* curr = head;
        do {
            printf("%d -> ", curr->data);
            curr = curr->next;
        } while(curr != head);
        printf("(retour tete)\n");
    } else {
        printf("Liste vide\n");
    }
}

void printDCircularList(Dnoeud* head) {
    if(head != NULL) {
        Dnoeud* curr = head;
        Dnoeud* start = head;
        do {
            printf("%d <-> ", curr->data);
            curr = curr->next;
        } while(curr != start);
        printf("(retour tete)\n");
    } else {
        printf("Liste vide\n");
    }
}

void menuTache2() {
    noeud* head = NULL;
    int choix, val;
    
    do {
        printf("\n=== TACHE 2: Insertion dans liste simplement chainee triee ===\n");
        printf("1. Inserer un element\n");
        printf("2. Afficher la liste\n");
        printf("0. Retour au menu principal\n");
        printf("Choix: ");
        scanf("%d", &choix);

        switch(choix) {
            case 1:
                printf("Entrez la valeur a inserer: ");
                scanf("%d", &val);
                head = insertSorted(head, val);
                break;
            case 2:
                printf("Liste triee: ");
                printList(head);
                break;
            case 0:
                break;
            default:
                printf("Choix invalide!\n");
        }
    } while(choix != 0);
}

void menuTache3() {
    Dnoeud* head = NULL;
    int choix, val;
    
    do {
        printf("\n=== TACHE 3: Insertion dans liste doublement chainee triee ===\n");
        printf("1. Inserer un element\n");
        printf("2. Afficher la liste\n");
        printf("0. Retour au menu principal\n");
        printf("Choix: ");
        scanf("%d", &choix);

        switch(choix) {
            case 1:
                printf("Entrez la valeur a inserer: ");
                scanf("%d", &val);
                head = insertSortedD(head, val);
                break;
            case 2:
                printf("Liste double triee: ");
                printDList(head);
                break;
            case 0:
                break;
            default:
                printf("Choix invalide!\n");
        }
    } while(choix != 0);
}

void menuTache4() {
    noeud* head = NULL;
    int choix, val;
    
    do {
        printf("\n=== TACHE 4: Liste simplement chainee circulaire ===\n");
        printf("1. Inserer en tete\n");
        printf("2. Inserer en queue\n");
        printf("3. Afficher la liste\n");
        printf("0. Retour au menu principal\n");
        printf("Choix: ");
        scanf("%d", &choix);

        switch(choix) {
            case 1:
                printf("Entrez la valeur a inserer: ");
                scanf("%d", &val);
                head = insertHeadCircular(head, val);
                break;
            case 2:
                printf("Entrez la valeur a inserer: ");
                scanf("%d", &val);
                head = insertTailCircular(head, val);
                break;
            case 3:
                printf("Liste circulaire simple: ");
                printCircularList(head);
                break;
            case 0:
                break;
            default:
                printf("Choix invalide!\n");
        }
    } while(choix != 0);
}

void menuTache5() {
    Dnoeud* head = NULL;
    int choix, val;
    
    do {
        printf("\n=== TACHE 5: Liste doublement chainee circulaire ===\n");
        printf("1. Inserer en tete\n");
        printf("2. Inserer en queue\n");
        printf("3. Afficher la liste\n");
        printf("0. Retour au menu principal\n");
        printf("Choix: ");
        scanf("%d", &choix);

        switch(choix) {
            case 1:
                printf("Entrez la valeur a inserer: ");
                scanf("%d", &val);
                head = insertHeadDCircular(head, val);
                break;
            case 2:
                printf("Entrez la valeur a inserer: ");
                scanf("%d", &val);
                head = insertTailDCircular(head, val);
                break;
            case 3:
                printf("Liste circulaire double: ");
                printDCircularList(head);
                break;
            case 0:
                break;
            default:
                printf("Choix invalide!\n");
        }
    } while(choix != 0);
}