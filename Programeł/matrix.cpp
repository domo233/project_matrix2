#include "matrix.h"

//////////////////K O N S T R U K T O R Y //////////////////////////
///////////////////////////////////////////////////////////////////

Matrix::Matrix(unsigned int rows, unsigned int cols)
{
    row=rows;
    col=cols;
    wiersze = new Wektor*[row];
    for(int i=0; i<(int)row; i++)
    {
        wiersze[i] = new Wektor(col);
    }
}

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

Matrix::Matrix(std::string nazwa)
{
    using namespace std;
    int licz_sr=0;
    int licz_spac=0;
    int temp=0;
    for(int i=0;i<(int)nazwa.size();i++)
    {
        while((nazwa[i]!=';') && (i<(int)nazwa.size()))
        {
            if(nazwa[i]==' ') temp++;
            i++;
        }
        if(temp>licz_spac) licz_spac=temp;
        licz_sr++;
        temp=0;
    }
    row=licz_sr;
    col=licz_spac+1;
    wiersze = new Wektor*[row];
    for(int i=0; i<(int)row; i++)
    {
        wiersze[i] = new Wektor(col);
    }
    int k=0;
    for(int i=0;i<(int)nazwa.size();i++)
    {
        string temp2;
        while((nazwa[i]!=';') && (i<(int)nazwa.size()))
        {
            temp2+=nazwa[i];
            i++;
        }
        *wiersze[k] = Wektor(temp2);
        k++;
    }
}

Matrix::Matrix(unsigned int rows, unsigned int cols, std::string par)
{
    if(par == "rand")
    {
        row=rows;
        col=cols;
        wiersze = new Wektor*[row];
        for(int i=0; i<(int)row; i++)
        {
            wiersze[i] = new Wektor(col);
        }
        for(int i=0;i<(int)row; i++)
        {
            for(int j=0; j<(int)col; j++)
            {
                wiersze[i][0][j]=rand()%10;
            }
        }
    }
}

Matrix::~Matrix()
{
    for(int i=0; i<(int)row; i++)
    {
        delete wiersze[i];
    }
    delete [] wiersze;
}

//////////////////S T R U M I E N I E //////////////////////////////
///////////////////////////////////////////////////////////////////


std::istream & operator>>(std::istream & os, Matrix & obiekt)
{
    for(int i=0; i<(int)obiekt.col; i++)
    {
        os >> *obiekt.wiersze[i];
    }
    return os;
}

std::ostream & operator<<(std::ostream & os,const Matrix & obiekt)
{
    for(int i=0; i<(int)obiekt.row; i++)
    {
        os << *obiekt.wiersze[i];
    }
    return os;
}

//////////////////I N D E K S O W A N I E //////////////////////////
///////////////////////////////////////////////////////////////////


Wektor & Matrix::operator[](int rows)
{
    return *wiersze[rows];
}

//////////////////O P E R A T O R Y ////////////////////////////////
///////////////////////////////////////////////////////////////////


Matrix Matrix::operator+(const Matrix & obiekt) const
{
    Matrix nowy(row,col);
    if((obiekt.row==row) && (obiekt.col==col))
    {
        for(int i=0; i<(int)row; i++)
        {
            *nowy.wiersze[i]=(*obiekt.wiersze[i])+(*wiersze[i]);
        }
        return nowy;
    }
    else
    {
        return Matrix(2,2);
    }
}

Matrix Matrix::operator-(const Matrix & obiekt) const
{
    Matrix nowy(row,col);
    if((obiekt.row==row) && (obiekt.col==col))
    {
        for(int i=0; i<(int)row; i++)
        {
            *nowy.wiersze[i]=(*wiersze[i])-(*obiekt.wiersze[i]);
        }
        return nowy;
    }
    else
    {
        return Matrix(2,2);
    }
}

Matrix operator*(const item & mnoznik, const Matrix & obiekt)
{
    Matrix nowy(obiekt.row,obiekt.col);
    for(int i=0; i<(int)obiekt.row; i++)
    {
        *nowy.wiersze[i]=mnoznik*(*obiekt.wiersze[i]);
    }
    return nowy;
}

Matrix operator*(const Matrix & obiekt, const item & mnoznik)
{
    return mnoznik*obiekt;
}

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

//////////////////P R Z Y P I S A N I E ////////////////////////////
///////////////////////////////////////////////////////////////////


Matrix & Matrix::operator=(const Matrix & obiekt)
{
    if(&obiekt==this) return *this;
    for(int i=0; i<(int)row; i++)
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


//////////////////M E T O D Y //////////////////////////////////////
///////////////////////////////////////////////////////////////////


Matrix potega(Matrix & obiekt, int n)
{
    Matrix temp=obiekt;
    for(int i=1; i<n; i++)
    {
        temp=temp*obiekt;
    }
    return temp;
}

void Matrix::func(void (*p)(item & w))
{
    for(int i=0;i<(int)row; i++)
    {
        for(int j=0; j<(int)col; j++)
        {
            p(wiersze[i][0][j]);
        }
    }
}























