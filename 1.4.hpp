// Copyright 2021 qqq <polyakovdd@student.bmstu.ru>


#ifndef INC_2_LAB_1_4_HPP
#define INC_2_LAB_1_4_HPP

#include <iomanip>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <cstring>
#include "Department.hpp"


#define ARRAY_SIZE 24
#define FILENAME "Departments.qqq"

void menu();

int readFile(Department *, int &);

void addDepartment(Department *, int &);

void deleteDepartment(Department *, int &);

void printDepartments(Department *, const int);

void editDepartment(Department *, const int);

void writeDB(Department *, const int);

#endif //INC_2_LAB_1_4_HPP
