/*Дана действительная квадратная матрица порядка n.Найти наименьшее из значений элементов, 
расположенных в заштрихованной части матрицы. Диоганали не учитываются*/
/*
A)
_____________
| x x x x x |
| 0 x x x 0 |
| 0 0 x 0 0 |
| 0 x x x 0 |
| x x x x x |
_____________
B)
_____________
| 0 0 0 0 x |
| 0 0 0 x x |
| 0 0 x x x |
| 0 0 0 x x |
| 0 0 0 0 x |
_____________
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

#define MAX_SIZE 100

int find_min_in_shaded_area_A(int matrix[MAX_SIZE][MAX_SIZE], int n) {
    int min = INT_MAX;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            // Под главной диагональю и под побочной диагональю ИЛИ над главной и над побочной диагональю
            if  ((i < j && (i + j) < n - 1) || (i > j && (i + j) > n - 1)){
                if (matrix[i][j] < min) {
                    min = matrix[i][j];
                }
            }
        }
    }
    return min;
}
int find_min_in_shaded_area_B(int matrix[MAX_SIZE][MAX_SIZE], int n) {
    int min = INT_MAX;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            // Под побочной диагональю и над главной диагональю
            if ((i < j) && ((i + j) > n - 1)) {
                if (matrix[i][j] < min) {
                    min = matrix[i][j];
                }
            }
        }
    }
    return min;
}


int main() {
    int matrix[MAX_SIZE][MAX_SIZE];
    int n;

    printf("Введите размер матрицы (n): ");
    scanf("%d", &n);

    if (n <= 0 || n > MAX_SIZE) {
        printf("Неверный размер матрицы.\n");
        return 1;
    }

    int choice;
    printf("Выберите способ заполнения матрицы:\n1. Ввод с консоли\n2. Автоматическое заполнение случайными числами\n");
    scanf("%d", &choice);

    if (choice == 1) {
        printf("Введите элементы матрицы %dx%d:\n", n, n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                scanf("%d", &matrix[i][j]);
            }
        }
    } else if (choice == 2) {
       // srand(time(NULL));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                matrix[i][j] = rand() % 100; // случайные числа от 0 до 99
            }
        }
    } else {
        printf("Неверный выбор.\n");
        return 1;
    }

    // Вывод исходной матрицы
    printf("Исходная матрица:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%3d ", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    // Находим минимальные значения для обоих вариантов
    int min_A = find_min_in_shaded_area_A(matrix, n);
    int min_B = find_min_in_shaded_area_B(matrix, n);

    printf("Наименьшее значение в заштрихованной области (вариант A): %d\n", min_A);
    printf("Наименьшее значение в заштрихованной области (вариант B): %d\n", min_B);

    return 0;
}