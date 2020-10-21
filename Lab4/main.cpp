#include <iostream>

using namespace std;

class Coach {
private:
    float experience;
public:
    Coach(float experience) : experience(experience) {}

    float getExperience() const {
        return experience;
    }

    void setExperience(float experience) {
        Coach::experience = experience;
    }

    void printCoach(){
        cout << "Coach: " << "exp - " <<this->experience << endl;
    }
};

class Libero : public Coach{
private:
    int attack;
public:
    Libero(float experience, int attack) : Coach(experience), attack(attack) {}

    int getAttack() const {
        return attack;
    }

    void setAttack(int attack) {
        Libero::attack = attack;
    }

    virtual ~Libero() {

    }

    void printLibero(){
        cout << "Libero: " << "exp - " << this->getExperience() << "attack - " << this->getAttack() << endl;
    }
};

class Central : public Coach {
private:
    int agility;
public:
    Central(float experience, int agility) : Coach(experience), agility(agility) {}

    int getAgility() const {
        return agility;
    }

    void setAgility(int agility) {
        Central::agility = agility;
    }

    virtual ~Central() {

    }

    void printCental(){
        cout << "Central: " << "exp - " << this->getExperience() << "agility - " << this->getAgility() << endl;
    }
};

class Blocker : public Central{
private:
    int protect;
public:
    Blocker(float experience, int agility, int protect) : Central(experience, agility), protect(protect) {}

    int getProtect() const {
        return protect;
    }

    void setProtect(int protect) {
        Blocker::protect = protect;
    }

    virtual ~Blocker() {

    }

    void printBlocker(){
        cout << "Blocker: " << "exp - " << this->getExperience() << "agility - " << this->getAgility() << " protection - " << this->getProtect() << endl;
    }

};

class Binder : public Libero{
private:
    int bindingValue;
public:
    Binder(float experience, int attack, int bindingValue) : Libero(experience, attack), bindingValue(bindingValue) {}

    int getBindingValue() const {
        return bindingValue;
    }

    void setBindingValue(int bindingValue) {
        Binder::bindingValue = bindingValue;
    }

    virtual ~Binder() {

    }

    void printBinder(){
        cout << "Binder: " << "exp - " << this->getExperience() << "attack - " << this->getAttack() << " bindingValue - "<< this->getBindingValue() << endl;
    }
};

class Junior : public Binder, public Blocker{
private:
    int age;
public:
    Junior(float experience, int attack, int bindingValue, float experience1, int agility, int protect, int age)
            : Binder(experience, attack, bindingValue), Blocker(experience1, agility, protect), age(age) {}

    int getAge() const {
        return age;
    }

    void setAge(int age) {
        Junior::age = age;
    }

    virtual ~Junior() {

    }

    void printJunior(){
        cout << "Junior: " << "experience - " << this->Binder::getExperience() << " attack - " << this->getAttack() << " binding value - "
        << this->getBindingValue() <<  " protection - " << this->getProtect() << " agility - " << getAgility() << " age - " << this->getAge() << endl;
    }
};

int main()
{
/*1. По полученному базовому классу создать классы наследников по двум разным ветвям наследования (B←P1←P11 и B←P2←P21):
    + a) во всех классах должны быть свои данные (характеристики объектов), расположенные в private или protected секциях;
    + b) во всех классах создать конструкторы инициализации объектов для всех классов (не забыть про передачу параметров в конструкции базовых классов);
    + c) во всех классах создать деструкторы;
    + d) во всех классах создать метод вывода объекта на экран (всех его параметров);
    + e) остальные методы создавать по необходимости.
    + 2. Создать класс с множественным наследованием (P11 ← P3 → P21). Создать в этом классе выше описанные функции (в коде функций не использовать доступ к данным через оператор разрешения зоны видимости ::). Наследование выглядит следующим образом: базовый имеет два наследника, каждый из которых имеет по одному наследнику, в свою очередь у этих наследников есть единый т. е. получается "кольцо"

    3. В головной функции создать экземпляр класса P3. Вывести содержимое экземпляра класса P3 на экран. Проверить, что получится, если не будет использовано виртуальное наследование.
    4. Все возможные данные вводятся с клавиатуры с проверкой на корректность. Данные для объектов вводятся в main и передаются в объекты классов через конструкторы. Память выделять динамически.*/

Junior boy(1, 2, 3, 4, 5, 6, 7);
boy.printJunior();
    return 0;
}
