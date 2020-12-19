//
// Created by danilapoddubny on 15/12/2020.
//

#ifndef LAB8_DRUG_H
#define LAB8_DRUG_H

#include <string>
#include <ostream>

class Drug {
public:
    Drug(const std::string &name, const std::string &country, int date, int rating, int sold);
    Drug();

    const std::string &getName() const;

    void setName(const std::string &name);

    const std::string &getCountry() const;

    void setCountry(const std::string &country);

    int getDate() const;

    void setDate(int date);

    int getRating() const;

    void setRating(int rating);

    int getSold() const;

    void setSold(int sold);

        bool operator!=(const Drug &rhs) const;

        friend bool operator==(const Drug &lhs, const Drug &rhs);

    friend bool operator<(const Drug &lhs, const Drug &rhs);

    friend bool operator>(const Drug &lhs, const Drug &rhs);

    friend bool operator<=(const Drug &lhs, const Drug &rhs);

    friend bool operator>=(const Drug &lhs, const Drug &rhs);

    friend std::ostream &operator<<(std::ostream &os, const Drug &drug);

    friend std::istream &operator>>(std::istream& in, Drug& drug);

private:
    std::string name;
    std::string country;
    int date;
    int rating;
    int sold;
};


#endif //LAB8_DRUG_H
