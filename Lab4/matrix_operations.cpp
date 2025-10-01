#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "matrix_operations.h"

void column_averages(int** matrix, int n, double* averages) {
    for (int col = 0; col < n; col++) {
        int sum = 0;
        for (int row = 0; row < n; row++) {
            sum += matrix[row][col];
        }
        averages[col] = (double)sum / n;
    }
}

void min_max_shaded_area(int** matrix, int n, int* min_abs, int* max_abs) {
    *min_abs = abs(matrix[0][0]);
    *max_abs = abs(matrix[0][0]);

    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            int current_abs = abs(matrix[i][j]);
            if (current_abs < *min_abs) {
                *min_abs = current_abs;
            }
            if (current_abs > *max_abs) {
                *max_abs = current_abs;
            }
        }
    }
}

int** create_matrix(int n) {
    int** matrix = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        matrix[i] = (int*)malloc(n * sizeof(int));
    }
    return matrix;
}

void free_matrix(int** matrix, int n) {
    for (int i = 0; i < n; i++) {
        free(matrix[i]);
    }
    free(matrix);
}