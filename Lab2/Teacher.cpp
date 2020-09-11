//
// Created by danilapoddubny on 11/09/2020.
//

#include "Teacher.h"
#include <iostream>

Teacher::Teacher() {
    name = "Maria Ivanovna";
    salary = "too low";
}

void Teacher::setMissings(Schoolkid &obj, const int missings) {
    obj.missed = missings;
}

void sayHelloToMyLittleFriend(const Teacher& obj){
    cout << "https://www.youtube.com/watch?v=AVQ8byG2mY8&ab_channel=Godlike"<< endl <<
         "Hi, children. My name is " << obj.name <<
         "And my salary is " << obj.salary << " to listen you." << endl;
}