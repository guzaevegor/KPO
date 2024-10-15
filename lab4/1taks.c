#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_INPUT_LENGTH 100

// Функция для генерации случайной строки
void generate_random_string(char *str, int word_count, int max_word_length) {
    const char charset[] = "abcdefghijklmnopqrstuvwxyz";
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

// Функция для нахождения длины самого короткого слова
int find_shortest_word_length(const char *str) {
    int shortest_length = MAX_INPUT_LENGTH; // инициализируем максимальным значением
    int current_length = 0;

    while (*str) {
        if (*str != ' ') {
            current_length++;
        } else if (current_length > 0) {
            if (current_length < shortest_length) {
                shortest_length = current_length;
            }
            current_length = 0; // сбрасываем длину для следующего слова
        }
        str++;
    }

    // Проверяем последнее слово
    if (current_length > 0 && current_length < shortest_length) {
        shortest_length = current_length;
    }

    return shortest_length == MAX_INPUT_LENGTH ? 0 : shortest_length; // если не нашли, возвращаем 0
}

int main() {
    srand(time(NULL)); // инициализируем генератор случайных чисел

    int choice;
    char input_string[MAX_INPUT_LENGTH];

    printf("Выберите вариант ввода:\n");
    printf("1. Сгенерировать случайную строку\n");
    printf("2. Ввести строку вручную\n");
    printf("Введите 1 или 2: ");
    scanf("%d", &choice);
    getchar(); // очищаем буфер ввода

    if (choice == 1) {
        int word_count, max_word_length;
        printf("Введите количество слов и максимальную длину слов: ");
        scanf("%d %d", &word_count, &max_word_length);
        getchar(); // очищаем буфер ввода
        
        char *random_string = malloc((word_count * (max_word_length + 1)) * sizeof(char));
        generate_random_string(random_string, word_count, max_word_length);
        printf("Сгенерированная строка: %s\n", random_string);
        int shortest_length = find_shortest_word_length(random_string);
        printf("Длина самого короткого слова: %d\n", shortest_length);
        free(random_string); // освобождаем память
    } else if (choice == 2) {
        printf("Введите строку: ");
        fgets(input_string, sizeof(input_string), stdin);
        input_string[strcspn(input_string, "\n")] = '\0'; // удаляем символ новой строки
        int shortest_length = find_shortest_word_length(input_string);
        printf("Длина самого короткого слова: %d\n", shortest_length);
    } else {
        printf("Неверный выбор.\n");
    }

    return 0;
}
