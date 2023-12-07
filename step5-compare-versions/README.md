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


