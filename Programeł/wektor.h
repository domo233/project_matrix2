#ifndef WEKTOR
#define WEKTOR
#include <iostream>

class Wektor
{
private:
    double * tablica;
    unsigned int rozmiar;
public:
    Wektor(unsigned int rozmiar_=2);
    Wektor(const Wektor &);
    ~Wektor();
    Wektor operator+(const Wektor &) const;
    Wektor operator-(const Wektor &) const;
    Wektor & operator=(const Wektor &);
    double & operator[](int);
    friend Wektor operator*(const double &, const Wektor &);
    friend Wektor operator*(const Wektor &, const double &);
    friend std::ostream & operator<<(std::ostream &,const Wektor &);
    friend std::istream & operator>>(std::istream &,Wektor &);
};

#endif // WEKTOR
