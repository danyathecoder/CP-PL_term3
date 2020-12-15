//
// Created by danilapoddubny on 15/12/2020.
//

#include "File.h"
#include "Drug.h"
#include "StackContainer.h"

using namespace std;
int main()
{
    Drug d1("Galoperidol", "Russia", 4, 10, 420);
    Drug d2("Penecilin", "Russia", 22, 5, 212);
    Drug d3("Analgin:", "Russia", 18, 6, 233);
    Drug d4("Lithium", "Russia", 300, 8, 90);
    Drug d5("Simvastatin", "Russia", 210, 7, 123);
    Drug drugs[5] = { d1,d2,d3,d4,d5 };
    cout << "\n-------TXT in TXT mode-------\n";
    File f1("1.txt", txt);
    f1.open("w");
    f1.set_size(5);
    f1 << d1;
    f1 << d2;
    f1 << d3;
    f1 << d4;
    f1 << d5;
    f1.close();
    f1.open("r");
    cout << f1;
    f1.close();
    cout << "\n--------------------------------------------------------";
    cout << "\n-------TXT in BIN mode-------\n";
    File f2("2.txt", bin);
    f2.open("w");
    f2.set_size(5);
    f2 << d1;
    f2 << d2;
    f2 << d3;
    f2 << d4;
    f2 << d5;
    f2.close();
    f2.open("r");
    cout << f2;
    f2.close();
    cout << "\n--------------------------------------------------------";
    cout << "\n-------BIN in BIN mode-------\n";
    File f3("3.bin", bin);
    f3.open("w");
    f3.set_size(5);
    f3 << d1;
    f3 << d2;
    f3 << d3;
    f3 << d4;
    f3 << d5;
    f3.close();
    f3.open("r");
    cout << f3;
    f3.close();
    cout << "\n--------------------------------------------------------\n";

    int i = 0, line = 0;
    do {
        cout << "Enter the line that you want to change:" << endl;
        cin >> line;
        f2.edit(line, drugs);
        f2.open("r");
        cout << "\n--------------------------------------------------------\n";
        cout << f2;
        f2.close();
        cout << "Do you want to change anything else?\n1 - yes\n0 - no" << endl;
        rewind(stdin);
        cin >> i;
    } while (i);
    cout << "\n--------------------------------------------------------\n";
    cout << "Sort by name:" << endl;
    cout << "\n--------------------------------------------------------\n";
    f1.sortByName();
    f1.open("r");
    cout << f1;
    f1.close();
    cout << "\n--------------------------------------------------------\n";
    cout << "Sort by country:" << endl;
    cout << "\n--------------------------------------------------------\n";
    f1.sortByCountry();
    f1.open("r");
    cout << f1;
    f1.close();
    cout << "\n--------------------------------------------------------\n";
    cout << "Sort by rating:" << endl;
    cout << "\n--------------------------------------------------------\n";
    f1.sortByRating();
    f1.open("r");
    cout << f1;
    f1.close();
    cout << "\n--------------------------------------------------------\n";
    cout << "Sort by amount of sold:" << endl;
    cout << "\n--------------------------------------------------------\n";
    f1.sortBySold();
    f1.open("r");
    cout << f1;
    f1.close();

    StackContainer<Drug> stack;
    f1.open("r");
    Drug tmp;
    float sum = 0;
    int p[5];
    for (int i = 0; i < f1.get_size(); i++)
    {
        tmp = f1.read();
        sum += tmp.getRating();
        p[i] = tmp.getRating();
        stack.push(tmp);
    }
    stack.sort();
    stack.print();
    cout << "Chance of selling" << endl;
    for(int i = 0; i < 5; i++){
        cout << p[i]/sum * 100 << "% ";
    }

return 0;
}