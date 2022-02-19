// Copyright 2021 qqq <polyakovdd@student.bmstu.ru>

#include "1.4.hpp"

int main() {
    menu();
    return 0;
}

void printMenuList() {
    std::cout << " ============== ГЛАВНОЕ МЕНЮ ========================\n";
    std::cout << "l - добавить кафедру\t 3 - редактирование сведений" << '\n';
    std::cout << "2 - удалить кафедру\t 4 - вывод базы на экран" << '\n';
    std::cout << "\t\t 5 - сохранение базы в файл" << '\n';
    std::cout << "\t\t\t 6 - выход" << '\n';
    std::cout << "Для выбора операции введите цифру от 1 до 6:" << '\n';
}

void menu() {
    int menuPoint = 0;
    int n = 0;
    Department departments[ARRAY_SIZE];
    readFile(departments, n);
    do {
        printMenuList();
        std::cin >> menuPoint;
        switch (menuPoint) {
            case 1:
                addDepartment(departments, n);
                break;
            case 2:
                deleteDepartment(departments, n);
                break;
            case 3:
                editDepartment(departments, n);
                break;
            case 4:
                printDepartments(departments, n);
                break;
            case 5:
                writeDB(departments, n);
                break;
            case 6:
                return;
            default:
                return;
        }
    } while (menuPoint != 6);

}

int readFile(Department *arr, int &n) {
    std::ifstream fin(FILENAME, std::ios::in);
    if (!fin) {
        std::cout << "Файл не найден\n";
        return 1;
    }
    fin >> n;
    if (n > 12) {
        std::cout << "Переполнение БД. n= " << n << '\n';
        return 1;
    }
    for (int i = 0; i < n; i++) {
        fin >> arr[i];
    }
    fin.close();
    return 0;
}

void addDepartment(Department *departments, int &n) {
    char *name = new char[20];
    size_t count, score;
    std::cout << "Введите название кафедры:\n";
    std::cin >> name;
    departments[n].SetName(name);
    std::cout << "Введите количество студентов:\n";
    std::cin >> count;
    departments[n].SetStudentsCount(count);
    std::cout << "Введите проходной балл:\n";
    std::cin >> score;
    departments[n].SetMinimalScore(score);
    n++;
}

void printDepartments(Department *departments, const int n) {
    std::sort(departments, departments + n);
    std::cout << " Список кафедр: " << '\n';
    std::cout << " Название:           Количество студентов:       Проходные баллы: " << '\n';
    for (int i = 0; i < n; i++) {
        std::cout << std::setw(3) << i + 1 << ". ";
        std::cout << departments[i];
    }
}

void deleteDepartment(Department *departments, int &n) {
    printDepartments(departments, n);
    std::cout << "Выберите номер кафедры, которую хотите удалить\n";
    int i = 0;
    std::cin >> i;
    i--;
    n--;
    for (size_t j = i; j < n; ++j) {
        departments[j] = departments[j + 1];
    }
}

void editDepartment(Department *departments, const int n) {
    printDepartments(departments, n);
    std::cout << "Выберите номер кафедры, которую хотите изменить\n";
    int i = 0;
    std::cin >> i;
    i--;
    char *name = new char[20];
    size_t count, score;
    std::cout << "Введите новое название кафедры:\n";
    std::cin >> name;
    departments[i].SetName(name);
    std::cout << "Введите новое количество студентов:\n";
    std::cin >> count;
    departments[i].SetStudentsCount(count);
    std::cout << "Введите новое проходной балл:\n";
    std::cin >> score;
    departments[i].SetMinimalScore(score);
}

void writeDB(Department *departments, const int n) {
    std::sort(departments, departments + n);
    std::ofstream fout(FILENAME, std::ios::out);
    if (!fout) {
        std::cout << "Ошибка открытия файла" << std::endl;
        return;
    }
    fout << n << '\n';
    for (int i = 0; i < n; i++)
        fout << departments[i];
    fout.close();
}
//Организовать интерфейс пользователя с программой в виде меню, позволяющего выполнять следующие действия:
//- чтение БД  «Солнечная система» из файла;
//- запись БД  «Солнечная система» в файл;
//- сортировка БД;
//- редактирование БД;
//- вывод БД на экран.

