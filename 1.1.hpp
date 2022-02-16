// Copyright 2021 qqq <polyakovdd@student.bmstu.ru>


#ifndef INC_2_LAB_1_1_HPP
#define INC_2_LAB_1_1_HPP

#include <iostream>
#include <iomanip>
#include <fstream>
#include "Man.hpp"

using namespace std;



int  menu();
int menu_f();
void print_dbase(Man *arr, int n);
int write_dbase(char *filename, Man *arr, int n);
int read_dbase(char *filename, Man *arr, int &n);
int find(Man* arr,int n, char* name);
int find(Man* arr,int n, int birth_year);
int find(Man* arr,int n, float pay);
void find_man(Man* arr,int n);
void add(Man* arr, int& n);
void edit(Man* arr, int n);
void remove(Man* arr, int& n);

#endif //INC_2_LAB_1_1_HPP
