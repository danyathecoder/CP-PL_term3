//
// Created by danilapoddubny on 11/09/2020.
//

#include "Schoolkid.h"
#include <iostream>
#include <iomanip>

Schoolkid::Schoolkid(const string &new_name, const int &new_id, const int &new_missed) {
    id = new_id;
    missed = new_missed;
    name = new_name;
}

Schoolkid::Schoolkid() {
    id = 42;
    missed = 0;
    name = "John Doe";
}

Schoolkid::~Schoolkid() {
    cout << "Goodbye, " << name << "."<< endl;
}

void Schoolkid::changeName(const string &new_name) {
    name = new_name;
}

void Schoolkid::changeID(const int &n) {
    id = n;
}

void printData(const Schoolkid& obj){
    cout << obj.name;
    cout << setw(53) << obj.id;
    cout << setw(40) << obj.missed << endl;
}