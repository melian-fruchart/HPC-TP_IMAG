# Parallelized execution
Dans cette deuxième étape, nous étudions la parallélisation des programmes de la première étape à l'aide de l'API OpenMP.

### **Avant de commencer**

Cette API est très simple à utiliser de manière basique, et où une syntaxe plus avancée permet d'apporter une puissance supplémentaire.


https://learn.microsoft.com/fr-fr/cpp/parallel/openmp/4-environment-variables?view=msvc-170

Recherchez ce que fait la variable d'environnement `OMP_NUM_THREADS` (et comment s'en servir) et trouvez la syntaxe permettant de paralléliser des boucles for.


### **1. Compiler les programmes prog1_naive et prog2_optimized**
Dans le répertoire `step2-parallelized/` :

```make```

Le programme `prog1_naive` n'est pas à exécuter immédiatement mais nous servira par la suite.

### **2. Lire et expérimenter avec l'implémentation parallélisée dans [prog2_optimized.c](./prog2_optimized.c)**

Le nombre de threads peut être changé via :  
```export OMP_NUM_THREADS=n``` (où n est le nombre de threads)

- Exécutez quelques fois le programme après avoir défini des nombres de threads différents.

```bash
export OMP_NUM_THREADS=n
./prog2_optimized
```

# OpenMP scaling

A l'aide du script [scaling_omp.sh](./scaling_omp.sh), étudiez l'évolution de la performance du programme pour un nombre de threads de plus en plus grand, et des tailles de matrice fixées :
```
./scaling_omp.sh
```

- Décrivez l'évolution du temps d'éxecution en fonction du nombre de threads.

- Selon vous, quel est le meilleur nombre de threads a utiliser, et pourquoi ?

# Performance comparison

```
./prog2_optimized [optionnal THREADS]
```