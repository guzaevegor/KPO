#include <stdio.h>
#include <string.h>

int main(void)
{
    
    int a, integer = 42;
    unsigned int uinteger = 42;
    float floating = 3.14159;
    char character = 'A';
    char string[100];
    a = 32 - 4;
    
    // Добавим новую переменную для демонстрации
    double scientific = 6.022e23;
    
    printf("Введите строку: ");
    fgets(string, sizeof(string), stdin);
    string[strcspn(string, "\n")] = '\0';  // Удаляем символ новой строки

    printf("\n--- Результаты ---\n");
    printf("Целое число (a): %d\n", a);
    printf("Беззнаковое целое число: %u\n", uinteger);
    printf("Число с плавающей точкой: %.2f\n", floating);
    printf("Символ: %c\n", character);
    printf("Строка: %s\n", string);
    printf("Шестнадцатеричное число: 0x%x\n", integer);
    printf("Шестнадцатеричное число (с заглавными буквами): 0x%X\n", integer);
    printf("Восьмеричное число: 0%o\n", integer);
    printf("Указатель: %p\n", (void*)&integer);
    printf("Число в экспоненциальной форме: %e\n", floating);
    printf("Научная нотация: %.4e\n", scientific);
    
    // Добавим форматированный вывод в виде таблицы
    printf("\n--- Таблица значений ---\n");
    printf("| %-15s | %-15s | %-15s |\n", "Тип", "Значение", "Формат");
    printf("|----------------|----------------|----------------|\n");
    printf("| %-15s | %-15d | %%d             |\n", "int", a);
    printf("| %-15s | %-15u | %%u             |\n", "unsigned int", uinteger);
    printf("| %-15s | %-15.2f | %%f             |\n", "float", floating);
    printf("| %-15s | %-15c | %%c             |\n", "char", character);
    printf("| %-15s | %-15s | %%s             |\n", "string", string);

    return 0;
}
