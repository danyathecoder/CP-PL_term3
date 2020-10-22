//
// Created by danilapoddubny on 11/09/2020.
//

#ifndef LAB2_SCHOOLKID_H
#define LAB2_SCHOOLKID_H

#include <string>
using namespace std;

class Schoolkid {
private:
    int id;
    int missed;
    string name;
public:
    Schoolkid(const string& new_name, const int& new_id, const int& new_missed);
    Schoolkid();
    ~Schoolkid();
    friend void printData(const Schoolkid& obj);
    friend class Teacher;
    void changeName(const string& new_name);
    void changeID(const int& n);
};

void printData(const Schoolkid& obj);


#endif //LAB2_SCHOOLKID_H
