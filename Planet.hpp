// Copyright 2021 qqq <polyakovdd@student.bmstu.ru>


#ifndef INC_2_LAB_PLANET_HPP
#define INC_2_LAB_PLANET_HPP

#define l_name 20

#include <cstring>
#include <iostream>

class Planet {
    char *Name;
    int Diameter;
    bool Life;
    int Satellite;

public:

    ~Planet();

    Planet(int len_name = l_name);

    Planet(char *name, int diameter, bool life, int satellite);

    char *GetName() {
        return Name;
    }

    int GetDiameter() {
        return Diameter;
    }

    bool GetLifeStatus() {
        return Life;
    }

    int GetSattelitesNumber() {
        return Satellite;
    };

    void SetName(char *);

    void SetDiameter(int);

    void SetLifeStatus(bool);

    void SetSattelitesNumber(int);

    void SetAllFields(char *, int, bool, int);

    void printInfo();

    Planet(const Planet &planet) {
        Name = new char[l_name];
        strcpy(Name, planet.Name);
        Diameter = planet.Diameter;
        Life = planet.Life;
        Satellite = planet.Satellite;
    }

    Planet &operator=(const Planet &planet) {
        delete[] Name;
        Name = new char[l_name];
        strcpy(Name, planet.Name);
        Diameter = planet.Diameter;
        Life = planet.Life;
        Satellite = planet.Satellite;

        return *this;
    }

    friend std::ostream &operator<<(std::ostream &, const Planet &);

    friend std::ofstream &operator<<(std::ofstream &, const Planet &);

    friend std::ifstream &operator>>(std::ifstream &, Planet &);

    friend bool operator<(const Planet&,const Planet&);

    friend bool operator==(const Planet&,const Planet&);
};


#endif //INC_2_LAB_PLANET_HPP
