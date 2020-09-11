#include <cmath>
#include <iostream>

using namespace std;

int main(){
    double a, b, c;
    cin >> a >> b >> c;
    cout.precision(2);
    if(a < 0){
        a = (-1)*a;
        b = (-1)*b;
        c = (-1)*c;
    }
    if(a == 0 && b == 0)
        return 0;
    if(a == 0){
        cout << (-1.0)*c/b;
        return 0;
}
    int D = b*b - 4*a*c;
    if(D < 0)
        return 0;
    if(D == 0) 
        cout << ((-1)*b)/(2*a);
    if(D > 0)
        cout << ((-1)*b + sqrt(D)) / (2*a)<<" "<< ((-1)*b - sqrt(D)) / (2*a);
    return 0;
}