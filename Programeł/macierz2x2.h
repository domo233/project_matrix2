#ifndef MACIERZ2X2_H
#define MACIERZ2X2_H

#include <QDialog>
#include "matrix.h"

namespace Ui {
class Macierz2x2;
}

class Macierz2x2 : public QDialog
{
    Q_OBJECT

public:
    explicit Macierz2x2(QWidget *parent = 0);
    ~Macierz2x2();

private slots:
    void on_pushButton_plus_clicked();

    void on_pushButton_minus_clicked();

    void on_pushButton_multiply_clicked();

    void on_pushButton_losuj_clicked();

private:
    Ui::Macierz2x2 *ui;
};

#endif // MACIERZ2X2_H
