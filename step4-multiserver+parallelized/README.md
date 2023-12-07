# Multiserver and parallelized execution
Dans cette dernière étape, nous étudions la parallélisation du programme sur deux machines, et sur 4 threads par machine. Nous allons donc combiner OpenMP et OpenMPI.

### **Avant de commencer**

La commande d'exécution est toujours `make parallel_run`, mais le code de cette commande a été modifié de manière à passer les informations de OpenMP.

Il est toujours possible de passer la taille de matrice en paramètre au programme exécuté :
```makefile
parallel_run: prog2_optimized_mpi copy_binary
	OMP_NUM_THREADS=4 OMP_PROC_BIND=spread OMP_PLACES=cores $(MPIRUN) -np 2 --map-by ppr:1:socket:pe=4 --host $(THIS_SERVER),$(PEER_SERVER) ./prog2_optimized_mpi [taille matrice]
```
Il est aussi possible de modifier le nombre de threads dans le Makefile, en changeant la valeur associée à `OMP_NUM_THREADS` (voir commande ci-dessus).


### **Lire et exécuter l'implémentation OpenMP + MPI [prog2_optimized_mpi_omp.c](./prog2_optimized_mpi_omp.c)**
- Après avoir compris ce que fait le programme, exécutez le avec ```make parallel_run```.
- Selon vous, combien de temps prendra l'exécution de ce programme avec une matrice de 1500x1500 ? 
- Modifiez le Makefile et vérifiez le temps d'exécution du programme pour une matrice de 1500x1500.


# Bilan

- Pour une multiplication de matrices de 1500x1500, quels ont été les facteurs d'accélération entre les différentes "améliorations" du programme (naive, optimized, OpenMP, MPI, OpenMP + MPI) ?
- Quel a été le facteur d'accélération total ?
