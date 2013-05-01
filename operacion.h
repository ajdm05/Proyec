#ifndef OPERACION_H
#define OPERACION_H

#include <QString>
#include "fraccion.h"
#include <QDebug>


class Operacion
{
private:
    Fraccion operando1;
    Fraccion operando2;
    Fraccion resultado;
    char operador; // + , - , * , /

public:
    Operacion();
    Operacion(Fraccion op1, Fraccion op2, char operador);

    Fraccion getOperando1();
    Fraccion getOperando2();
    Fraccion getResultado();
    char getOperador();
    QString toString();

    void setOperando1(Fraccion f);
    void setOperando2(Fraccion f);
    void setOperador(char op);
    void setOperacion(Fraccion op1, Fraccion op2, char operador);
};

#endif // OPERACION_H
