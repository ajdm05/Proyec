#include "fraccion.h"

Fraccion::Fraccion()
{
    this->numerador = 1;
    this->denominador = 1;
}
Fraccion::Fraccion(int num, int den)
{
    this->setFraccion(num, den);
}

QString Fraccion::toString()
    {
        QString temp;
        temp.setNum(this->getNumerador());
        temp = temp+"/";
        temp = temp + QString::number(this->getDenominador());
        return temp;
    }

int Fraccion::getNumerador()
    {
    return this->numerador;
    }
int Fraccion::getDenominador()
    {
    return this->denominador;
    }

void Fraccion::setDenominador(int nuevoDen)
    {
       if (nuevoDen == 0) return;
       this->denominador = nuevoDen;
    }
void Fraccion::setNumerador(int nuevoNum)
    {
       this->numerador = nuevoNum;
    }

void Fraccion::setFraccion(int num, int denom)
    {
        this->setNumerador(num);
        this->setDenominador(denom);
    }
void Fraccion::setFraccion(Fraccion F)
    {
        this->setFraccion(F.getNumerador(), F.getDenominador());
    }

void Fraccion::sumar(Fraccion F)
    {
        this->setNumerador((this->getNumerador()*F.getDenominador())+
                           this->getDenominador()*F.getNumerador());

        this->setDenominador(this->getDenominador()*
                             F.getDenominador());

    }
void Fraccion::sumar(Fraccion F1, Fraccion F2)
    {
        this->setFraccion(F1);
        this->sumar(F2);
    }
Fraccion Fraccion::Sumar(Fraccion F1, Fraccion F2)
    {
        Fraccion Ftemp;
        Ftemp.Sumar(F1,F2);
        return Ftemp;
    }

void Fraccion::restar(Fraccion F)
{
    this->setNumerador((this->getNumerador()*F.getDenominador())-
                       this->getDenominador()*F.getNumerador());

    this->setDenominador(this->getDenominador()*
                         F.getDenominador());
}
void Fraccion::restar(Fraccion F1, Fraccion F2)
{
    this->setFraccion(F1);
    this->restar(F2);
}
Fraccion Fraccion::Restar(Fraccion F1, Fraccion F2)
{
    Fraccion Ftemp;
    Ftemp.Restar(F1,F2);
    return Ftemp;
}

void Fraccion::multiplicar(Fraccion F)
{
    this->setNumerador((this->getNumerador()*F.getNumerador()));

    this->setDenominador(this->getDenominador()*F.getDenominador());
}
void Fraccion::multiplicar(Fraccion F1, Fraccion F2)
{
    this->setFraccion(F1);
    this->multiplicar(F2);
}
Fraccion Fraccion::Multiplicar(Fraccion F1, Fraccion F2)
{
    Fraccion Ftemp;
    Ftemp.Multiplicar(F1,F2);
    return Ftemp;
}

void Fraccion::dividir(Fraccion F)
{
    this->setNumerador((this->getNumerador()*F.getDenominador()));

    this->setDenominador(this->getDenominador()*F.getNumerador());
}
void Fraccion::dividir(Fraccion F1, Fraccion F2)
{
    this->setFraccion(F1);
    this->dividir(F2);
}
Fraccion Fraccion::Dividir(Fraccion F1, Fraccion F2)
{
    Fraccion Ftemp;
    Ftemp.Dividir(F1,F2);
    return Ftemp;
}


int Fraccion::MCD(int nuevoNum, int nuevoDen)
{
    int div = nuevoNum;
    if (div > nuevoDen)
        div = nuevoDen;

    while (div > 0)
    {
        if (nuevoDen%div == 0 && nuevoNum%div == 0)
            return div;
        div--;
    }
    return div;
}
void Fraccion::simplificar()
{
    int mcd = this->MCD(this->getNumerador(),this->getDenominador());

    this->setNumerador(this->getNumerador()/mcd);
    this->setDenominador(this->getDenominador()/mcd);

}

bool Fraccion::esIgual(Fraccion F1)
{
    this->simplificar();
    F1.simplificar();
    if (this->getNumerador() == F1.getNumerador() && this->getDenominador() == F1.getDenominador())
        return true;
    return false;


}
bool Fraccion::esMayor(Fraccion F1)
{
    this->simplificar();
    F1.simplificar();

    if (this->getNumerador() * F1.getDenominador() >
            this->getDenominador() * F1.getNumerador())
        return true;
    return false;

}
bool Fraccion::esMenor(Fraccion F1)
{
    this->simplificar();
    F1.simplificar();

    if (this->getNumerador() * F1.getDenominador() <
            this->getDenominador() * F1.getNumerador())
        return true;
    return false;
}
