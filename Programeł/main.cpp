#include <iostream>
#include "matrix.h"
#include "wektor.h"

using namespace std;

int main()
{
    cout << "TESTOWANIE KLASY WEKTOR\n" << endl;
    Wektor w1(3);
    Wektor w2(3);
    cout << "||Test przeciazenia operatorow strumienia ||\n";
    cout << "Podaj pierwszy wektor poziomy : ";
    cin >> w1;
    cout << "Podaj drugi wektor poziomy : ";
    cin >> w2;
    cout << "Przeciazenie operatora dodawania : " << w1+w2;
    cout << "Przeciazenie operatora odejmowania : " << w1-w2;
    cout << "Przeciazenie operatora mnozenia(dla skalarow) 5*w2: " << 5*w2;
    cout << "Przeciazenie operatora indeksowania : \n";
    for(int i=0;i<3;i++)
    {
        cout << "w["<< i << "] : " << w1[i] << endl;
    }
    cout << "Przeciazenie operatorow porownania : \nw1==w2 : " << (w1==w2) <<"\nw1==w1 : " << (w1==w1);
    cout << "\nw1!=w2 : " << (w1!=w2) << "\nw1!=w1 : " << (w1!=w1);
    cout << "\nPrzeciazenie operatora += : " <<(w1+=w2);
    cout << "Przeciazenie operatora -= : " <<(w1-=w2);
}
