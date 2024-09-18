/*Дана матрица размера M x N (M - четное число). Поменять местами верхнюю и нижнюю половину матрицы. */
#include <stdio.h>

int main() {
    int M, N;

    // Ввод размеров матрицы
    printf("Input M (M should be an even number): ");
    scanf("%d", &M);
    printf("Input N: ");
    scanf("%d", &N);

    // Проверка на четность M
    if (M % 2 != 0) {
        printf("M must be an even number!\n");
        return 1; // Завершаем программу, если M нечетное
    }

    int matrix[M][N];

    // Ввод элементов матрицы
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            printf("Input matrix[%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }

    // Вывод изначальной матрицы
    printf("Original matrix:\n");
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    // Обмен верхней и нижней половины матрицы
    for (int i = 0; i < M / 2; i++) {
        for (int j = 0; j < N; j++) {
            int temp = matrix[i][j];
            matrix[i][j] = matrix[M / 2 + i][j];
            matrix[M / 2 + i][j] = temp;
        }
    }

    // Вывод измененной матрицы
    printf("Modified matrix (upper and lower halves swapped):\n");
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}
