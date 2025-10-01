#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "matrix_operations.h"

int main() {
    setlocale(LC_ALL, "Russian");
    int n;

    printf("Введите размер матрицы N: ");
    scanf_s("%d", &n);

    int** matrix = create_matrix(n);

    printf("Введите элементы матрицы %dx%d:\n", n, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("matrix[%d][%d] = ", i, j);
            scanf_s("%d", &matrix[i][j]);
        }
    }

    printf("\nВведенная матрица:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%4d", matrix[i][j]);
        }
        printf("\n");
    }

    double* averages = (double*)malloc(n * sizeof(double));
    column_averages(matrix, n, averages);

    printf("\nСредние арифметические столбцов:\n");
    for (int i = 0; i < n; i++) {
        printf("Столбец %d: %.2f\n", i, averages[i]);
    }

    int min_abs, max_abs;
    min_max_shaded_area(matrix, n, &min_abs, &max_abs);

    printf("\nЗаштрихованная область (элементы выше главной диагонали):\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (j >= i) {
                printf("%4d", matrix[i][j]);
            }
            else {
                printf("    ");
            }
        }
        printf("\n");
    }

    printf("\nМинимальный по модулю элемент в заштрихованной области: %d\n", min_abs);
    printf("Максимальный по модулю элемент в заштрихованной области: %d\n", max_abs);

    free(averages);
    free_matrix(matrix, n);

    return 0;
}