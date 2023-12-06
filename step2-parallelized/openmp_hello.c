#include <stdio.h>
#include <omp.h>

int main() {
    // Définir le nombre de threads à utiliser
    omp_set_num_threads(4);

    // La directive 'parallel' lance les threads
    #pragma omp parallel
    {
        int id = omp_get_thread_num(); // Obtenir l'ID du thread
        int num_threads = omp_get_num_threads(); // Obtenir le nombre total de threads

        // Début de la zone critique
        #pragma omp critical
        {
            printf("Thread %d sur un total de %d threads\n", id, num_threads);
            printf("Hello World from thread %d\n", id);
        }
        // Fin de la zone critique
    }

    return 0;
}
