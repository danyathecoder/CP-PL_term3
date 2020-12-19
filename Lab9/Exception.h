//
// Created by danilapoddubny on 16/12/2020.
//

#ifndef LAB8_EXCEPTION_H
#define LAB8_EXCEPTION_H

#include <string>

class Exception {
public:
    Exception(const std::string &message);

    const std::string &getMessage() const;

private:
    std::string message;

};


#endif //LAB8_EXCEPTION_H
