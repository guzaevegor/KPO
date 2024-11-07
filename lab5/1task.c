#include <stdio.h>
#include <string.h>
#include <locale.h>

#define MAX_WORDS 100
#define MAX_LENGTH 100

char english_words[MAX_WORDS][MAX_LENGTH] = {
    "THIS",
    "IS",
    "A",
    "TABLE",
    "EXAMPLE",
    "PROGRAM",
    "OF",
    "DOG"
};

char russian_words[MAX_WORDS][MAX_LENGTH] = {
    "ЭТО",
    "",
    "",
    "СТОЛ",
    "ПРИМЕР",
    "ПРОГРАММЫ",
    "ЭТОЙ",
    "СОБАКА"
};

int dictionary_size = sizeof(english_words) / sizeof(english_words[0]);

const char* translate(const char* word) {
    for (int i = 0; i < dictionary_size; i++) {
        if (strcmp(english_words[i], word) == 0) {
            return russian_words[i];
        }
    }
    return word; 
}

int main() {
    setlocale(LC_ALL, "");

    char input[MAX_LENGTH];
    char output[MAX_LENGTH * MAX_WORDS] = ""; 
    char* token;
    char* context;

    printf("Введите предложение на английском языке:\n");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = 0;

    // Используем strtok_r вместо strtok_s
    token = strtok_r(input, "_", &context);

    int first_word = 1; // Флаг для первого слова

    while (token != NULL) {
        const char* translation = translate(token);

        // Добавляем разделитель только между непустыми переводами
        if (strlen(translation) > 0) {
            if (!first_word) {
                strcat(output, "_");
            }
            strcat(output, translation);
            first_word = 0;
        }

        token = strtok_r(NULL, "_", &context);
    }

    printf("Перевод:\n%s\n", output);
    return 0;
}
