// Copyright 2021 qqq <polyakovdd@student.bmstu.ru>


#include "Man.hpp"


Man::~Man() {
    delete[] pName;
}

Man::Man(int len_name) {
    pName = new char[len_name];
}

Man::Man(int len_name, char *name, int year, float salary ) {
    pName = new char[len_name];
    pName = name;
    birth_year = year;
    pay = salary;
}

void Man::SetName(char *name) {
    pName = name;
}

void Man::SetPay(float salary) {
    pay = salary;
}

void Man::SetBithYear(int year) {
    birth_year = year;
}
void Man::SetAll(char* name, int year, float salary)
{
    pName = name;
    pay = salary;
    birth_year = year;
}

char *Man::GetName() {
    return pName;
}

int Man::GetBirthYear() {
    return birth_year;
}

float Man::GetPay() {
    return pay;
}

