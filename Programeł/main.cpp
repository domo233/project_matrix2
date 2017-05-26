#include <iostream>
#include "matrix.h"
#include "algorithm.h"
#include <time.h>
#include <stdlib.h>

using namespace std;

int main()
{
    srand(time(NULL));
    Matrix m1(5,5,"rand");
    Matrix m2(5,5,"rand");
    cout << "TEST KLASY MATRIX\n\n";
    cout << "Tworze dwie tablice 5x5 i wypelniam je za pomoca rand()\n";
    cout << "m1 :\n" << m1;
    cout << "m2 :\n" << m2;
    cout << "Dodawanie : \n" << m1+m2;
    cout << "Odejmowanie : \n" << m1-m2;
    cout << "Mnozenie : \n" << m1*m2;

    return 0;
}
