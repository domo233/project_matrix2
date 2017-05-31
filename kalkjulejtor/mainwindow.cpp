#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap bkgnd(":/new/ico/background.jpg");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);
    setGeometry(QRect(QPoint(100,100),QSize(410,500)));
    //this->centralWidget()->setStyleSheet("background-image:url(\":/new/ico/background.jpg\"); background-position: center;" );
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::wczytaj()
{
    mA=new Matrix(arow,acol);
    mB=new Matrix(brow,bcol);
    for(int i = 0; i < arow; i++)
    {
        for(int j = 0; j < acol; j++)
        {
            (*mA)[i][j]=tab_lineeditA[i][j]->text().toDouble();
        }
    }
    for(int i = 0; i < brow; i++)
    {
        for(int j = 0; j < bcol; j++)
        {
            (*mB)[i][j]=tab_lineeditB[i][j]->text().toDouble();
        }
    }
}

void MainWindow::usun()
{
    delete mA;
    delete mB;
}

void MainWindow::wypisz(Matrix & obiekt)
{
    int k = (arow >= brow ? arow : brow);
    wynik = new QLabel("Wynik C : ",this);
    int x = 25;
    int y = 240+k*50;
    wynik->setGeometry(QRect(QPoint(x,y),QSize(100,25)));
    wynik->setStyleSheet("font-size: 18px; font-family: Calibri");
    wynik->show();
    tab_wynik=new QLabel**[obiekt.rows()];
    for(int i = 0; i < obiekt.rows(); i++)
    {
        tab_wynik[i]=new QLabel*[obiekt.cols()];
        for(int j = 0; j < obiekt.cols(); j++)
        {
            tab_wynik[i][j]=new QLabel(this);
            tab_wynik[i][j]->setText(QString::number((double)obiekt[i][j],'f',1));
            tab_wynik[i][j]->setGeometry(QRect(QPoint(x+j*50,y+50+i*50),QSize(50,50)));
            tab_wynik[i][j]->setStyleSheet("border-style: solid; border-width: 2px; qproperty-alignment: AlignCenter;");
            tab_wynik[i][j]->show();
        }
    }

    int heightt=y+60+obiekt.rows()*50;
    if(heightt > current_height)
    {
        setGeometry(100,100,current_width,heightt);
        current_height=heightt;
    }

}

void MainWindow::usun_wypisz()
{
    if(wynik != NULL)
    {
        delete wynik;
        wynik=NULL;
        for(int i = 0; i < crow; i++)
        {
            for(int j = 0; j < ccol; j++)
            {
                delete tab_wynik[i][j];
            }
            delete [] tab_wynik[i];
        }
        delete [] tab_wynik;
    }
}


void MainWindow::on_pushButton_clicked()
{

    usun_wypisz();

/////////////////////////////////////////////////////////////////////////////////////
/////////////////////////// M A C I E R Z    A /////////////////////////////////////
/// ///////////////////////////////////////////////////////////////////////////////

    if(tab_lineeditA!=NULL)
    {
        for(int i = 0; i < arow; i++)
        {
            for(int j = 0; j < acol; j++)
            {
                tab_lineeditA[i][j]->hide();
                delete tab_lineeditA[i][j];
            }
            delete [] tab_lineeditA[i];
        }
        delete [] tab_lineeditA;
        delete macierzA;
    }
    if(tab_lineeditB!=NULL)
    {
        for(int i = 0; i < brow; i++)
        {
            for(int j = 0; j < bcol; j++)
            {
                tab_lineeditB[i][j]->hide();
                delete tab_lineeditB[i][j];
            }
            delete [] tab_lineeditB[i];
        }
        delete [] tab_lineeditB;
        delete macierzB;
    }

    arow=ui->lineEdit_AROW->text().toInt();
    acol=ui->lineEdit_ACOL->text().toInt();

    macierzA = new QLabel("Macierz A :",this);
    macierzA->setGeometry(QRect(QPoint(25,185),QSize(100,25)));
    macierzA->setStyleSheet("font-size: 18px; font-family: Calibri");
    macierzA->show();

    tab_lineeditA=new QLineEdit**[arow];
    for(int i = 0; i < arow; i++)
    {
        tab_lineeditA[i]=new QLineEdit*[acol];
        for(int j = 0; j < acol; j++)
        {
            tab_lineeditA[i][j]=new QLineEdit(this);
            tab_lineeditA[i][j]->setGeometry(QRect(QPoint(25+j*50,225+i*50),QSize(25,25)));
            tab_lineeditA[i][j]->show();
        }
    }

/////////////////////////////////////////////////////////////////////////////////////
/////////////////////////// M A C I E R Z    B /////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////

    brow=ui->lineEdit_BROW->text().toInt();
    bcol=ui->lineEdit_BCOL->text().toInt();

    macierzB = new QLabel("Macierz B :",this);
    macierzB->setGeometry(QRect(QPoint(125+acol*50,185),QSize(100,25)));
    macierzB->setStyleSheet("font-size: 18px; font-family: Calibri");
    macierzB->show();

    tab_lineeditB=new QLineEdit**[brow];
    for(int i = 0; i < brow; i++)
    {
        tab_lineeditB[i]=new QLineEdit*[bcol];
        for(int j = 0; j < bcol; j++)
        {
            tab_lineeditB[i][j]=new QLineEdit(this);
            tab_lineeditB[i][j]->setGeometry(QRect(QPoint(acol*50+125+j*50,225+i*50),QSize(25,25)));
            tab_lineeditB[i][j]->show();
        }
    }

/////////////////////////////////////////////////////////////////////////////////////
/////////////////////////// R O Z M I A R   O K N A ////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////

    int widthh=acol*50+125+bcol*50;
    int temp1=225+arow*50;
    int temp2=225+brow*50;
    int heightt=(temp1 > temp2 ? temp1 : temp2);
    if(widthh > current_width)
    {
        setGeometry(100,100,widthh,current_height);
        current_width=widthh;
    }
    if(heightt > current_height)
    {
        setGeometry(100,100,current_width,heightt);
        current_height=heightt;
    }


}

