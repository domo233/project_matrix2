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
    bool operator==(const Wektor &) const;
    bool operator!=(const Wektor &) const;
    const Wektor & operator+=(const Wektor &);
    const Wektor & operator-=(const Wektor &);
    double & operator[](int);
    double & operator[](int) const;
    friend Wektor operator*(const double &, const Wektor &);
    friend Wektor operator*(const Wektor &, const double &);
    friend std::ostream & operator<<(std::ostream &,const Wektor &);
    friend std::istream & operator>>(std::istream &,Wektor &);
};

#endif // WEKTOR
