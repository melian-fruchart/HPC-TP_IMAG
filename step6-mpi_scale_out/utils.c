#include <stdlib.h>
#include <assert.h>
#include <sys/time.h>
#include <time.h>

int initialize_matrices_step1(double **mat1, double **mat2)
{
    for (int i = 0; i < N; i++)
    {
        mat1[i][i] = 1;
        for (int j = 0; j < N; j++)
        {
            mat2[i][j] = i * N + j + 1;
        }
    }

    return EXIT_SUCCESS;
}

int check_matrix(double **mat)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
	  assert(mat[i][j] == i * N + j + 1);
        }
    }
    return EXIT_SUCCESS;
}

#define BILLION 1000000000.0

/**
 * @brief The start and stop times used by TIC and TOC macros.
 */
struct timespec t_start, t_stop;

/**
 * @brief Get a start time for a time measurement.
 * Uses clock_gettime with CLOCK_MONOTONIC.
 * Should be used with TOC().
 */
#define TIC() clock_gettime(CLOCK_MONOTONIC, &t_start)

/**
 * @brief Get a stop time for a time measurement.
 * Uses clock_gettime with CLOCK_MONOTONIC.
 * Should be used with TIC().
 */
#define TOC() clock_gettime(CLOCK_MONOTONIC, &t_stop)

/**
 * @brief Get the time measurement between TIC and TOC, in seconds.
 * @returns double
 */
#define TICTOC_SECONDS (double)(t_stop.tv_sec - t_start.tv_sec) + (double)(t_stop.tv_nsec - t_start.tv_nsec) / BILLION
