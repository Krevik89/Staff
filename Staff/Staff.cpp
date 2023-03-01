#include <iostream>
#include <conio.h>
#include "Header.h"
using namespace std;


int main() {
    setlocale(LC_ALL, "");
    struct Staf staf[100]; 
    int count = 0; 
    int index;
    char letter = 0;
    char lastName[50];
    char path[] = "Staf.txt";
    int age = 0;
    FILE* file;
    fopen_s(&file,"Staf.txt", "r");
    if (file == NULL) {
        printf("Ошибка открытия файла!");
        exit(1);
    }
    while (!feof(file)) {
        fscanf_s(file, "%s %s %d",
            staf[count].firstName, sizeof(staf[count].firstName),
            staf[count].lastName,sizeof(staf[count].lastName),
            &staf[count].age);
        count++;
    }
    fclose(file);
   
    int choise = 0;
    do
    {
        system("pause");
        system("cls");
        printStaf(staf, count);
        cout << "\t\t\t~~~Сотрудники~~~\n"
            << "1. Добавить сотрудника\n"
            << "2. Редактировать сотрудника\n"
            << "3. Удалить сторудника\n"
            << "4. Поиск сторудника по фамилии\n"
            << "5. Поиск сторудника по 1 букве фамилии\n"
            << "6. Поиск сотрудника по возрасту\n"
            << "7. Сохранить изминения\n"
            << "0. Выход\n";
       cin >> choise;
       switch (choise)
       {
       case 1:
           addStaf(staf, &count);
           break;
       case 2:
           printf("Введите индекс сотрудника, данные которого нужно отредактировать: ");
           scanf_s("%d", &index);
           if (index >= 0 && index < count) {
               editStaf(staf, index);
               printf("\nДанные о сотруднике успешно отредактированы!\n\n");
           }
           else {
               printf("\nНекорректный индекс сотрудника!\n\n");
           }
           break;
       case 3:
           printf("Введите индекс сотрудника, которого нужно удалить: ");
           scanf_s("%d", &index);
           deleteStaf(staf, &count, index);
           break;
       case 4:
           printf("Введите фамилию сотрудника для поиска: ");
           scanf_s("%s", lastName, sizeof(lastName));
           findStafLastName(staf, count, lastName);
           break;
       case 5:
           cout << "Введите первую букву фамилии для поиска\n";
           cin >> letter;
           FindhLastNameOne(letter, staf, count);
           break;
       case 6:
           printf("Введите возраст сотрудников для поиска: ");
           scanf_s("%d", &age);
           findStafAge(staf, count, age);
           break;
       case 7:
           printf("Введите путь сохранения например (Staf.txt):  ");
           scanf_s("%s", path, sizeof(path));
           saveToFile(staf, count, path);
           break;
       case 0:
           break;
       default:
           break;
       }
    } while (choise!=0);
    saveToFile(staf, count, path);
}