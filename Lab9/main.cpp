#include <iostream>
#include "Exception.h"
#include <set>
#include <fstream>
#include "Drug.h"
#include "setCalculator.h"

using namespace setCalculator;



/*
Контейнер: set(ключ - число, значение - объект).
Алгоритмы:
    1. Подсчет слов в строке, которые содержат все символы из указанного набора символов.




/*Общие требования к выполнению работы
    3. Реализовать алгоритм (алгоритм 1 в индивидуальном задании), который обрабатывает строки текстового файла согласно заданию, а результаты обработки помещает в строки другого текстового файла. Для хранения и обработки данных использовать контейнер библиотеки STL. На экран выводить отладочную информацию: какой файл открыт (или ошибка открытия файла), номер обработанной строки и результат ее обработки и т.п. 
    4. Любую работу с данными реализовывать через обработку исключительных ситуаций через try - catch и реализовать перегрузку операторов для контейнера и итератора.*/



int main(){
    Drug d1("Galoperidol", "Russia", 4, 10, 420);
    Drug d2("Penecilin", "England", 22, 6, 212);
    Drug d3("Analgin", "Spain", 18, 6, 233);
    Drug d4("Lithium", "France", 300, 8, 90);
    Drug d5("Simvastatin", "Germany", 210, 7, 123);

    Calculator drugSet;

    drugSet.push(d1);
    drugSet.push(d2);
    drugSet.push(d3);
    drugSet.push(d4);
    drugSet.push(d5);
    drugSet.push(d1);
    drugSet.view();

    std:: cout << "Amount of elements according to value: "<< drugSet.amount(setCalculator::Calculator::RATING, 6) << '\n';

    std::set<Drug> secretSet;
    Calculator::move(drugSet.getCustomSet(), secretSet);

    for(const auto &obj: secretSet){
        std::cout << obj << std::endl;
    }


    try
    {
        std::set<std::string> tmpSet;
        std::string line;

        std::ifstream in("text1.txt");
        if (in.is_open()) {
            while (getline(in, line)) {
                tmpSet.insert(line);
            }
        } else throw Exception("File not founded");

        in.close();

        std::ofstream out;
        out.open("text2.txt");
        if (out.is_open()) {
            for (const auto line : tmpSet) {
                out << line << std::endl;
            }
        }
        out.close();
    }catch(Exception err){
        std::cerr << err.getMessage();
    }



    return 0;
}