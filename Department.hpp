// Copyright 2021 qqq <polyakovdd@student.bmstu.ru>


#ifndef INC_2_LAB_DEPARTMENT_HPP
#define INC_2_LAB_DEPARTMENT_HPP

#include <cstring>
#include <fstream>

class Department {
    char *Name;
    size_t StudentsCount;
    size_t MinimalPassingScore;

public:
    ~Department();

    Department();

    char *GetName();

    size_t GetStudentsCount();

    size_t GetScore();

    void SetName(const char *);

    void SetStudentsCount(const size_t);

    void SetMinimalScore(const size_t);

    Department(const Department &);

    Department &operator=(const Department &department) {
        delete[] Name;
        Name = new char[strlen(department.Name) + 1];
        strcpy(Name, department.Name);
        StudentsCount = department.StudentsCount;
        MinimalPassingScore = department.MinimalPassingScore;

        return *this;
    }

    friend std::ostream &operator<<(std::ostream &, const Department &);

    friend std::ofstream &operator<<(std::ofstream &, const Department &);

    friend std::ifstream &operator>>(std::ifstream &, Department &);

    friend bool operator<(const Department&,const Department&);

    friend bool operator==(const Department&,const Department&);
};


#endif //INC_2_LAB_DEPARTMENT_HPP
