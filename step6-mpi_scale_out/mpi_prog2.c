#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>

#define N 1500

#include "utils.c"

void matrix_multiply(double **mat1, double **mat2, double **res, int myrank, int nb_ranks) {
    for (int i = 0; i < N; i++) {
        if (i % nb_ranks != myrank) continue;
        for (int k = 0; k < N; k++)
            for (int j = 0; j < N; j++)
                res[i][j] += mat1[i][k] * mat2[k][j];
    }
}

int main() {
    int nb_ranks, myrank, name_len;
    char processor_name[MPI_MAX_PROCESSOR_NAME];
    MPI_Status status;

    assert(N % 2 == 0);

    MPI_Init(NULL, NULL);
    MPI_Comm_size(MPI_COMM_WORLD, &nb_ranks);
    MPI_Comm_rank(MPI_COMM_WORLD, &myrank);
    MPI_Get_processor_name(processor_name, &name_len);

    printf("Process %d of %d on %s\n", myrank, nb_ranks, processor_name);

    assert(nb_ranks % 2 == 0);

    double **mat1 = (double **)malloc(sizeof(double *) * N);
    double **mat2 = (double **)malloc(sizeof(double *) * N);
    double **res = (double **)malloc(sizeof(double *) * N);

    for (int i = 0; i < N; i++) {
        mat1[i] = (double *)calloc(N, sizeof(double));
        mat2[i] = (double *)calloc(N, sizeof(double));
        res[i] = (double *)calloc(N, sizeof(double));
    }

    initialize_matrices_step1(mat1, mat2);

    TIC();

    matrix_multiply(mat1, mat2, res, myrank, nb_ranks);

    for (int i = 0; i < N; i++) {
        if (myrank == 0) {
            if (i % nb_ranks != 0) {
                MPI_Recv(res[i], N, MPI_DOUBLE, i % nb_ranks, 0, MPI_COMM_WORLD, &status);
            }
        } else {
            if (i % nb_ranks == myrank) {
                MPI_Send(res[i], N, MPI_DOUBLE, 0, 0, MPI_COMM_WORLD);
            }
        }
    }

    TOC();

    if (myrank == 0) {
        printf("\n%s: finished in %.2lfs\n", __FILE__, TICTOC_SECONDS);
        fprintf(stdout, "%s: checking result...", __FILE__);
        fflush(stdout);
        check_matrix(res);
        printf("done...\n");
    }

    MPI_Finalize();
    return 0;
}
