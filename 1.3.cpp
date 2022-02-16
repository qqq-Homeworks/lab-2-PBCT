// Copyright 2021 qqq <polyakovdd@student.bmstu.ru>

#include "1.3.hpp"

int main() {
    menu();

    return 0;
}

void menu() {
    std::cout << " ============== ГЛАВНОЕ МЕНЮ ========================\n";
    std::cout << "l - добавление планеты\t 3 - редактирование сведений" << '\n';
    std::cout << "2 - удаление планеты\t 4 - вывод базы на экран" << '\n';
    std::cout << "\t\t 5 - сохранение базы в файл" << '\n';
    std::cout << "\t\t\t 6 - выход" << '\n';
    std::cout << "Для выбора операции введите цифру от 1 до 6" << '\n';

    int menuPoint = 0;
    int n = 0;
    Planet planets[ARRAY_SIZE];
    readFile(planets, n);
    do {
        std::cin >> menuPoint;
        switch (menuPoint) {
            case 1:
                addPlanet(planets, n);
                break;
            case 2:
                deletePlanet(planets, n);
                break;
            case 3:
                editPlanet(planets, n);
                break;
            case 4:
                printPlanets(planets, n);
                break;
            case 5:

            case 6:
                return;
            default:
                return;
        }
    } while (menuPoint != 6);

}

int readFile(Planet *arr, int &n) {
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
    int sattelites, diameter;
    bool life;
    for (int i = 0; i < n; i++) {
        char *name = new char[20];
        fin >> name >> diameter >> life >> sattelites;
        arr[i].SetAllFields(name, diameter, life, sattelites);
    }
    fin.close();
    return 0;
}

void addPlanet(Planet *planets, int &n) {
    char *name = new char[20];
    int sattelites, diameter;
    bool life;
    std::cout << "Введите имя планеты:\n";
    std::cin >> name;
    std::cout << "Введите диаметр:\n";
    std::cin >> diameter;
    std::cout << "Введите статус жизни:\n";
    std::cin >> life;
    std::cout << "Введите количество спутников:\n";
    std::cin >> sattelites;
    planets[n].SetAllFields(name, diameter, life, sattelites);
    n++;
}

void printPlanets(Planet *planets, const int n) {
    std::cout << " Список планет: " << '\n';
    for (int i = 0; i < n; i++)
        std::cout << std::setw(3) << i + 1 << ". " << planets[i].GetName()
                  << std::setw(20 - strlen(planets[i].GetName()) + 6)
                  << planets[i].GetDiameter() << std::setw(10) << planets[i].GetLifeStatus() << "   "
                  << planets[i].GetSattelitesNumber() << '\n';
}

void deletePlanet(Planet *planets, int &n) {
    printPlanets(planets, n);
    std::cout << "Выберите номер планеты, которую хотите удалить\n";
    int i = 0;
    std::cin >> i;
    i--;
    n--;
    for (size_t j = i; j < n; ++j) {
        planets[j] = planets[j + 1];
    }
}

void editPlanet(Planet *planets, const int n) {
    printPlanets(planets, n);
    std::cout << "Выберите номер планеты, которую хотите изменить\n";
    int i = 0;
    std::cin >> i;
    i--;
    char *name = new char[20];
    int sattelites, diameter;
    bool life;
    std::cout << "Введите новое имя планеты:\n";
    std::cin >> name;
    std::cout << "Введите новый диаметр:\n";
    std::cin >> diameter;
    std::cout << "Введите новый статус жизни:\n";
    std::cin >> life;
    std::cout << "Введите новое количество спутников:\n";
    std::cin >> sattelites;
    planets[i].SetAllFields(name, diameter, life, sattelites);
}

void writeDB(Planet *planets, const int n) {
    std::ofstream fout(FILENAME, std::ios::out);
    if (!fout) {
        std::cout << "Ошибка открытия файла" << std::endl;
        return;
    }
    fout << n;
    for (int i = 0; i < n; i++)
        fout << planets[i].GetName() << ' ' << planets[i].GetDiameter() << ' ' << planets[i].GetLifeStatus()
             << ' ' << planets[i].GetSattelitesNumber() << '\n';
    fout.close();
}
//Организовать интерфейс пользователя с программой в виде меню, позволяющего выполнять следующие действия:
//- чтение БД  «Солнечная система» из файла;
//- запись БД  «Солнечная система» в файл;
//- сортировка БД;
//- редактирование БД;
//- вывод БД на экран.

