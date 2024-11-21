/*Разработать программу слияниях двух отсортированных по убыванию значений элементов файлов F1 и F2. Результатом сияния должен быть файл F3, элементы которого упорядоченны по возрастанию*/
#include <stdio.h>
#include <stdlib.h>

#define MAX_LINES 1000

void mergeSortedFiles(const char *file1, const char *file2, const char *outputFile) {
    int numbers[MAX_LINES];
    int count = 0;

    // Функция для чтения чисел из файла
    void readNumbersFromFile(const char *filename) {
        FILE *file = fopen(filename, "r");
        if (!file) {
            perror("Ошибка открытия файла");
            return;
        }

        int num;
        while (fscanf(file, "%d", &num) == 1) {
            numbers[count++] = num;
        }
        fclose(file);
    }

    // Читаем числа из обоих файлов
    readNumbersFromFile(file1);
    readNumbersFromFile(file2);

    // Сортировка массива по возрастанию
    for (int i = 0; i < count - 1; i++) {
        for (int j = i + 1; j < count; j++) {
            if (numbers[i] > numbers[j]) {
                int temp = numbers[i];
                numbers[i] = numbers[j];
                numbers[j] = temp;
            }
        }
    }

    // Запись результата в выходной файл
    FILE *output = fopen(outputFile, "w");
    if (!output) {
        perror("Ошибка открытия выходного файла");
        return;
    }

    for (int i = 0; i < count; i++) {
        fprintf(output, "%d\n", numbers[i]);
    }

    fclose(output);
    printf("Слияние завершено. Результат в файле %s.\n", outputFile);
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Использование: %s file1 file2 output_file\n", argv[0]);
        return 1;
    }

    mergeSortedFiles(argv[1], argv[2], argv[3]);
    return 0;
}
