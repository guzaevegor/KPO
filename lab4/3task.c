/*Дана строка, состоящая из слов, набранных заглавными буквами и
разделенных пробелами (одним или несколькими). Вывести строку,
содержащую эти же слова, разделенные одним пробелом
и расположенные в алфавитном порядке.*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_WORDS 10
#define MAX_WORD_LENGTH 5

// Функция для генерации случайной строки с заглавными буквами
void generate_random_string(char *str, int word_count, int max_word_length) {
    const char charset[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char *ptr = str;
    
    for (int i = 0; i < word_count; i++) {
        int word_length = rand() % max_word_length + 1; // длина слова от 1 до max_word_length
        for (int j = 0; j < word_length; j++) {
            *ptr++ = charset[rand() % (sizeof(charset) - 1)];
        }
        *ptr++ = ' '; // добавляем пробел
    }
    *(ptr - 1) = '\0'; // заменяем последний пробел на нуль-терминатор
}

// Функция для сравнения двух строк (используется в qsort)
int compare_words(const void *a, const void *b) {
    return strcmp(*(const char **)a, *(const char **)b);
}

// Функция для сортировки и вывода строки с отсортированными словами
void sort_and_print_words(char *str) {
    char *words[100];  // массив указателей на слова
    int word_count = 0;

    // Разделение строки на слова
    char *token = strtok(str, " ");
    while (token != NULL) {
        words[word_count++] = token;
        token = strtok(NULL, " ");
    }

    // Сортировка слов
    qsort(words, word_count, sizeof(char *), compare_words);

    // Вывод отсортированных слов с одним пробелом между ними
    for (int i = 0; i < word_count; i++) {
        if (i > 0) printf(" ");
        printf("%s", words[i]);
    }
    printf("\n");
}

int main() {
    srand(time(NULL)); // инициализируем генератор случайных чисел
    char input_string[200];

    printf("Выберите способ ввода строки:\n");
    printf("1. Сгенерировать случайную строку\n");
    printf("2. Ввести строку вручную\n");
    printf("> ");
    int choice;
    scanf("%d", &choice);
    getchar(); // очищаем буфер

    if (choice == 1) {
        generate_random_string(input_string, MAX_WORDS, MAX_WORD_LENGTH);
        printf("Сгенерированная строка: %s\n", input_string);
    } else if (choice == 2) {
        printf("Введите строку (слова заглавными буквами):\n");
        fgets(input_string, sizeof(input_string), stdin);
        input_string[strcspn(input_string, "\n")] = '\0'; // удаляем символ новой строки
    } else {
        printf("Неверный выбор.\n");
        return 1;
    }

    // Сортировка и вывод отсортированных слов
    sort_and_print_words(input_string);

    return 0;
}
