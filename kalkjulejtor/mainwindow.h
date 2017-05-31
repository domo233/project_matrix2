#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLineEdit>
#include <QLabel>
#include <QMessageBox>
#include "matrix.h"
#include "algorithm.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    void wczytaj();
    void usun();
    void wypisz(Matrix &);
    void usun_wypisz();
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_actionDodaj_triggered();

    void on_actionOdejmij_triggered();

    void on_actionPomn_triggered();

    void on_actionLosuj_triggered();

    void on_actionWyznacznik_triggered();

    void on_actionMacierz_tr_jk_tna_triggered();

    void on_actionRz_d_triggered();

private:
    Ui::MainWindow *ui;
    QLineEdit ***tab_lineeditA=NULL;
    QLineEdit ***tab_lineeditB=NULL;
    QLabel *macierzA;
    QLabel *macierzB;
    QLabel *wynik=NULL;
    QLabel ***tab_wynik=NULL;
    Matrix *mA;
    Matrix *mB;
    int arow=-420;
    int acol=-420;
    int brow=-420;
    int bcol=-420;
    int crow;
    int ccol;

    int current_height=500;
    int current_width=410;
};

#endif // MAINWINDOW_H
