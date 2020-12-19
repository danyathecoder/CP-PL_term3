//
// Created by danilapoddubny on 18/12/2020.
//

#ifndef LAB9_SETCALCULATOR_H
#define LAB9_SETCALCULATOR_H

namespace setCalculator{

class Calculator{
private:
    std::set<Drug> customSet;
public:
    enum fields{NAME, COUNTRY, DATE, RATING, SOLD};

    int amount(fields c, int number){
        int a = 0;
        switch (c) {
            case DATE:
                for(auto obj : customSet){
                    if(obj.getDate() == number)
                        a++;

                }
                break;

            case RATING:
                for(auto obj : customSet){
                    if(obj.getRating() == number)
                        a++;

                }
                break;

            case SOLD:
                for(auto obj : customSet){
                    if(obj.getSold() == number)
                        a++;

                }
                break;
        }
        return a;
    }

    int amount(fields c, std::string word){
        int a = 0;
        switch (c) {
            case NAME:
                for(auto obj : customSet){
                    if(obj.getName() == word)
                        a++;

                }
                break;
            case COUNTRY:
                for(auto obj : customSet){
                    if(obj.getCountry() == word)
                        a++;
                }
                break;
        }
        return a;
    }

    void push(Drug obj){
        customSet.insert(obj);
    }
    void destroy(Drug obj){
        customSet.erase(obj);
    }
    auto find(Drug obj){
        return customSet.find(obj);
    }
    void view(){
    for(auto i = customSet.begin(); i != customSet.end(); i++){
        std::cout << *i << '\n';
    }
    }

    static void move(const std::set<Drug> lhs, std::set<Drug> &rhs){
        for(auto obj: lhs){
            rhs.insert(obj);
        }
    }

    const std::set<Drug> &getCustomSet() const {
        return customSet;
    }
};
}


#endif //LAB9_SETCALCULATOR_H
