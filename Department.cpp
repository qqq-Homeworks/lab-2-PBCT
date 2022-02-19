// Copyright 2021 qqq <polyakovdd@student.bmstu.ru>

#include "Department.hpp"

Department::~Department() {
    delete[] Name;
}

Department::Department() {
    Name = nullptr;
}

char *Department::GetName() {
    return Name;
}

size_t Department::GetStudentsCount() {
    return StudentsCount;
}

size_t Department::GetScore() {
    return MinimalPassingScore;
}

void Department::SetName(const char *name) {
    Name = new char[strlen(name) + 1];
    strcpy(Name,name);
}

void Department::SetStudentsCount(const size_t count) {
    StudentsCount = count;
}

void Department::SetMinimalScore(const size_t score) {
    MinimalPassingScore = score;
}

Department::Department(const Department &department) {
    Name = new char[strlen(department.Name) + 1];
    strcpy(Name, department.Name);
    StudentsCount = department.StudentsCount;
    MinimalPassingScore = department.MinimalPassingScore;
}

std::ostream &operator<<(std::ostream &out, const Department &department) {
    out << department.Name << std::setw(22 - strlen(department.Name) + 6) << department.StudentsCount << std::setw(26)
        << department.MinimalPassingScore
        << '\n';
    return out;
}

std::ofstream &operator<<(std::ofstream &fout, const Department &department) {
    fout << department.Name << ' ' << department.StudentsCount << ' ' << department.MinimalPassingScore << '\n';
    return fout;
}

std::ifstream &operator>>(std::ifstream &fin, Department &department) {
    char *name = new char[30];
    fin >> name >> department.StudentsCount >> department.MinimalPassingScore;
    department.SetName(name);
    return fin;
}

bool operator<(const Department &department1, const Department &department2) {
    return department1.MinimalPassingScore > department2.MinimalPassingScore;
}

bool operator==(const Department &department1, const Department &department2) {
    return ((strcmp(department1.Name, department2.Name) == 0) &&
            department1.MinimalPassingScore == department2.MinimalPassingScore &&
            department1.StudentsCount == department2.StudentsCount);
}



