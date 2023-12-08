# Multiserver execution
Dans cette troisième étape, nous étudions la parallélisation du programme sur deux machines. Pour cela, nous utiliserons OpenMPI.

OpenMPI est une implémentation open-source de MPI (*Message Passing Interface*), un standard pour la programmation parallèle sur des systèmes distribués ou à mémoire distribuée.
OpenMPI facilite le développement d'applications parallèles en fournissant des fonctionnalités pour la communication et la coordination entre les processus s'exécutant simultanément sur un cluster de machines.

### **Lire et exécuter l'implémentation MPI [prog2_optimized_mpi.c](./prog2_optimized_mpi.c)**

- Après avoir compris ce que fait le programme, exécutez le avec :
```
make parallel_run
```
Cette commande se charge de compiler le programme, d'envoyer une copie du binaire sur la deuxième machine (via le script `ship_binary.sh`), puis de lancer l'exécution. 
Chaque machine effectue alors une partie de la multiplication de matrices, puis le résultat final est obtenu en fusionnant les deux parties. 

- Selon vous, combien de temps prendra l'exécution de ce programme avec une matrice de 1500x1500 ? 

Pour passer la taille de matrice en paramètre au programme exécuté, il faut modifier la ligne de commmande de la target `parallel_run` dans le makefile, tel que montré ci-dessous :
```makefile
parallel_run: prog2_optimized_mpi copy_binary
	$(MPIRUN) -np 2 --host $(THIS_SERVER),$(PEER_SERVER) ./prog2_optimized_mpi [taille matrice]
```

- Modifiez le Makefile et vérifiez le temps d'exécution du programme pour une matrice de 1500x1500.