void MainWindow::on_actionDodaj_triggered()
{
    if(arow == -420 || acol == -420 || brow == -420 || bcol == -420)
    {
        QMessageBox::warning(this,"Halo !","Nie zdefiniowano rozmiarów macierzy !");
        return;
    }
    if(arow != brow || acol != bcol)
    {
        QMessageBox::warning(this,"Halo !","Aby dodać macierze ich wymiary muszą być zgodne !");
        return;
    }
    crow=arow;
    ccol=acol;
    Matrix mC(crow,ccol);
    wczytaj();
    mC=*mA+*mB;
    usun_wypisz();
    wypisz(mC);
    usun();


}

void MainWindow::on_actionOdejmij_triggered()
{
    if(arow == -420 || acol == -420 || brow == -420 || bcol == -420)
    {
        QMessageBox::warning(this,"Halo !","Nie zdefiniowano rozmiarów macierzy !");
        return;
    }
    if(arow != brow || acol != bcol)
    {
        QMessageBox::warning(this,"Halo !","Aby odjąć macierze ich wymiary muszą być zgodne !");
        return;
    }
    crow=arow;
    ccol=acol;
    Matrix mC(crow,ccol);
    wczytaj();
    mC=*mA-*mB;
    usun_wypisz();
    wypisz(mC);
    usun();
}

void MainWindow::on_actionPomn_triggered()
{
    if(arow == -420 || acol == -420 || brow == -420 || bcol == -420)
    {
        QMessageBox::warning(this,"Halo !","Nie zdefiniowano rozmiarów macierzy !");
        return;
    }
    if(acol != brow)
    {
        QMessageBox::warning(this,"Halo !","Aby pomnożyć macierze, liczba kolumn macierzy A musi równać się liczbie wierszy macierzy B !");
        return;
    }
    crow=arow;
    ccol=bcol;
    Matrix mC(crow,ccol);
    wczytaj();
    mC=(*mA)*(*mB);
    usun_wypisz();
    wypisz(mC);
    usun();
}

void MainWindow::on_actionLosuj_triggered()
{
    if(arow == -420 || acol == -420 || brow == -420 || bcol == -420)
    {
        QMessageBox::warning(this,"Halo !","Nie zdefiniowano rozmiarów macierzy !");
        return;
    }
    for(int i = 0; i < arow; i++)
    {
        for(int j = 0; j < acol; j++)
        {
            tab_lineeditA[i][j]->setText(QString::number(rand()%10));
        }
    }
    for(int i = 0; i < brow; i++)
    {
        for(int j = 0; j < bcol; j++)
        {
            tab_lineeditB[i][j]->setText(QString::number(rand()%10));
        }
    }
}

void MainWindow::on_actionWyznacznik_triggered()
{
    if(arow == -420 || acol == -420)
    {
        QMessageBox::warning(this,"Halo !","Nie zdefiniowano rozmiarów macierzy A !");
        return;
    }
    if(acol != arow)
    {
        QMessageBox::warning(this,"Halo !","Aby policzyć wyznacznik, macierz musi być kwadratowa !");
        return;
    }
    wczytaj();
    double k = det(*mA);
    QString komunikat = "Wyznacznik macierzy A : ";
    komunikat += QString::number(k);
    QMessageBox::information(this,"Bardzo proszę !",komunikat);
    usun();
}

void MainWindow::on_actionMacierz_tr_jk_tna_triggered()
{
    if(arow == -420 || acol == -420)
    {
        QMessageBox::warning(this,"Halo !","Nie zdefiniowano rozmiarów macierzy A !");
        return;
    }
    wczytaj();
    crow=arow;
    ccol=acol;
    Matrix m3(*mA);
    gauss(m3);
    usun_wypisz();
    wypisz(m3);
    usun();

}

void MainWindow::on_actionRz_d_triggered()
{
    if(arow == -420 || acol == -420)
    {
        QMessageBox::warning(this,"Halo !","Nie zdefiniowano rozmiarów macierzy A !");
        return;
    }
    wczytaj();
    double k = rzad(*mA);
    QString komunikat = "Rzad macierzy A : ";
    komunikat += QString::number(k);
    QMessageBox::information(this,"Bardzo proszę !",komunikat);
    usun();
}
