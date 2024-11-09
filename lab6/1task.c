/*Дана ведомость абитуриентов. В каждой строке записана фамилия абитуриента, 
город проживания, средний балл аттестата. Вывести на экран количество абитуриентов, 
проживающих в Минске и имеющих аттестат со средним баллом не ниже 7. Распечатать список в алфавитном порядке*/
#include <stdio.h>
#include <string.h>
#include <assert.h>

#define MAX_APPLICANTS 100
#define NAME_LENGTH 50
#define CITY_LENGTH 30

// Структура для хранения данных абитуриента
typedef struct {
    char name[NAME_LENGTH];
    char city[CITY_LENGTH];
    float average_score;
} Applicant;

// Константные данные для тестирования
const Applicant test_data[] = {
    {"Ivanov", "Минск", 8.2},
    {"Petrov", "Гродно", 6.5},
    {"Sidorov", "Минск", 7.0},
    {"Pavlov", "Минск", 5.5},
    {"ASmirnov", "Минск", 9.0},
    {"Kuznetsov", "Витебск", 7.5}
};

const int test_data_count = sizeof(test_data) / sizeof(test_data[0]);

// Функция сравнения для сортировки по имени
int compare_names(const void *a, const void *b) {
    Applicant *applicantA = (Applicant *)a;
    Applicant *applicantB = (Applicant *)b;
    return strcmp(applicantA->name, applicantB->name);
}

// Функция для фильтрации и сортировки абитуриентов
int filter_and_sort_applicants(Applicant applicants[], int count, Applicant result[]) {
    int valid_count = 0;

    // Отбор подходящих абитуриентов
    for (int i = 0; i < count; i++) {
        if (strcmp(applicants[i].city, "Минск") == 0 && applicants[i].average_score >= 7.0) {
            result[valid_count++] = applicants[i];
        }
    }

    // Сортировка подходящих абитуриентов по имени
    qsort(result, valid_count, sizeof(Applicant), compare_names);
    return valid_count;
}

// Функция для печати результата
void print_applicants(const Applicant applicants[], int count) {
    for (int i = 0; i < count; i++) {
        printf("%s, город: %s, средний балл: %.2f\n", applicants[i].name, applicants[i].city, applicants[i].average_score);
    }
    printf("Всего абитуриентов из Минска со средним баллом >= 7: %d\n", count);
}

// Тестовая функция
void run_tests() {
    Applicant filtered_applicants[MAX_APPLICANTS];
    int count = filter_and_sort_applicants((Applicant *)test_data, test_data_count, filtered_applicants);

    // Проверка количества отобранных абитуриентов
    assert(count == 3);

    // Проверка отсортированных данных
    assert(strcmp(filtered_applicants[0].name, "ASmirnov") == 0);
    assert(strcmp(filtered_applicants[1].name, "Ivanoc") == 0);
    assert(strcmp(filtered_applicants[2].name, "Sidorov") == 0);

    printf("Тесты пройдены успешно.\n");
}

int main() {
    //run_tests();

    // Вывод отфильтрованных и отсортированных абитуриентов
    Applicant filtered_applicants[MAX_APPLICANTS];
    int count = filter_and_sort_applicants((Applicant *)test_data, test_data_count, filtered_applicants);

    printf("Список абитуриентов из Минска со средним баллом >= 7:\n");
    print_applicants(filtered_applicants, count);

    return 0;
}
