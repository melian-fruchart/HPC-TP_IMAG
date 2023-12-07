#include <stdio.h>
#include <stdlib.h>

int matrix_size = 500;

#include "utils.c"

void matrix_multiply(double **mat1, double **mat2, double **res) {
    for (int i = 0; i < matrix_size; i++)
        for (int j = 0; j < matrix_size; j++)
            for (int k = 0; k < matrix_size; k++)
                res[i][j] += mat1[i][k] * mat2[k][j];
}

int main(int argc, char const *argv[]) {
    /* The matrix size can be passed as an argument */
    if (argc > 1) {
        matrix_size = atoi(argv[1]);
    }

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
    matrix_multiply(mat1, mat2, res);
    TOC();

    // check_matrix(res);
    printf("%s: terminé en %.3lf (size: %d)\n", __FILE__, TICTOC_SECONDS, matrix_size);
    return 0;
}
