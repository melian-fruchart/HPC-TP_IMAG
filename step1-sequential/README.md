# Sequential execution
Dans cette première étape nous étudions une implémentation naive d'un programme de multiplication de matrices. Nous étudions ensuite comment une petite modification du programme original peut améliorer les performances.

### **1. Compiler les programmes prog1_naive et prog2_optimized**
Dans le répertoire `step1-sequential/` :

```make```

Le programme `prog2_optimized` n'est pas à exécuter immédiatement mais nous servira par la suite.

### **2. Lire et exécuter l'implémentation originale dans [prog1_naive.c](./prog1_naive.c)**


Ce code C implémente un programme qui multiplie deux matrices carrés. Si un argument est fourni lors de l'exécution, il définit la taille des matrices (par défaut 500x500 éléments).

Le programme alloue dynamiquement de la mémoire (`malloc`) pour deux matrices d'entrée et une matrice de résultat, toutes de taille spécifiée. Les matrices d'entrée mat1 et mat2 sont initialisées par la fonction `initialize_matrices`, et la matrice résultat est initialisée à zéro (`calloc`).

Ensuite, le programme effectue la multiplication de ces matrices et mesure le temps pris pour cette opération. Les méthodes `TIC` et `TOC` permettent de mesurer le temps d'exécution entre leurs deux appels (en secondes).
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

- Décrivez l'évolution du temps d'exécution en fonction de la taille des matrices.

- Étudiez la complexité algorithmique (nombre d'opérations) de l'algorithme utilisé, ainsi que sa complexité spatiale (empreinte mémoire). Est-ce en accord avec l'évolution du temps d'exécution ?

Il est possible de vérifier l'empreinte mémoire d'un programme avec la commande `top` ou `htop` (colonne RES exprimée en KiB) (il vaut mieux vérifier l'empreinte mémoire lors de l'exécution de `prog1_naive`, car les tailles des matrices changent durant l'exécution de `scaling_naive.sh`).

- Prédire le temps d'exécution de matrices de 2000x2000 éléments ainsi que l'empreinte mémoire (sachant que la taille d'un double est de 8 octets).

Vous pouvez vérifier le temps d'exécution en utilisant la commande suivante :
`./prog1_naive 2000`

- Quelle doit être la taille maximale du problème pour que le calcul prenne moins de 60 secondes ?


# Optimized version
Lire et exécuter l'implémentation optimisée dans [prog2_optimized.c](./prog2_optimized.c)

- Comparer la vitesse d'exécution avec la première version
```
./prog1_naive 
./prog2_optimized
```

- Identifier la différence entre ces deux programmes
- Comment expliquez vous cette différence de performance ? **Essayez de formuler des hypothèses, de représenter les multiplications, et n'hésitez pas à nous poser des questions ou nous soumettre des théories.** (Si jamais aucune idée ne vous vient, vous pouvez consulter l'indice : [Locality and Caching](https://www.cs.utexas.edu/users/fussell/courses/cs429h/lectures/Lecture_18-429h.pdf))
- A l'aide du script [scaling_both.sh](./scaling_both.sh), étudiez l'évolution du temps des deux programmes.








