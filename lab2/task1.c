/* Дана матрица размера M x N. Поменять местами столбцы, содержащие минимальный и максимальный элемент матрицы.  */
#include <stdio.h>

int main() {
    int M, N;
    
    // Ввод размеров матрицы
    printf("Input M: ");
    scanf("%d", &M);
    printf("Input N: ");
    scanf("%d", &N);

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

    // Инициализация переменных для поиска минимального и максимального элемента
    int min = matrix[0][0], max = matrix[0][0];
    int min_col = 0, max_col = 0;

    // Поиск столбцов с минимальным и максимальным элементами
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if (matrix[i][j] < min) {
                min = matrix[i][j];
                min_col = j;
            }
            if (matrix[i][j] > max) {
                max = matrix[i][j];
                max_col = j;
            }
        }
    }

    // Обмен столбцов
    for (int i = 0; i < M; i++) {
        int temp = matrix[i][min_col];
        matrix[i][min_col] = matrix[i][max_col];
        matrix[i][max_col] = temp;
    }

    // Вывод измененной матрицы
    printf("Modified matrix:\n");
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}
