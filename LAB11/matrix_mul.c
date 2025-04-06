/**
* Lab 11 - CS401/501Spr2025
* Matrix Multiplication using MPI
*
* This program implements parallel matrix multiplication using MPI.
* Each process is assigned a portion of rows from matrix A,
* then calculates the corresponding part of the result matrix C.
*
* Compile: mpicc -o matrix_mul matrix_mul.c
* Run: mpiexec -n <num_processes> ./matrix_mul
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <mpi.h>
#include <time.h>
#define N 4000 // Matrix size (N x N)
// Function to initialize a matrix with random values
void initialize_matrix(double *matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i * cols + j] = (double)rand() / RAND_MAX * 10.0;
        }
    }
}
// Function to print a matrix (for debugging with small matrices)
void print_matrix(double *matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%.2f\t", matrix[i * cols + j]);
        }
        printf("\n");
    }
    printf("\n");
}

void mult_sub(double *A, double *B, double *C, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            C[i * cols + j] = 0.0;
            for(int c = 0; c < cols; c++) {
                C[i * cols + j] += A[i * cols + c] * B[c * cols + j];
            }
        }
    }
}

int main(int argc, char *argv[]) {
    clock_t start, end;
    double cputime;
    int rank, size;
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    int rows_per_proc = N / size;

    double *matrixA = NULL;
    double *matrixB = malloc(N * N * sizeof(double));
    double *matrixC = NULL;

    if (rank == 0) {
        matrixA = malloc(N * N * sizeof(double));
        matrixC = malloc(N * N * sizeof(double));
        initialize_matrix(matrixA, N, N);
        initialize_matrix(matrixB, N, N);
        
        start = clock();
    }

    

    double *A_sub = malloc(rows_per_proc * N * sizeof(double));
    double *C_sub = malloc(rows_per_proc * N * sizeof(double));

    MPI_Scatter(matrixA, rows_per_proc * N, MPI_DOUBLE, A_sub, rows_per_proc * N, MPI_DOUBLE, 0, MPI_COMM_WORLD);

    MPI_Bcast(matrixB, N * N, MPI_DOUBLE, 0, MPI_COMM_WORLD);

    mult_sub(A_sub, matrixB, C_sub, rows_per_proc, N);

    MPI_Gather(C_sub, rows_per_proc * N, MPI_DOUBLE, matrixC, rows_per_proc * N, MPI_DOUBLE, 0, MPI_COMM_WORLD);

    if (rank == 0) {
        end = clock();
        cputime = ((double) (end - start)) / CLOCKS_PER_SEC * 1000;
        printf("Matrix mul done!\n");
        printf("Took %.3f milliseconds\n", cputime);
        if (N <= 10) {
            print_matrix(matrixC, N, N);
        }
        free(matrixA);
        free(matrixC);
    }

    free(A_sub);
    free(C_sub);
    free(matrixB);
    MPI_Finalize();


    return 0;
}