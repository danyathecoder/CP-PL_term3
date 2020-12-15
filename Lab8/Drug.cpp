//
// Created by danilapoddubny on 15/12/2020.
//

#include "Drug.h"
#include<iostream>

Drug::Drug(const std::string &name, const std::string &country, int date, int rating, int sold) : name(name),
                                                                                                  country(country),
                                                                                                  date(date),
                                                                                                  rating(rating),
                                                                                                  sold(sold) {}

Drug::Drug() : name("name"),
               country("country"),
               date(100),
               rating(10),
               sold(100) {}

const std::string &Drug::getName() const {
    return name;
}

void Drug::setName(const std::string &name) {
    Drug::name = name;
}

const std::string &Drug::getCountry() const {
    return country;
}

void Drug::setCountry(const std::string &country) {
    Drug::country = country;
}

int Drug::getDate() const {
    return date;
}

void Drug::setDate(int date) {
    Drug::date = date;
}

int Drug::getRating() const {
    return rating;
}

void Drug::setRating(int rating) {
    Drug::rating = rating;
}

int Drug::getSold() const {
    return sold;
}

void Drug::setSold(int sold) {
    Drug::sold = sold;
}

bool operator==(const Drug &lhs, const Drug &rhs) {
    return lhs.name == rhs.name &&
           lhs.country == rhs.country &&
           lhs.date == rhs.date &&
           lhs.rating == rhs.rating &&
           lhs.sold == rhs.sold;
}

bool operator<(const Drug &lhs, const Drug &rhs) {
    if (lhs.name < rhs.name)
        return true;
    if (rhs.name < lhs.name)
        return false;
    if (lhs.country < rhs.country)
        return true;
    if (rhs.country < lhs.country)
        return false;
    if (lhs.date < rhs.date)
        return true;
    if (rhs.date < lhs.date)
        return false;
    if (lhs.rating < rhs.rating)
        return true;
    if (rhs.rating < lhs.rating)
        return false;
    return lhs.sold < rhs.sold;
}

bool operator>(const Drug &lhs, const Drug &rhs) {
    return rhs < lhs;
}

bool operator<=(const Drug &lhs, const Drug &rhs) {
    return !(rhs < lhs);
}

bool operator>=(const Drug &lhs, const Drug &rhs) {
    return !(lhs < rhs);
}

std::ostream &operator<<(std::ostream &os, const Drug &drug) {
    os << "name: " << drug.name << " country: " << drug.country << " date: " << drug.date << " rating: " << drug.rating
       << " sold: " << drug.sold;
    return os;
}

std::istream& operator>>(std::istream& in, Drug& drug)
{
    in >> drug.name;
    in >> drug.country;
    in >> drug.date;
    in >> drug.rating;
    in >> drug.sold;
    return in;
}