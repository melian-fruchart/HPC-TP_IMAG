# STEP 5 - compare

Le script [./compare.sh](./compare.sh) exécute les différente versions du code de multiplication de matrices vu dans les étapes précédente.

### Configuration
```
MATRICE_SIZE: Taille des matrices à multiplier.
OMP_NUM_THREADS: Nombre de threads utilisés pour OpenMP.
```

### Execution
* vérifiez bien que toutes les versions des binaires sont existantes. (si vous avez utilisé `make clean` dans un dossier, vous devez y retourner pour le compiler)*



Pour exécuter le script de test et afficher les performances de chaque version du programme, utilisez la commande suivante dans le terminal :
```
./compare.sh
```

Le script run_tests.sh exécute chaque version du programme avec la taille de matrice spécifiée et affiche les résultats sous forme de tableau, y compris le type de programme, le nombre de threads, le nombre de serveurs et le temps d'exécution.

# Bilan
- Pour une multiplication de matrices de 1500x1500, quels ont été les facteurs d'accélération entre les différentes "améliorations" du programme (naive, optimized, OpenMP, MPI, OpenMP + MPI) ?

Vous pouvez pour cela utiliser le script `compare.sh`, en mettant la taille de la matrice à 1500 et non 500.

- Quel a été le facteur d'accélération total ?
