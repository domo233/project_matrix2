#ifndef MATRIX
#define MATRIX
#include "wektor.h"
#include <time.h>
#include <stdlib.h>

class Matrix
{
private:
    Wektor ** wiersze;
    unsigned int row;
    unsigned int col;
public:
    Matrix(unsigned int rows=2, unsigned int cols=2);
    Matrix(const Matrix &);
    Matrix(std::string);
    Matrix(unsigned int rows, unsigned int cols, std::string);
    ~Matrix();
    Matrix operator+(const Matrix &) const;
    Matrix operator-(const Matrix &) const;
    friend Matrix operator*(Matrix &,Matrix &);
    Matrix & operator=(const Matrix &);
    Wektor & operator[](int);
    friend Matrix operator*(const item &, const Matrix &);
    friend Matrix operator*(const Matrix &, const item &);
    friend std::ostream & operator<<(std::ostream &,const Matrix &);
    friend std::istream & operator>>(std::istream &,Matrix &);
    int cols() const{return col;}
    int rows() const{return row;};
    void func(void (*p)(item &));
    friend Matrix potega(Matrix &,int);
};

#endif // MATRIX
