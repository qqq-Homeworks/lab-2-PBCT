// Copyright 2021 qqq <polyakovdd@student.bmstu.ru>


#include "Planet.hpp"
#include <iostream>


void Planet::printInfo() {
    std::cout << "Планета " << Name << ":\n";
    std::cout << "Диаметр: " << Diameter << '\n';
    std::cout << "Наличие жизни: " << std::boolalpha << Life << '\n';
    std::cout << "Количество спутников: " << Satellite << '\n';
}

Planet::Planet(int len_name) {
    Name = new char[len_name];
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