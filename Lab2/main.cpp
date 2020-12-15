//v7
/*
Общие требования к выполнению работы
+    1. Создать проект консольной программы.
+    2. Создать базовый класс согласно заданию. Все данные класса описать в закрытой секции, все методы класса реализовать как открытые.
        Создать конструктор по умолчанию и конструктор инициализации. Создать деструктор.
+    3. Вне класса должна быть создана дружественная функция, предназначенная для вывода данных объекта на экран.
+    4. Для задания значений уникальных номеров использовать или статические члены класса или особую инициализацию членов класса.
+    5. Установка значений переменных должна иметь проверку на реальный диапазон значений.
+    6. В головной функции создать несколько одиночных экземпляров базового класса.
+        Обработать все экземпляры базового класса с помощью заданного метода дружественного класса.
        Вывести содержимое переменных экземпляров классов на экран до и после этой обработки.
+    7. В головной функции создать массив экземпляров базового класса. Обработать все элементы массива с помощью заданного метода дружественного класса.
        Вывести содержимое переменных элементов массива на экран до и после этой обработки.

Создать класс «Школьник» со следующими данными: id – уникальный номер, name – ФИО, missed – количество пропущенных занятий.
Создать дружественный класс «Учитель», в которо реализовать метод установки количества пропущенных занятий.

*/

#include <iostream>
#include <iomanip>
#include "Schoolkid.h"
#include "Teacher.h"


using namespace std;

int main() {
    string name;
    int id, missings;
    bool check = true;

    Teacher MariaIvanovna;
    sayHelloToMyLittleFriend(MariaIvanovna);

    cout << "Name:" << setw(50) << "ID: " << setw(50) <<"Missed lessons: " << endl;

    Schoolkid obj1;
    printData(obj1);
    MariaIvanovna.setMissings(obj1, rand());
    printData(obj1);


    Schoolkid obj2 {"Pupkin" , 228, 5000};
    printData(obj2);
    MariaIvanovna.setMissings(obj2, rand());
    printData(obj2);

    Schoolkid obj3;
    cout << endl << "Enter name of third student: "<< endl;
    cin >> name;
    obj3.changeName(name);
    do{
        cout << "Enter the ID: ";
        cin >> id;
        cout << "Enter the missings: ";
        cin >> missings;
        if(missings >= 0 && id >= 0){
            check = false;
        }else cout << "Try again." << endl;
    }while(check);

    cout << "Name:" << setw(50) << "ID: " << setw(50) <<"Missed lessons: " << endl;
    obj3.changeID(id);
    printData(obj3);
    MariaIvanovna.setMissings(obj3, missings);
    printData(obj3);

    Schoolkid horde[3];
    string names[3] = {"Erich", "Maria", "Remarque"};
    missings = 1916;
    for(int i = 0; i < 3; i++){
        horde[i].changeName(names[i]);
        horde[i].changeID(1898 + rand() % 20);
        printData(horde[i]);
        MariaIvanovna.setMissings(horde[i], missings + rand() % 20);
        printData(horde[i]);
    }
    return 0;
}
