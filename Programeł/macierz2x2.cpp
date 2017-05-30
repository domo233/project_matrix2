#include "macierz2x2.h"
#include "ui_macierz2x2.h"



// Obs?uga okna macierzy 2x2
// Window handling for 2x2 dimension matrix


Macierz2x2::Macierz2x2(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Macierz2x2)
{
    ui->setupUi(this);
}

Macierz2x2::~Macierz2x2()
{
    delete ui;
}

void Macierz2x2::on_pushButton_plus_clicked()
{

    Matrix m3(2,2);
    Matrix m1(2,2);
    Matrix m2(2,2);
    m1[0][0]=ui->lineEdita_0_0->text().toFloat();
    m1[0][1]=ui->lineEdita_0_1->text().toFloat();
    m1[1][0]=ui->lineEdita_1_0->text().toFloat();
    m1[1][1]=ui->lineEdita_1_1->text().toFloat();

    m2[0][0]=ui->lineEditb_0_0->text().toFloat();
    m2[0][1]=ui->lineEditb_0_1->text().toFloat();
    m2[1][0]=ui->lineEditb_1_0->text().toFloat();
    m2[1][1]=ui->lineEditb_1_1->text().toFloat();
    m3=m1+m2;
    ui->wynik_0_0->setText(QString::number(m3[0][0]));
    ui->wynik_0_1->setText(QString::number(m3[0][1]));
    ui->wynik_1_0->setText(QString::number(m3[1][0]));
    ui->wynik_1_1->setText(QString::number(m3[1][1]));

}

void Macierz2x2::on_pushButton_minus_clicked()
{
    Matrix m3(2,2);
    Matrix m1(2,2);
    Matrix m2(2,2);
    m1[0][0]=ui->lineEdita_0_0->text().toFloat();
    m1[0][1]=ui->lineEdita_0_1->text().toFloat();
    m1[1][0]=ui->lineEdita_1_0->text().toFloat();
    m1[1][1]=ui->lineEdita_1_1->text().toFloat();

    m2[0][0]=ui->lineEditb_0_0->text().toFloat();
    m2[0][1]=ui->lineEditb_0_1->text().toFloat();
    m2[1][0]=ui->lineEditb_1_0->text().toFloat();
    m2[1][1]=ui->lineEditb_1_1->text().toFloat();
    m3=m1-m2;
    ui->wynik_0_0->setText(QString::number(m3[0][0]));
    ui->wynik_0_1->setText(QString::number(m3[0][1]));
    ui->wynik_1_0->setText(QString::number(m3[1][0]));
    ui->wynik_1_1->setText(QString::number(m3[1][1]));
}

void Macierz2x2::on_pushButton_multiply_clicked()
{
    Matrix m3(2,2);
    Matrix m1(2,2);
    Matrix m2(2,2);
    m1[0][0]=ui->lineEdita_0_0->text().toFloat();
    m1[0][1]=ui->lineEdita_0_1->text().toFloat();
    m1[1][0]=ui->lineEdita_1_0->text().toFloat();
    m1[1][1]=ui->lineEdita_1_1->text().toFloat();

    m2[0][0]=ui->lineEditb_0_0->text().toFloat();
    m2[0][1]=ui->lineEditb_0_1->text().toFloat();
    m2[1][0]=ui->lineEditb_1_0->text().toFloat();
    m2[1][1]=ui->lineEditb_1_1->text().toFloat();
    m3=m1*m2;
    ui->wynik_0_0->setText(QString::number(m3[0][0]));
    ui->wynik_0_1->setText(QString::number(m3[0][1]));
    ui->wynik_1_0->setText(QString::number(m3[1][0]));
    ui->wynik_1_1->setText(QString::number(m3[1][1]));
}

void Macierz2x2::on_pushButton_losuj_clicked()
{
    ui->lineEdita_0_0->setText(QString::number(rand()%10));
    ui->lineEdita_0_1->setText(QString::number(rand()%10));
    ui->lineEdita_1_0->setText(QString::number(rand()%10));
    ui->lineEdita_1_1->setText(QString::number(rand()%10));

    ui->lineEditb_0_0->setText(QString::number(rand()%10));
    ui->lineEditb_0_1->setText(QString::number(rand()%10));
    ui->lineEditb_1_0->setText(QString::number(rand()%10));
    ui->lineEditb_1_1->setText(QString::number(rand()%10));
}
