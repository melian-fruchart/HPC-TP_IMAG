#include <mpi.h>
#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

int matrix_size = 500;

#include "utils.c"

void matrix_multiply(double **mat1, double **mat2, double **res, int myrank, int nb_ranks, char *processor_name) {
    printf("Process %d of %d on %s (size : %d)\n", myrank, nb_ranks, processor_name, matrix_size);

    #pragma omp parallel
    {
        int id = omp_get_thread_num();            // Obtenir l'ID du thread
        int num_threads = omp_get_num_threads();  // Obtenir le nombre total de threads
        printf("MPI (%d) -- Thread %d/%d\n",myrank, id+1, num_threads);
    }
    int start = myrank * (matrix_size / 2);
    int end = start + (matrix_size / 2);

    #pragma omp parallel for collapse(2)
    for (int i = start; i < end; i++) {
        for (int k = 0; k < matrix_size; k++) {
            for (int j = 0; j < matrix_size; j++) {
                res[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
}

int main(int argc, char const *argv[]) {
    /* The matrix size can be passed as an argument */
    if (argc > 1) {
        matrix_size = atoi(argv[1]);
    }

    int nb_ranks, myrank, name_len;
    char processor_name[MPI_MAX_PROCESSOR_NAME];
    MPI_Status status;

    MPI_Init(NULL, NULL);
    MPI_Comm_size(MPI_COMM_WORLD, &nb_ranks);
    MPI_Comm_rank(MPI_COMM_WORLD, &myrank);
    MPI_Get_processor_name(processor_name, &name_len);

    assert(nb_ranks % 2 == 0);
    assert(matrix_size % 2 == 0);

    double **mat1 = (double **)malloc(sizeof(double *) * matrix_size);
    double **mat2 = (double **)malloc(sizeof(double *) * matrix_size);
    double **res = (double **)malloc(sizeof(double *) * matrix_size);

    for (int i = 0; i < matrix_size; i++) {
        mat1[i] = (double *)calloc(matrix_size, sizeof(double));
        mat2[i] = (double *)calloc(matrix_size, sizeof(double));
        res[i] = (double *)calloc(matrix_size, sizeof(double));
    }

    initialize_matrices(mat1, mat2);

    TIC();
    matrix_multiply(mat1, mat2, res, myrank, nb_ranks, processor_name);

    int start = myrank * (matrix_size / 2);
    int end = start + (matrix_size / 2);

    // Communication        
    if (myrank != 0) {
        for (int i = start; i < end; i++) {
            MPI_Send(res[i], matrix_size, MPI_DOUBLE, 0, 0, MPI_COMM_WORLD);
        }
    }
    if (myrank == 0) {
        for (int i = matrix_size / 2; i < matrix_size; i++) {
            MPI_Recv(res[i], matrix_size, MPI_DOUBLE, 1, 0, MPI_COMM_WORLD, &status);
        }
    }
    TOC();

    if (myrank == 0) {
        printf("\n%s: finished in %.3lfs\n", __FILE__, TICTOC_SECONDS);
        fprintf(stdout, "%s: checking result...", __FILE__);
        fflush(stdout);
        check_matrix(res);
        printf("done...\n");
    }


    MPI_Finalize();
    return 0;
}
