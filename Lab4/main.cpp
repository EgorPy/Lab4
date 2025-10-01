#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "matrix_operations.h"

int main() {
    setlocale(LC_ALL, "Russian");
    int n;

    printf("������� ������ ������� N: ");
    scanf_s("%d", &n);

    int** matrix = create_matrix(n);

    printf("������� �������� ������� %dx%d:\n", n, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("matrix[%d][%d] = ", i, j);
            scanf_s("%d", &matrix[i][j]);
        }
    }

    printf("\n��������� �������:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%4d", matrix[i][j]);
        }
        printf("\n");
    }

    double* averages = (double*)malloc(n * sizeof(double));
    column_averages(matrix, n, averages);

    printf("\n������� �������������� ��������:\n");
    for (int i = 0; i < n; i++) {
        printf("������� %d: %.2f\n", i, averages[i]);
    }

    int min_abs, max_abs;
    min_max_shaded_area(matrix, n, &min_abs, &max_abs);

    printf("\n�������������� ������� (�������� ���� ������� ���������):\n");
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

    printf("\n����������� �� ������ ������� � �������������� �������: %d\n", min_abs);
    printf("������������ �� ������ ������� � �������������� �������: %d\n", max_abs);

    free(averages);
    free_matrix(matrix, n);

    return 0;
}