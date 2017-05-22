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

// algorytm mnożący

Matrix operator*(Matrix & obiekt1,Matrix & obiekt2)
{
    Matrix nowy(obiekt1.row,obiekt2.col);
    if(obiekt1.col==obiekt2.row)
    {
        for(int i=0; i<(int)obiekt1.row; i++)
        {
            for(int j=0; j<(int)obiekt2.col; j++)
            {
                item wynik=0;
                for(int k=0; k<(int)obiekt1.col; k++)
                {
                    wynik+=obiekt1[i][k]*obiekt2[k][j];
                }
                nowy[i][j]=wynik;
            }
        }
        return nowy;
    }
    else
    {
        return Matrix(2,2);
    }
}
