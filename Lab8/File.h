//
// Created by danilapoddubny on 15/12/2020.
//

#ifndef LAB8_FILE_H
#define LAB8_FILE_H


#include<iostream>
#include<fstream>
#include<string>
#include "Drug.h"


using namespace std;

enum Key{ no = 0,txt,bin};

class File
{
private:
    fstream file;
    string name;
    Key key;
    int size;
public:
    File();
    File(string, Key);
    ~File();
    void open(string);
    void close();
    void begin();
    void set_size(int);
    int get_size();
    Drug read();
    void edit(int, Drug[]);
    void sortByName();
    void sortByDate();
    void sortByCountry();
    void sortByRating();
    void sortBySold();
    friend File& operator<<(File&, const char* );
    friend ostream& operator<<(ostream&, File&);
    friend File& operator<<(File&, Drug& );
};

#endif //LAB8_FILE_H
