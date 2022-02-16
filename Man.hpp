// Copyright 2021 qqq <polyakovdd@student.bmstu.ru>


#ifndef INC_2_LAB_MAN_HPP
#define INC_2_LAB_MAN_HPP

#define l_name  20

class Man {
    char *pName;
    int birth_year;
    float pay;
public:
    ~Man();

    Man(int len_name = l_name);    // конструктор
    Man(int len_name, char *name, int year, float salary);

    void SetName(char *);

    void SetBithYear(int);

    void SetPay(float);

    void SetAll(char*, int, float);

    char *GetName();

    int GetBirthYear();

    float GetPay();

};


#endif //INC_2_LAB_MAN_HPP
