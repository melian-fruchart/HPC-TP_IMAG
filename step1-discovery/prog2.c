#include <stdlib.h>
#include <stdio.h>

#define N 1500

#include "utils.c"

void matrix_multiply(double **mat1, double **mat2, double **res)
{
    for (int i = 0; i < N; i++)
        for (int k = 0; k < N; k++)
            for (int j = 0; j < N; j++)
                res[i][j] += mat1[i][k] * mat2[k][j];
}

int main()
{
    double **mat1 = (double **)malloc(sizeof(double *) * N);
    double **mat2 = (double **)malloc(sizeof(double *) * N);
    double **res = (double **)malloc(sizeof(double *) * N);

    for (int i = 0; i < N; i++)
    {
        mat1[i] = (double *)calloc(N, sizeof(double));
        mat2[i] = (double *)calloc(N, sizeof(double));
        res[i] = (double *)calloc(N, sizeof(double));
    }

    // initialize_matrices_step1(mat1, mat2);

    TIC();
    matrix_multiply(mat1, mat2, res);
    TOC();

    // check_matrix(res);
    printf("\n%s: terminé en %.1lfs\n", __FILE__, TICTOC_SECONDS);
    return 0;
}
