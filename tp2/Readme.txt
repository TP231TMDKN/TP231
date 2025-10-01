

- main.c      : contient le code source complet en C.
- README.txt  : ce fichier explicatif.


  *Compilation
ouvrir un terminal dans le dossier contenant main.c puis exécuter :

    gcc main.c -o prog

Cela crée un exécutable nommé `prog`.

  *Exécution

Lancer le programme avec :

    ./prog

Le programme demandera :
- Combien d’éléments insérer dans la liste.
- Les valeurs des éléments un par un.
- Puis la valeur à supprimer (toutes ses occurrences).



   *Remarques

- La fonction `insererDebut` ajoute les éléments en tête de liste.
     Donc l’ordre d’insertion est inversé à l’affichage.
- La fonction `supprimerOccurences` parcourt la liste et supprime
  toutes les cellules contenant la valeur recherchée.
- Une amélioration possible serait d’ajouter une fonction
  `freeListe` pour libérer toute la mémoire à la fin du programme.