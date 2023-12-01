# Sequential exécution
Dans cette première étape nous étudions une implémentation naive d'un programme de multiplication de matrices. Nous étudions ensuite comment une petite modification du programme original peut améliorer les perforamnces.

### **1. Compiler les programmes prog1_naive et prog2_optimized**

```make```

### **2. Lire et exécuter l'implémentation originale dans [prog1_naive.c](./prog1_naive.c)**


Ce code C implémente un programme qui multiplie deux matrices carrés. Si un argument est fourni lors de l'exécution, il définit la taille des matrices (par defaut 500x500 éléments). 

Le programme alloue dynamiquement de la mémoire (`malloc`) pour deux matrices d'entrée et une matrice de résultat, toutes de taille spécifiée. Chaque élément des matrices d'entrée mat1 et mat2 sont initialisé par la fonction `initialize_matrices`, la matrice résultat est initialisé à zéro (`calloc`).

Ensuite, le programme effectue la multiplication de ces matrices et mesure le temps pris pour cette opération. Les méthodes `TIC` et `TOC` permettent de mesurer le temps d'exécution entre leurs deux appels (en seconde).
Finalement, il affiche la durée de cette opération (`TICTOC_SECONDS`) avant de se terminer. 

Note : Le code pour la vérification du résultat est commentée et sera utilisé dans la suite du TP.

Pour exécuter le programme :
```
./prog1_naive [optionnal SIZE]
```



# Scaling analysis

 A l'aide du script [scaling_naive.sh](./scaling_naive.sh), étudiez l'évolution de la performance du programme pour des tailles de matrices de plus en plus grande :
 ```
./scaling_naive.sh
```

 - Comment expliqué vous l'évolution du temps d'exécution en fonction de la taille des matrices. 
 
 - Étudiez la complexité calculatoire de l'algorithme utilisé ainsi que son empreinte mémoire.
 
 - Prédire le temps d'exécution de matrices de 2000x2000 éléments ainsi que l'empreinte mémoire de ce programme.

 Vous pouvez vérifier le temps d'exécution en utilisant la commande suivante :
 `./prog1_naive 2000`

 Vous pouvez vérifier l'empreinte mémoire d'un programme avec la commande `top` ou `htop` (colonne RES exprimée en KiB).

- Quelle doit être la taille maximum du problème pour que le calculs prenne moins de 60 secondes.


# Optimized version
Lire et exécuter l'implémentation optimisée dans [prog2_optimized.c](./prog2_optimized.c)

- Comparer la vitesse d'exécution avec la première version
```
./prog1_naive 
./prog2_optimized
```

- Identifier la différence entre ces deux programmes
- Comment expliquez vous cette différence de performance ?
(indice : [Locality and Caching](https://www.cs.utexas.edu/users/fussell/courses/cs429h/lectures/Lecture_18-429h.pdf))
- A l'aide du script [scaling_both.sh](./scaling_both.sh) étudiez l'évolution du temps des deux programmes. 








