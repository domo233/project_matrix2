#include "wektor.h"


// Interfejs klasy Wektor: konstruktory, przeci??anie, indeksowanie
// Wektor class interface: constructors, overloaded operators and indexing methods



//////////////////K O N S T R U K T O R Y //////////////////////////
///////////////////////////////////////////////////////////////////

Wektor::Wektor(unsigned int rozmiar_)
{
    rozmiar=rozmiar_;
    tablica=new item [rozmiar];
    for(int i=0; i<(int)rozmiar; i++)
    {
        tablica[i]=0;
    }
}

Wektor::Wektor(const Wektor & obiekt)
{
    rozmiar=obiekt.rozmiar;
    tablica=new item [rozmiar];
    for(int i=0; i<(int)rozmiar; i++)
    {
        tablica[i]=obiekt.tablica[i];
    }
}

Wektor::Wektor(std::string name)
{
    using namespace std;
    int licz=0;
    for(int j = 0; j<(int)name.size(); j++)
    {
        if(name[j]==' ') licz++;
    }
    rozmiar=licz+1;
    tablica=new item [rozmiar];
    int k = 0;
    for(int i=0; i<(int)name.size(); i++)
    {
        int zmienna=0;
        bool znak=1;
        while((name[i]!=' ')&&(i<(int)name.size()))
        {
            switch(name[i])
            {
            case '1':
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7':
            case '8':
            case '9':
            case '0':
                zmienna=(int)name[i]+zmienna*10-48;
                break;
            case '-':
                znak=0;
                break;
            default:
                break;
            }
            i++;
        }
        zmienna=(znak ? zmienna : -zmienna);
        tablica[k]=zmienna;
        k++;
    }
    /*
    while(name[i]!='\0')
    {
        bool znak;
        if(name[i]=='-')
        {
            znak=0;
            i++;
        }
        else znak=1;
        int zmienna=0;
        while((name[i]!=' ') && (name[i]!='\0'))
        {
            zmienna=(int)name[i]+zmienna*10-48;
            i++;
        }
        zmienna=(znak ? zmienna : -zmienna);
        tablica[k]=zmienna;
        k++;
        if(name[i]==' ') i++;
    }
    */
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
        for(int i=0; i<(int)rozmiar; i++)
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
        for(int i=0; i<(int)rozmiar; i++)
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

Wektor operator*(const item & mnoznik, const Wektor & obiekt)
{
    Wektor nowy(obiekt.rozmiar);
    for(int i=0; i<(int)obiekt.rozmiar; i++)
    {
        nowy.tablica[i]=mnoznik*obiekt.tablica[i];
    }
    return nowy;
}

Wektor operator*(const Wektor & obiekt, const item & mnoznik)
{
    return mnoznik*obiekt;
}

bool Wektor::operator==(const Wektor & obiekt) const
{
    if(rozmiar==obiekt.rozmiar)
    {
        for(int i=0; i<(int)rozmiar; i++)
        {
            if(tablica[i]!=obiekt[i]) return 0;
        }
        return 1;
    }
    else return 0;
}

bool Wektor::operator!=(const Wektor & obiekt) const
{
    return !((*this)==obiekt);
}

Wektor & Wektor::operator+=(const Wektor & obiekt)
{
    *this=*this+obiekt;
    return *this;
}

Wektor & Wektor::operator-=(const Wektor & obiekt)
{
    *this=*this-obiekt;
    return *this;
}

//////////////////P R Z Y P I S A N I E ////////////////////////////
///////////////////////////////////////////////////////////////////


Wektor & Wektor::operator=(const Wektor & obiekt)
{
    if(&obiekt==this) return *this;
    delete [] tablica;
    rozmiar=obiekt.rozmiar;
    tablica=new item[obiekt.rozmiar];
    for(int i=0; i<(int)obiekt.rozmiar; i++)
    {
        tablica[i]=obiekt.tablica[i];
    }
    return *this;
}


//////////////////S T R U M I E N I E //////////////////////////////
///////////////////////////////////////////////////////////////////


std::istream & operator>>(std::istream & os, Wektor & obiekt)
{
    for(int i=0; i<(int)obiekt.rozmiar; i++)
    {
        os >> obiekt.tablica[i];
    }
    return os;
}

std::ostream & operator<<(std::ostream & os,const Wektor & obiekt)
{
    os << "| ";
    for(int i=0; i<(int)obiekt.rozmiar; i++)
    {
        os << obiekt.tablica[i] << " ";
    }
    os <<"|"<<std::endl;
    return os;
}

//////////////////I N D E K S O W A N I E //////////////////////////
///////////////////////////////////////////////////////////////////


item & Wektor::operator[](int r)
{
    return tablica[r];
}

item & Wektor::operator[](int r) const
{
    return tablica[r];
}













