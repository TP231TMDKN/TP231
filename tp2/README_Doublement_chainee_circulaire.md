
           ___________ DESCRIPTION __________

Ce programme implémente une liste doublement chaînée circulaire en langage C. Une liste doublement chaînée circulaire est une structure de données où chaque nœud pointe vers son prédécesseur et son successeur, et où le dernier nœud pointe vers le premier, formant ainsi une boucle.
        ____________Structure de Données___________     
                     	
            ___________NOEUD(NODE)___________

Chaque élément de la liste est représenté par un nœud contenant :

    data : la valeur entière stockée

    front : pointeur vers le nœud précédent

    back : pointeur vers le nœud suivant

          ____________LISTE (LIST)___________
 
La structure principale contient :

    head : pointeur vers le premier élément de la liste

    size : nombre d'éléments dans la liste

       __________🎯 FONCTIONS IMPLEMENTEES________
1. Initialisation

    initlist() : Initialise une liste vide

2. Insertion

    insert_head() : Ajoute un élément au début de la liste

    insert_tail() : Ajoute un élément à la fin de la liste

3. Affichage

    display_list() : Affiche la liste dans l'ordre normal

    display_Backside_list() : Affiche la liste dans l'ordre inverse

4. Gestion Mémoire

    free_list() : Libère toute la mémoire allouée pour la liste

5. Utilitaire

    create_node() : Crée un nouveau nœud avec allocation mémoire

        ____________COMPILATION ET EXECUTION_____________
COMPILATION:

bash

gcc -o liste_circulaire Liste_doublement_chaine_circulaire.c

EXECUTION:
bash

./liste_circulaire

         __________ GESTION 🖥️ET MENU INTERACTIF__________

Menu 👨‍💼:
1. Insérer en tête 👈
2. Insérer en queue 👈
3. Afficher votre liste dans l'ordre 👈
4. Afficher votre liste dans l'ordre inverse 👈
5. Taille de la liste 👈
6. Quitter 👈
Choix: 1
Entrer la valeur a inserer a l'en-tête 👉 10
Elément [10] inséré en tête.

           ________________PETIT RAPPEL________________

---La liste est circulaire : le dernier élément pointe vers le premier

---La liste est doublement chaînée : chaque nœud a des pointeurs avant et arrière

---La mémoire est automatiquement libérée à la fin du programme
