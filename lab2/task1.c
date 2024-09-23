/* Дана матрица размера M x N. Поменять местами столбцы, 
содержащие минимальный и максимальный элемент матрицы.  */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap_columns(int** matrix, int rows, int col1, int col2) {
    for (int i = 0; i < rows; i++) {
        int temp = matrix[i][col1];
        matrix[i][col1] = matrix[i][col2];
        matrix[i][col2] = temp;
    }

}

int main() {
    int M, N;
    printf("Введите количество строк (M): ");
    scanf("%d", &M);
    printf("Введите количество столбцов (N): ");
    scanf("%d", &N);

    int** matrix = (int**)malloc(M * sizeof(int*));
    for (int i = 0; i < M; i++) {
        matrix[i] = (int*)malloc(N * sizeof(int));
    }

    int choice;
    printf("Выберите способ заполнения матрицы:\n1. Ввод с консоли\n2. Автоматическое заполнение случайными числами\n");
    scanf("%d", &choice);

    if (choice == 1) {
        printf("Введите элементы матрицы:\n");
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                scanf("%d", &matrix[i][j]);
            }
        }
    } else if (choice == 2) {
        srand(time(NULL));
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                matrix[i][j] = rand() % 100; // случайные числа от 0 до 99
            }
        }
    } else {
        printf("Неверный выбор.\n");
        return 1;
    }
    printf("Текущая матрица:\n");
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    int min_col = 0, max_col = 0;
    int min_value = matrix[0][0], max_value = matrix[0][0];

    // Поиск минимального и максимального элементов
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if (matrix[i][j] < min_value) {
                min_value = matrix[i][j];
                min_col = j;
            }
            if (matrix[i][j] > max_value) {
                max_value = matrix[i][j];
                max_col = j;
            }
        }
    }

    // Меняем местами столбцы
    swap_columns(matrix, M, min_col, max_col);

    // Вывод измененной матрицы
    printf("Измененная матрица:\n");
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    // Освобождение памяти
    for (int i = 0; i < M; i++) {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}