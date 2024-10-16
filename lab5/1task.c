#include <stdio.h>
#include <string.h>

#define MAX_WORDS 100
#define MAX_WORD_LENGTH 50

// Структура для хранения базы данных перевода
typedef struct {
    char english[MAX_WORD_LENGTH];
    char russian[MAX_WORD_LENGTH];
} Translation;

Translation dictionary[] = {
    {"THIS", "ЭТО"},
    {"IS", ""},         // Пустой перевод
    {"A", " "},         // Пробел как перевод
    {"TABLE", "СТОЛ"}
};

const int dictionary_size = sizeof(dictionary) / sizeof(dictionary[0]);

// Функция для поиска перевода слова
const char* translate_word(const char* word) {
    for (int i = 0; i < dictionary_size; i++) {
        if (strcmp(word, dictionary[i].english) == 0) {
            return dictionary[i].russian;
        }
    }
    return word; // Если слово не найдено, возвращаем его же
}

// Функция для разбора строки на слова и перевода
void translate_sentence(const char* sentence) {
    char word[MAX_WORD_LENGTH];
    int word_index = 0;
    int print_separator = 0; // Флаг для вывода разделителя
    
    for (int i = 0; i <= strlen(sentence); i++) {
        if (sentence[i] == ' ' || sentence[i] == '_' || sentence[i] == '\0') {
            word[word_index] = '\0'; // завершение слова
            
            if (word_index > 0) { // Если слово не пустое
                if (print_separator) {
                    printf("_"); // Выводим разделитель перед следующим словом
                }
                printf("%s", translate_word(word));
                print_separator = 1; // Разрешаем выводить разделитель
            }
            
            word_index = 0; // начинаем новое слово
        } else {
            word[word_index++] = sentence[i];
        }
    }
}

int main() {
    char input[MAX_WORD_LENGTH * MAX_WORDS];

    // Ввод предложения на английском языке
    printf("Введите предложение на английском языке:\n");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0'; // удаляем символ новой строки

    // Вывод перевода
    printf("Перевод:\n");
    translate_sentence(input);

    return 0;
}
