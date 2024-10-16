/*Дана строка, состоящая из слов, набранных заглавными буквами и
разделенных пробелами (одним или несколькими). Найти количество
слов, которые содержат хотя бы одну букву «А».*/
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

// Функция для нахождения количества слов с буквой 'А'
int count_words_with_A(const char *str) {
    int count = 0;
    int found_A = 0;
    int in_word = 0; // Флаг, указывающий, что мы внутри слова

    while (*str) {
        if (*str == ' ') {
            if (in_word) { // Если конец слова и в слове была 'А'
                if (found_A) {
                    count++;
                }
                found_A = 0;
                in_word = 0; // Мы больше не внутри слова
            }
        } else {
            in_word = 1; // Мы внутри слова
            if (*str == 'A') {
                found_A = 1; // нашли 'А' в слове
            }
        }
        str++;
    }

    // Проверяем последнее слово
    if (in_word && found_A) {
        count++;
    }

    return count;
}

int main() {
    srand(time(NULL)); // инициализируем генератор случайных чисел
    char input_string[200];

    printf("Выберите способ ввода строки:\n");
    printf("1. Сгенерировать случайную строку\n");
    printf("2. Ввести строку вручную\n");
    int choice;
    printf("> ");
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

    int count = count_words_with_A(input_string);
    printf("Количество слов с буквой 'А': %d\n", count);

    return 0;
}
