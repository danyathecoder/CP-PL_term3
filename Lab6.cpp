#include <iostream>

using namespace std;

//Функция для подсчета количества элементов удовлетворяющих определенному условию.

template<typename T>
int spec_counter(const T *arr, int size, T x){
    int counter = 0;
    for(int i = 0; i < size; i++){
        if(arr[i] == x)
            counter++;
    }
    return counter;
}

//явная спецификация

template<>
int spec_counter(const char *arr, int size, char x){
    int counter = 0;
    for(int i = 0; i < size; i++){
        if(arr[i] == x)
            counter++;
    }
    return counter;
}

int main() {
    char arr_char[] = {'a', 'b', 'c', 'd', 'a', 'f', 'g'};
    cout << spec_counter(arr_char, sizeof(arr_char)/sizeof(arr_char[0]), 'a') <<
    " elements found" << endl;

    int n = 0, x;
    cout << "Enter size of array:" << endl;
    cin >> n;
    int *arr_int = new int[n];
    cout << "Enter the values in array" << endl;
    for(int i = 0; i < n; i++){
        cin >> arr_int[i];
    }
    cout << "Value to find:" << endl;
    cin >> x;
    cout << spec_counter(arr_int, n, x);
    return 0;
}
