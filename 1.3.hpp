// Copyright 2021 qqq <polyakovdd@student.bmstu.ru>


#ifndef INC_2_LAB_1_3_HPP
#define INC_2_LAB_1_3_HPP

#include <iostream>
#include <fstream>
#include <iomanip>
#include "Planet.hpp"

#define FILENAME "Platents_Database.qqq"
#define ARRAY_SIZE 12


void menu();

int readFile(Planet *, int &);

void addPlanet(Planet *, int &);

void deletePlanet(Planet *, int &);

void printPlanets(Planet *, const int);

void editPlanet(Planet *, const int);

void writeDB(Planet *, const int);

#endif //INC_2_LAB_1_3_HPP
