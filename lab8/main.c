#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 50
#define MAX_PHONE_LEN 15
#define FILE_NAME "phones.dat"

typedef struct {
    char surname[MAX_NAME_LEN];
    int year;
    char phone[MAX_PHONE_LEN];
} Subscriber;

void addSubscriber() {
    FILE *file = fopen(FILE_NAME, "ab");
    if (!file) {
        perror("Ошибка открытия файла");
        return;
    }

    Subscriber sub;
    printf("Введите фамилию: ");
    scanf("%s", sub.surname);
    printf("Введите год установки телефона: ");
    scanf("%d", &sub.year);
    printf("Введите номер телефона: ");
    scanf("%s", sub.phone);

    fwrite(&sub, sizeof(Subscriber), 1, file);
    fclose(file);
}

void deleteSubscriber() {
    FILE *file = fopen(FILE_NAME, "rb");
    if (!file) {
        perror("Ошибка открытия файла");
        return;
    }

    FILE *temp = fopen("temp.dat", "wb");
    if (!temp) {
        perror("Ошибка создания временного файла");
        fclose(file);
        return;
    }

    char surname[MAX_NAME_LEN];
    printf("Введите фамилию для удаления: ");
    scanf("%s", surname);

    Subscriber sub;
    int found = 0;
    while (fread(&sub, sizeof(Subscriber), 1, file)) {
        if (strcmp(sub.surname, surname) != 0) {
            fwrite(&sub, sizeof(Subscriber), 1, temp);
        } else {
            found = 1;
        }
    }

    fclose(file);
    fclose(temp);

    remove(FILE_NAME);
    rename("temp.dat", FILE_NAME);

    if (found)
        printf("Абонент удален.\n");
    else
        printf("Абонент с указанной фамилией не найден.\n");
}

void searchBySurname() {
    FILE *file = fopen(FILE_NAME, "rb");
    if (!file) {
        perror("Ошибка открытия файла");
        return;
    }

    char surname[MAX_NAME_LEN];
    printf("Введите фамилию для поиска: ");
    scanf("%s", surname);

    Subscriber sub;
    int found = 0;
    while (fread(&sub, sizeof(Subscriber), 1, file)) {
        if (strcmp(sub.surname, surname) == 0) {
            printf("Номер телефона: %s\n", sub.phone);
            found = 1;
            break;
        }
    }

    if (!found)
        printf("Абонент с указанной фамилией не найден.\n");

    fclose(file);
}

void countByYear() {
    FILE *file = fopen(FILE_NAME, "rb");
    if (!file) {
        perror("Ошибка открытия файла");
        return;
    }

    int year, count = 0;
    printf("Введите год: ");
    scanf("%d", &year);

    Subscriber sub;
    while (fread(&sub, sizeof(Subscriber), 1, file)) {
        if (sub.year >= year) {
            count++;
        }
    }

    printf("Количество телефонов, установленных с %d года: %d\n", year, count);

    fclose(file);
}

void displayAll() {
    FILE *file = fopen(FILE_NAME, "rb");
    if (!file) {
        perror("Ошибка открытия файла");
        return;
    }

    Subscriber sub;
    printf("\nСписок всех абонентов:\n");
    printf("%-20s %-10s %-15s\n", "Фамилия", "Год", "Номер телефона");
    printf("---------------------------------------------\n");
    while (fread(&sub, sizeof(Subscriber), 1, file)) {
        printf("%-20s %-10d %-15s\n", sub.surname, sub.year, sub.phone);
    }

    fclose(file);
}

void menu() {
    int choice;
    do {
        printf("\nМеню:\n");
        printf("1. Добавить абонента\n");
        printf("2. Удалить абонента\n");
        printf("3. Найти номер по фамилии\n");
        printf("4. Подсчитать количество телефонов с указанного года\n");
        printf("5. Вывести всех абонентов\n");
        printf("6. Выйти\n");
        printf("Выберите действие: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addSubscriber(); break;
            case 2: deleteSubscriber(); break;
            case 3: searchBySurname(); break;
            case 4: countByYear(); break;
            case 5: displayAll(); break;
            case 6: printf("Выход.\n"); break;
            default: printf("Неверный выбор. Повторите попытку.\n");
        }
    } while (choice != 6);
}

int main() {
    menu();
    return 0;
}
