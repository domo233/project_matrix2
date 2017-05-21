#include <iostream>
#include "matrix.h"

//metody

//konstruktor kopiuj¹cy

Matrix::Matrix(const Matrix & obiekt)
{
    col=obiekt.col;
    row=obiekt.row;
    wiersze = new Wektor*[row];
    for(int i=0; i<(int)row; i++)
    {
        wiersze[i] = new Wektor(col);
        *wiersze[i] = *obiekt.wiersze[i];
    }
}

//operator przypisania

Matrix & Matrix::operator=(const Matrix & obiekt)
{
    if(&obiekt==this) return *this;
    for(int i=0; i<row; i++)
    {
        delete wiersze[i];
    }
    delete [] wiersze;
    row=obiekt.row;
    col=obiekt.col;
    wiersze=new Wektor*[row];
    for(int i=0; i<(int)row; i++)
    {
        wiersze[i] = new Wektor(col);
        *wiersze[i] = *obiekt.wiersze[i];
    }
    return *this;
}
