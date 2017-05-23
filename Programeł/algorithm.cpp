#include "algorithm.h"

int gauss(Matrix & obiekt)
{
    int zamiana=1;
    for(int i=0; i<obiekt.rows(); i++)
    {
        if(obiekt[i][i]==0)
        {
            int j=i;
            while(obiekt[j][i]==0 && j<obiekt.rows()-1)
            {
                j++;
            }
            Wektor temp;
            temp=obiekt[j];
            obiekt[j]=obiekt[i];
            obiekt[i]=temp;
            zamiana*=-1;
        }
        for(int j=i+1; j<obiekt.rows(); j++)
        {
            if(obiekt[j][i]!=0)
            {
                double k=obiekt[j][i]/obiekt[i][i];
                obiekt[j]=obiekt[j]-k*obiekt[i];
            }
        }
    }
    return zamiana;
}

double det(Matrix obiekt)
{
    int temp=gauss(obiekt);
    double wynik=1;
    for(int i=0;i<obiekt.rows();i++)
    {
        wynik*=obiekt[i][i];
    }
    wynik*=temp;
    return wynik;
}
