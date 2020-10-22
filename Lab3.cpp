#include <iostream>
#include <string>

using namespace std;

class CharMatrix{
private:
    char **arr;
    int n, m;
public:
    CharMatrix(){
        arr = new char* [1];
        arr[0] = new char [1];
    }
    CharMatrix(const int& x, const int& y){
        n = x;
        m = y;
        arr = new char* [n];
        for(int i = 0; i < n; i++){
            arr[i] = new char [m];
        }
    }
    CharMatrix(const CharMatrix &obj){
        n = obj.n;
        m = obj.m;
        arr = new char* [n];
        for(int i = 0; i < n; i++){
            arr[i] = new char [m];
            for(int j = 0; j < m; j++){
                this -> setChar(i, j, obj.arr[i][j]);
            }
        }
    }
    ~CharMatrix(){
        delete[] arr;
    }
    char getChar(int i, int j){
        return this -> arr[i][j];
    }
    void setChar(int i, int j, char c){
         this -> arr[i][j] = c;
    }
    bool operator<(const CharMatrix &obj){
        if(arr[0][0] >= obj.arr[0][0]) return true;
        else return false;
    }
    bool operator>(const CharMatrix &obj){
        if(this -> arr[0][0] <= obj.arr[0][0]) return true;
        else return false;
    }
    friend ostream& operator<<(ost ream &stream, const CharMatrix &obj);
};


ostream& operator<<(ostream &stream, const CharMatrix &obj) {
    for (int i = 0; i < obj.n; i++){
        for (int j = 0; j < obj.m; j++) {
            stream << obj.arr[i][j] << " ";
        }
        stream << endl;
    }
    return stream;
}

int main() {
    srand(time(0));
    CharMatrix mtx(3, 3);
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
            mtx.setChar(i, j, char(98 + rand() % 20 ));
    CharMatrix test(mtx);
    cout << mtx;
    test.setChar(0, 0, 'a');
    cout << test;
    bool flag = mtx > test;
    if(flag){
        cout << "Right matrix bigger than left" << endl;
    }else cout << "Left matrix bigger than right" << endl;
    flag = mtx < test;
    CharMatrix *arr = new CharMatrix [2];
    for(int i = 0; i < 2; i++){
        arr[i].setChar(0, 0, 'A');
        cout << arr[i];
    }
    delete [] arr;
    return 0;
}
