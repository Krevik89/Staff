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
        printf("��������� %d:\n", i + 1);
        printf("���: %s\n", staf[i].firstName);
        printf("�������: %s\n", staf[i].lastName);
        printf("�������: %d\n\n", staf[i].age);
    }
}

void addStaf(Staf staf[], int* count) {
    Staf newStaf;
    printf("������� ��� ����������: ");
    scanf_s("%s", newStaf.firstName, sizeof(newStaf.firstName));
    printf("������� ������� ����������: ");
    scanf_s("%s", newStaf.lastName, sizeof(newStaf.lastName));
    printf("������� ������� ����������: ");
    scanf_s("%d", &newStaf.age);
    staf[*count] = newStaf;
    (*count)++;
    printf("��������� ������� ��������!\n");
}

// ����� ��� �������������� ���������� 
void editStaf(struct Staf staf[], int index) {
    printf("������� ����� ������ ��� ���������� %d:\n", index + 1);
    printf("���: ");
    scanf_s("%s", staf[index].firstName, sizeof(staf[index].firstName));
    printf("�������: ");
    scanf_s("%s", staf[index].lastName, sizeof(staf[index].lastName));
    printf("�������: ");
    scanf_s("%d", &staf[index].age);
}

// ����� ��� �������� ���������� �� �������
void deleteStaf(struct Staf staf[], int* count, int index) {
    if (index >= 0 && index < *count) {
        // �������� ��� �������� ������� �� ���� ������� �����
        for (int i = index; i < *count - 1; i++) {
            strcpy_s(staf[i].firstName, staf[i + 1].firstName);
            strcpy_s(staf[i].lastName, staf[i + 1].lastName);
            staf[i].age = staf[i + 1].age;
        }
        // ��������� ���������� ����������� �� 1
        (*count)--;
        printf("��������� ������� ������!\n\n");
    }
    else {
        printf("������������ ������ ����������!\n\n");
    }
}

// ����� ��� ������ ���������� �� �������
void findStafLastName(struct Staf staf[], int count, char* lastName) {
    int found = 0;

    for (int i = 0; i < count; i++) {
        if (strcmp(staf[i].lastName, lastName) == 0) {
            printf("���: %s\n", staf[i].firstName);
            printf("�������: %s\n", staf[i].lastName);
            printf("�������: %d\n\n", staf[i].age);
            found = 1;
        }
    }

    if (!found) {
        printf("��������� � �������� %s �� ������!\n\n", lastName);
    }
}

// ����� ��� ������ ���������� �� ������� 1-�����
void FindhLastNameOne(char letter, Staf staf[], int count) {
    int found = 0;
    printf("����������, ������� ������� ���������� �� ����� %c:\n", letter);
    for (int i = 0; i < count; i++) {
        if (staf[i].lastName[0] == letter) {
            printf("���: %s\n", staf[i].firstName);
            printf("�������: %s\n", staf[i].lastName);
            printf("�������: %d\n\n", staf[i].age);
            found = 1;
        }
    }
    if (!found) {
        printf("����������� � ��������, ������������ �� ����� %c, �� �������.\n", letter);
    }
}

// ����� ��� ������ ����������� �� ��������
void findStafAge(struct Staf staf[], int count, int age) {
    int found = 0;
    printf("���������� � ��������� %d\n", age);
    for (int i = 0; i < count; i++) {
        if (staf[i].age == age) {
            printf("���: %s\n", staf[i].firstName);
            printf("�������: %s\n", staf[i].lastName);
            printf("�������: %d\n\n", staf[i].age);
            found = 1;
        }
    }
    if (!found) {
        printf("���������� � ��������� %d �� �������!\n\n", age);
    }
}

void saveToFile(struct Staf staf[], int count, char* fileName) {
    FILE* file1;
    fopen_s(&file1, "Staf.txt", "w");
    if (file1 == NULL) {
        printf("������ �������� �����!");
    }

    for (int i = 0; i < count; i++) {
        fprintf(file1, "%s %s %d\n", staf[i].firstName, staf[i].lastName, staf[i].age);
    }
    fclose(file1);
    printf("���������� ������� ��������� � ����� %s\n", fileName);
}