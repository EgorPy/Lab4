#ifndef MATRIX_OPERATIONS_H
#define MATRIX_OPERATIONS_H

void column_averages(int** matrix, int n, double* averages);

void min_max_shaded_area(int** matrix, int n, int* min_abs, int* max_abs);

int** create_matrix(int n);

void free_matrix(int** matrix, int n);

#endif
