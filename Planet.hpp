// Copyright 2021 qqq <polyakovdd@student.bmstu.ru>


#ifndef INC_2_LAB_PLANET_HPP
#define INC_2_LAB_PLANET_HPP

#define l_name 20

class Planet {
    char *Name;
    int Diameter;
    bool Life;
    int Satellite;

public:
    ~Planet() {
        delete[] Name;
    }

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
};


#endif //INC_2_LAB_PLANET_HPP
