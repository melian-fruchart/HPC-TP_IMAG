# Parallelized execution
Dans cette deuxième étape, nous étudions la parallélisation du programme de multiplication de matrice vu précédemment.
Pour cela nous utiliserons le modèle de programmation OpenMP. 

OpenMP (Open Multi-Processing) est une API (Application Programming Interface) pour la programmation parallèle en mémoire partagée. Elle est principalement utilisée pour améliorer les performances des programmes en exploitant la puissance des architectures de processeurs multi-cœurs. 

### **Avant de commencer**

OpenMP est réputé pour sa facilité d'utilisation, permettant aux développeurs d'intégrer efficacement le parallélisme dans leurs applications avec des directives pré-compilateur simples et des modifications minimales du code source.
Pour appréhender le concept, utilisez le fichier [openmp_hello.c](./openmp_hello.c) et compilez le avec la commande suivante:
```
gcc -fopenmp openmp_hello.c -o openmp_hello
./openmp_hello
```

- Recherchez ce que fait la variable d'environnement `OMP_NUM_THREADS` ([Variables d'environnement](https://gcc.gnu.org/onlinedocs/libgomp/Environment-Variables.html))
- Exécutez quelques fois le programme après avoir défini des nombres de threads différents (`export OMP_NUM_THREADS=3`).

### **1. Compiler les programmes prog1_naive et prog2_optimized**

Dans le répertoire `step2-parallelized/` :

```make```

Le programme `prog1_naive` n'est pas à exécuter immédiatement mais nous servira par la suite.

### **2. Lire et expérimenter avec l'implémentation parallélisée dans [prog2_optimized.c](./prog2_optimized.c)**

- Comprendre la syntaxe permettant de paralléliser des boucles for.
- ÈTudiez différentes exécution avec un nombre dde threads différent

```bash
export OMP_NUM_THREADS=n
./prog2_optimized
```

# OpenMP scaling


- Selon vous, quel est le meilleur nombre de threads a utiliser ? (indice: utilisez la commande `lscpu`)


- A l'aide du script [scaling_omp.sh](./scaling_omp.sh), étudiez l'évolution de la performance du programme pour un nombre de threads de plus en plus grand, et une taille de matrice fixée :
```
./scaling_omp.sh
```

- Décrivez l'évolution du temps d'éxecution en fonction du nombre de threads et expliquez le comportement de la performance.
- De quel facteur le programme est il accéléré ?