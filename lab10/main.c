#include <stdio.h>
#include <stdlib.h>

// Структура узла стека
typedef struct StackNode {
    int value;
    struct StackNode* next;
} StackNode;

// Функция для создания нового узла стека
StackNode* createNode(int value) {
    StackNode* newNode = (StackNode*)malloc(sizeof(StackNode));
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}

// Функция для добавления элемента в стек
void push(StackNode** top, int value) {
    StackNode* newNode = createNode(value);
    newNode->next = *top;
    *top = newNode;
}

// Функция для удаления элемента из стека
int pop(StackNode** top) {
    if (*top == NULL) {
        printf("Стек пуст!\n");
        return 0;
    }
    StackNode* temp = *top;
    int value = temp->value;
    *top = (*top)->next;
    free(temp);
    return value;
}

// Функция для проверки, пуст ли стек
int isEmpty(StackNode* top) {
    return top == NULL;
}

// Функция для вывода содержимого стека
void printStack(StackNode* top) {
    while (top != NULL) {
        printf("%d ", top->value);
        top = top->next;
    }
    printf("\n");
}

// Функция для преобразования исходного стека в два новых
void splitStack(StackNode** original, StackNode** positives, StackNode** negatives) {
    while (!isEmpty(*original)) {
        int value = pop(original);
        if (value > 0) {
            push(positives, value);
        } else if (value < 0) {
            push(negatives, value);
        }
    }
}

int main() {
    StackNode* original = NULL;
    StackNode* positives = NULL;
    StackNode* negatives = NULL;

    // Пример заполнения стека
    push(&original, 5);
    push(&original, -3);
    push(&original, 10);
    push(&original, -8);
    push(&original, 7);
    push(&original, 0);

    printf("Исходный стек: ");
    printStack(original);

    // Разделение стека
    splitStack(&original, &positives, &negatives);

    printf("Стек положительных чисел: ");
    printStack(positives);

    printf("Стек отрицательных чисел: ");
    printStack(negatives);

    return 0;
}

