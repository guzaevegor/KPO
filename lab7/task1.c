/*Разработать программу, объединяющую несколько файлов содержащих списки студенческих групп, в один результирующий файл. Запись производится в алфавитном порядке*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 1000
#define MAX_LENGTH 256

void mergeFiles(char *outputFile, int fileCount, char *inputFiles[]) {
    char *lines[MAX_LINES];
    int lineCount = 0;

    // Читаем строки из всех файлов
    for (int i = 0; i < fileCount; i++) {
        FILE *file = fopen(inputFiles[i], "r");
        if (!file) {
            perror("Ошибка открытия файла");
            continue;
        }

        char buffer[MAX_LENGTH];
        while (fgets(buffer, MAX_LENGTH, file)) {
            // Удаляем символ новой строки
            buffer[strcspn(buffer, "\n")] = '\0';
            lines[lineCount] = strdup(buffer);
            lineCount++;
        }
        fclose(file);
    }

    // Сортируем строки
    for (int i = 0; i < lineCount - 1; i++) {
        for (int j = i + 1; j < lineCount; j++) {
            if (strcmp(lines[i], lines[j]) > 0) {
                char *temp = lines[i];
                lines[i] = lines[j];
                lines[j] = temp;
            }
        }
    }

    // Записываем результат в выходной файл
    FILE *output = fopen(outputFile, "w");
    if (!output) {
        perror("Ошибка открытия выходного файла");
        return;
    }

    for (int i = 0; i < lineCount; i++) {
        fprintf(output, "%s\n", lines[i]);
        free(lines[i]); // Освобождаем память
    }

    fclose(output);
    printf("Объединение завершено. Результат в файле %s.\n", outputFile);
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Использование: %s output_file input_file1 input_file2 ...\n", argv[0]);
        return 1;
    }

    mergeFiles(argv[1], argc - 2, &argv[2]);
    return 0;
}
