/*ввести матрицу 5*5. Упорядочить столбцы этой матрицы по убыванию сумм их элементов*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 5

void swap_columns(int matrix[SIZE][SIZE], int col1, int col2) {
    for (int i = 0; i < SIZE; i++) {
        int temp = matrix[i][col1];
        matrix[i][col1] = matrix[i][col2];
        matrix[i][col2] = temp;
    }
}

int main() {
    int matrix[SIZE][SIZE];
    int sums[SIZE] = {0};

    int choice;
    printf("Выберите способ заполнения матрицы:\n1. Ввод с консоли\n2. Автоматическое заполнение случайными числами\n");
    scanf("%d", &choice);

    if (choice == 1) {
        printf("Введите элементы матрицы 5x5:\n");
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                scanf("%d", &matrix[i][j]);
            }
        }
    } else if (choice == 2) {
        srand(time(NULL));
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                matrix[i][j] = rand() % 100; // случайные числа от 0 до 99
            }
        }
    } else {
        printf("Неверный выбор.\n");
        return 1;
    }

    // Вычисление сумм столбцов
    for (int j = 0; j < SIZE; j++) {
        for (int i = 0; i < SIZE; i++) {
            sums[j] += matrix[i][j];
        }
    }

    // Вывод исходной матрицы с суммами столбцов
    printf("Исходная матрица:\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%3d ", matrix[i][j]);
        }
        printf("\n");
    }
    printf("Суммы столбцов:\n");
    for (int j = 0; j < SIZE; j++) {
        printf("%3d ", sums[j]);
    }
    printf("\n\n");

    // Сортировка столбцов по убыванию сумм
    for (int i = 0; i < SIZE - 1; i++) {
        for (int j = 0; j < SIZE - i - 1; j++) {
            if (sums[j] < sums[j + 1]) {
                // Меняем местами суммы
                int temp = sums[j];
                sums[j] = sums[j + 1];
                sums[j + 1] = temp;
                // Меняем местами столбцы
                swap_columns(matrix, j, j + 1);
            }
        }
    }

    // Удаляем повторное вычисление сумм столбцов

    // Вывод отсортированной матрицы
    printf("\nОтсортированная матрица:\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%3d ", matrix[i][j]);
        }
        printf("\n");
    }
    printf("Суммы столбцов:\n");
    for (int j = 0; j < SIZE; j++) {
        printf("%3d ", sums[j]);
    }
    printf("\n\n");

    return 0;
}