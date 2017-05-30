#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "macierz2x2.h"



// UI mainwindow class declaration
// Deklaracja klasy g?ównego okna interfejsu u?ytkownika



namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_actionMacierz_2x2_triggered();

private:
    Ui::MainWindow *ui;
    Macierz2x2 *wsk;
};

#endif // MAINWINDOW_H
