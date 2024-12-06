#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    double value;
    struct Node* next;
    struct Node* prev;
} Node;

// Функция для создания нового узла
Node* createNode(double value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->value = value;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

// Функция для добавления узла в конец списка
void appendNode(Node** head, double value) {
    Node* newNode = createNode(value);
    if (*head == NULL) {
        *head = newNode;
        return;
    }

    Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}

// Функция для удаления узла
void deleteNode(Node** head, Node* target) {
    if (*head == NULL || target == NULL) return;

    if (*head == target) {
        *head = target->next;
    }

    if (target->next != NULL) {
        target->next->prev = target->prev;
    }

    if (target->prev != NULL) {
        target->prev->next = target->next;
    }

    free(target);
}

// Функция для удаления элемента после отрицательного
void deleteAfterNegative(Node** head) {
    Node* current = *head;

    while (current != NULL) {
        if (current->value < 0 && current->next != NULL) {
            Node* toDelete = current->next;
            deleteNode(head, toDelete);
        }
        current = current->next;
    }
}

// Функция для печати списка
void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%.2f ", temp->value);
        temp = temp->next;
    }
    printf("\n");
}

// Освобождение памяти списка
void freeList(Node* head) {
    Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    Node* head = NULL;

    // Пример данных
    appendNode(&head, 1.2);
    appendNode(&head, -3.4);
    appendNode(&head, 5.6);
    appendNode(&head, -7.8);
    appendNode(&head, 9.0);

    printf("Исходный список: ");
    printList(head);

    deleteAfterNegative(&head);

    printf("Список после удаления: ");
    printList(head);

    freeList(head);
    return 0;
}

