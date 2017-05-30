#ifndef WEKTOR
#define WEKTOR
#include <iostream>

typedef long double item;



// Wektor (Vector-typo) class declarations, header file
// Plik nag?ówkowy z deklaracjami klasy Wektor


class Wektor
{
private:
    item * tablica;
    unsigned int rozmiar;
public:
    Wektor(unsigned int rozmiar_=2);
    Wektor(std::string);
    Wektor(const Wektor &);
    ~Wektor();
    Wektor operator+(const Wektor &) const;
    Wektor operator-(const Wektor &) const;
    Wektor & operator=(const Wektor &);
    bool operator==(const Wektor &) const;
    bool operator!=(const Wektor &) const;
    Wektor & operator+=(const Wektor &);
    Wektor & operator-=(const Wektor &);
    item & operator[](int);
    item & operator[](int) const;
    friend Wektor operator*(const item &, const Wektor &);
    friend Wektor operator*(const Wektor &, const item &);
    friend std::ostream & operator<<(std::ostream &,const Wektor &);
    friend std::istream & operator>>(std::istream &,Wektor &);
};

#endif // WEKTOR
