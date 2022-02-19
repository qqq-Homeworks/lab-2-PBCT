// Copyright 2021 qqq <polyakovdd@student.bmstu.ru>


#include "Planet.hpp"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>

void Planet::printInfo() {
    std::cout << "Планета " << Name << ":\n";
    std::cout << "Диаметр: " << Diameter << '\n';
    std::cout << "Наличие жизни: " << std::boolalpha << Life << '\n';
    std::cout << "Количество спутников: " << Satellite << '\n';
}

Planet::~Planet() {
    delete[] Name;
    std::cout << "deleted planet\n";
}

Planet::Planet(int len_name) {
    Name = new char[len_name];
    std::cout << "created planet\n";
}

Planet::Planet(char *name, int diameter, bool life, int satellite) {
    Name = new char[l_name];
    Name = name;
    Diameter = diameter;
    Life = life;
    Satellite = satellite;
}


void Planet::SetName(char *name) {
    Name = name;
}

void Planet::SetDiameter(int diameter) {
    Diameter = diameter;
}

void Planet::SetLifeStatus(bool lifeStatus) {
    Life = lifeStatus;
}

void Planet::SetSattelitesNumber(int sattelitesNumber) {
    Satellite = sattelitesNumber;
}

void Planet::SetAllFields(char *name, int diameter, bool lifeStatus, int sattelitesNumber) {
    Name = name;
    Diameter = diameter;
    Life = lifeStatus;
    Satellite = sattelitesNumber;
}

std::ostream &operator<<(std::ostream &out, const Planet &planet) {
    out << planet.Name << std::setw(20 - strlen(planet.Name) + 6) << planet.Diameter << std::setw(10) << planet.Life
        << "   " << planet.Satellite << '\n';
    return out;
}

std::ofstream &operator<<(std::ofstream &fout, const Planet &planet) {
    fout << planet.Name << ' ' << planet.Diameter << ' ' << planet.Life
         << ' ' << planet.Satellite << '\n';
    return fout;
}

std::ifstream &operator>>(std::ifstream &fin, Planet &planet) {
    fin >> planet.Name >> planet.Diameter >> planet.Life >> planet.Satellite;
    return fin;
}

bool operator<(const Planet &planet1, const Planet &planet2) {
    bool result = false;
    strcmp(planet1.Name, planet2.Name) >= 0 ? result = false : result = true;
    return result;
}

bool operator==(const Planet &planet1, const Planet &planet2) {
    bool isNamesEqual = false;
    strcmp(planet1.Name, planet2.Name) == 0 ? isNamesEqual = true : isNamesEqual = false;
    return (isNamesEqual && planet1.Life == planet2.Life && planet1.Satellite == planet2.Satellite &&
            planet1.Diameter == planet2.Diameter);
}

