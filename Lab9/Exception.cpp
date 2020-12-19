//
// Created by danilapoddubny on 16/12/2020.
//

#include "Exception.h"

const std::string &Exception::getMessage() const {
    return message;
}

Exception::Exception(const std::string &message) : message(message) {}
