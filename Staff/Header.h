#pragma once
#include <iostream>
#include <conio.h>

using namespace std;

struct Staf {
    char firstName[50];
    char lastName[50];
    int age;
};

void printStaf(struct Staf staf[], int count) {
    for (int i = 0; i < count; i++) {
        printf("Сотрудник %d:\n", i + 1);
        printf("Имя: %s\n", staf[i].firstName);
        printf("Фамилия: %s\n", staf[i].lastName);
        printf("Возраст: %d\n\n", staf[i].age);
    }
}

void addStaf(Staf staf[], int* count) {
    Staf newStaf;
    printf("Введите имя сотрудника: ");
    scanf_s("%s", newStaf.firstName, sizeof(newStaf.firstName));
    printf("Введите фамилию сотрудника: ");
    scanf_s("%s", newStaf.lastName, sizeof(newStaf.lastName));
    printf("Введите возраст сотрудника: ");
    scanf_s("%d", &newStaf.age);
    staf[*count] = newStaf;
    (*count)++;
    printf("Сотрудник успешно добавлен!\n");
}

// Метод для редактирования сотрудника 
void editStaf(struct Staf staf[], int index) {
    printf("Введите новые данные для сотрудника %d:\n", index + 1);
    printf("Имя: ");
    scanf_s("%s", staf[index].firstName, sizeof(staf[index].firstName));
    printf("Фамилия: ");
    scanf_s("%s", staf[index].lastName, sizeof(staf[index].lastName));
    printf("Возраст: ");
    scanf_s("%d", &staf[index].age);
}

// Метод для удаления сотрудника по индексу
void deleteStaf(struct Staf staf[], int* count, int index) {
    if (index >= 0 && index < *count) {
        // Сдвигаем все элементы массива на одну позицию влево
        for (int i = index; i < *count - 1; i++) {
            strcpy_s(staf[i].firstName, staf[i + 1].firstName);
            strcpy_s(staf[i].lastName, staf[i + 1].lastName);
            staf[i].age = staf[i + 1].age;
        }
        // Уменьшаем количество сотрудников на 1
        (*count)--;
        printf("Сотрудник успешно удален!\n\n");
    }
    else {
        printf("Некорректный индекс сотрудника!\n\n");
    }
}

// Метод для поиска сотрудника по фамилии
void findStafLastName(struct Staf staf[], int count, char* lastName) {
    int found = 0;

    for (int i = 0; i < count; i++) {
        if (strcmp(staf[i].lastName, lastName) == 0) {
            printf("Имя: %s\n", staf[i].firstName);
            printf("Фамилия: %s\n", staf[i].lastName);
            printf("Возраст: %d\n\n", staf[i].age);
            found = 1;
        }
    }

    if (!found) {
        printf("Сотрудник с фамилией %s не найден!\n\n", lastName);
    }
}

// Метод для поиска сотрудника по фамилии 1-буквы
void FindhLastNameOne(char letter, Staf staf[], int count) {
    int found = 0;
    printf("Сотрудники, фамилия которых начинается на букву %c:\n", letter);
    for (int i = 0; i < count; i++) {
        if (staf[i].lastName[0] == letter) {
            printf("Имя: %s\n", staf[i].firstName);
            printf("Фамилия: %s\n", staf[i].lastName);
            printf("Возраст: %d\n\n", staf[i].age);
            found = 1;
        }
    }
    if (!found) {
        printf("Сотрудников с фамилией, начинающейся на букву %c, не найдено.\n", letter);
    }
}

// Метод для поиска сотрудников по возрасту
void findStafAge(struct Staf staf[], int count, int age) {
    int found = 0;
    printf("Сотрудники с возрастом %d\n", age);
    for (int i = 0; i < count; i++) {
        if (staf[i].age == age) {
            printf("Имя: %s\n", staf[i].firstName);
            printf("Фамилия: %s\n", staf[i].lastName);
            printf("Возраст: %d\n\n", staf[i].age);
            found = 1;
        }
    }
    if (!found) {
        printf("Сотрудники с возрастом %d не найдены!\n\n", age);
    }
}

void saveToFile(struct Staf staf[], int count, char* fileName) {
    FILE* file1;
    fopen_s(&file1, "Staf.txt", "w");
    if (file1 == NULL) {
        printf("Ошибка открытия файла!");
    }

    for (int i = 0; i < count; i++) {
        fprintf(file1, "%s %s %d\n", staf[i].firstName, staf[i].lastName, staf[i].age);
    }
    fclose(file1);
    printf("Информация успешно сохранена в файле %s\n", fileName);
}