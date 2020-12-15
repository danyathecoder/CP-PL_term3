//
// Created by danilapoddubny on 11/09/2020.
//

#ifndef LAB2_TEACHER_H
#define LAB2_TEACHER_H

#include "Schoolkid.h"
#include <string>
using namespace std;


class Teacher {
private:
    string name;
    string salary;
public:
    Teacher();
    void setMissings(Schoolkid& obj, const int missings);
    friend void sayHelloToMyLittleFriend(const Teacher& obj);
};

void sayHelloToMyLittleFriend(const Teacher& obj);


#endif //LAB2_TEACHER_H
