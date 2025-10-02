     //Gestion d’une Liste Simplement Chaînée triee en C

*Description

Ce projet implémente une liste simplement chaînée triée en langage C.
Il permet :
-d’insérer des éléments de manière triée dans la liste,
-d’afficher les éléments de la liste,
-d’interagir via un menu console simple.

*Fonctionnalités
-Insertion triée : chaque nouvel élément est inséré à sa place pour garder la liste triée en ordre croissant.
-Affichage : la liste est affichée avec les liens (->) jusqu’à NULL.
-Menu interactif : l’utilisateur peut choisir les actions à effectuer.

*Structure du code et explication

-Node : structure représentant un nœud de la liste (valeur + pointeur next).
Chaque nœud contient une valeur entière (data) et un pointeur vers le nœud suivant (next).

-Fonction createNode() : crée un nouveau nœud.
Crée un nouveau nœud avec la valeur donnée et next à NULL.
Retourne un pointeur vers le nouveau nœud.

-Fonction inserer_tri() : insère un élément dans la liste tout en gardant l’ordre trié.
Si la liste est vide ou si la valeur doit être insérée au début, elle devient le nouveau head.
Sinon, parcourt la liste jusqu’au bon emplacement et insère le nouveau nœud pour garder la liste triée.

-afficher_liste() : parcourt et affiche la liste.
Parcourt la liste depuis le head et affiche chaque élément suivi de ->.
Affiche NULL à la fin pour indiquer la fin de la liste.


-menu_main() : affiche le menu principal et gère les choix de l’utilisateur.
Affiche un menu avec trois options : insérer, afficher ou quitter.
Lit le choix de l’utilisateur et appelle la fonction correspondante.
Boucle jusqu’à ce que l’utilisateur choisisse de quitter (0).

*Illustration de la liste chaînée triée
Supposons que la liste contient les éléments suivants :  
5 -> 10 -> 15 -> NULL
Insertion de 12
1. On parcourt la liste pour trouver la bonne position (entre 10 et 15).  
2. On insère le nouveau nœud avec la valeur 12 :
5 -> 10 -> 12 -> 15 -> NULL
   
*Améliorations possibles
-Ajouter la suppression d’un élément.
-Ajouter la recherche d’un élément.
-Libérer la mémoire à la fin du programme (free) pour éviter les fuites.


## Auteur
Galyeu De Honba
23U2707
