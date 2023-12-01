#include <stdlib.h>
#include <stdio.h>

int matrix_size = 800;

#include "utils.c"

void matrix_multiply(double **mat1, double **mat2, double **res)
{
    for (int i = 0; i < matrix_size; i++)
        for (int k = 0; k < matrix_size; k++)
            for (int j = 0; j < matrix_size; j++)
                res[i][j] += mat1[i][k] * mat2[k][j];
}

int main(int argc, char const *argv[])
{
    /* The matrix size can be passed as an argument */
    if (argc > 1)
    {
        matrix_size = atoi(argv[1]);
    }

    double **mat1 = (double **)malloc(sizeof(double *) * matrix_size);
    double **mat2 = (double **)malloc(sizeof(double *) * matrix_size);
    double **res = (double **)malloc(sizeof(double *) * matrix_size);

    for (int i = 0; i < matrix_size; i++)
    {
        mat1[i] = (double *)calloc(matrix_size, sizeof(double));
        mat2[i] = (double *)calloc(matrix_size, sizeof(double));
        res[i] = (double *)calloc(matrix_size, sizeof(double));
    }

    // initialize_matrices_step1(mat1, mat2);

    TIC();
    matrix_multiply(mat1, mat2, res);
    TOC();

    // check_matrix(res);
    printf("%s: terminé en %.1lfs\n", __FILE__, TICTOC_SECONDS);
    return 0;
}
