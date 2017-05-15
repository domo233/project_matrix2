#include "wektor.h"

//////////////////K O N S T R U K T O R Y //////////////////////////
///////////////////////////////////////////////////////////////////

Wektor::Wektor(unsigned int rozmiar_)
{
    rozmiar=rozmiar_;
    tablica=new double [rozmiar];
    for(int i=0; i<(int)rozmiar; i++)
    {
        tablica[i]=0;
    }
}

Wektor::Wektor(const Wektor & obiekt)
{
    rozmiar=obiekt.rozmiar;
    tablica=new double [rozmiar];
    for(int i=0; i<(int)rozmiar; i++)
    {
        tablica[i]=obiekt.tablica[i];
    }
}

Wektor::~Wektor()
{
    delete [] tablica;
}

//////////////////O P E R A T O R Y ////////////////////////////////
///////////////////////////////////////////////////////////////////

Wektor Wektor::operator+(const Wektor & obiekt) const
{
    Wektor nowy(rozmiar);
    if(rozmiar==obiekt.rozmiar)
    {
        for(int i=0;i<(int)rozmiar;i++)
        {
            nowy.tablica[i]=tablica[i]+obiekt.tablica[i];
        }
        return nowy;
    }
    std::cout << "Nie mozna dodawac wektorow o roznym rozmiarze !" << std::endl;
    return Wektor(2);
}

Wektor Wektor::operator-(const Wektor & obiekt) const
{
    Wektor nowy(rozmiar);
    if(rozmiar==obiekt.rozmiar)
    {
        for(int i=0;i<(int)rozmiar;i++)
        {
            nowy.tablica[i]=tablica[i]-obiekt.tablica[i];
        }
        return nowy;
    }
    else
    {
        std::cout << "Nie mozna odejmowac wektorow o roznej wielkosci !" << std::endl;
        return Wektor(2);
    }
}

Wektor operator*(const double & mnoznik, const Wektor & obiekt)
{
    Wektor nowy(obiekt.rozmiar);
    for(int i=0;i<(int)obiekt.rozmiar;i++)
    {
        nowy.tablica[i]=mnoznik*obiekt.tablica[i];
    }
    return nowy;
}

Wektor operator*(const Wektor & obiekt, const double & mnoznik)
{
    return mnoznik*obiekt;
}


//////////////////P R Z Y P I S A N I E ////////////////////////////
///////////////////////////////////////////////////////////////////


Wektor & Wektor::operator=(const Wektor & obiekt)
{
    if(&obiekt==this) return *this;
    delete [] tablica;
    rozmiar=obiekt.rozmiar;
    tablica=new double[obiekt.rozmiar];
    for(int i=0;i<(int)obiekt.rozmiar;i++)
    {
        tablica[i]=obiekt.tablica[i];
    }
    return *this;
}


//////////////////S T R U M I E N I E //////////////////////////////
///////////////////////////////////////////////////////////////////


std::istream & operator>>(std::istream & os, Wektor & obiekt)
{
    for(int i=0;i<(int)obiekt.rozmiar;i++)
    {
        os >> obiekt.tablica[i];
    }
    return os;
}

std::ostream & operator<<(std::ostream & os,const Wektor & obiekt)
{
    os << "| ";
    for(int i=0;i<(int)obiekt.rozmiar;i++)
    {
        os << obiekt.tablica[i] << " ";
    }
    os <<"|"<<std::endl;
    return os;
}

//////////////////I N D E K S O W A N I E //////////////////////////
///////////////////////////////////////////////////////////////////


double & Wektor::operator[](int r)
{
    return tablica[r];
}













