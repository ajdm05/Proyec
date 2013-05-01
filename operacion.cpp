#include "operacion.h"

Operacion::Operacion()
{
}

void Operacion::setOperacion(Fraccion op1, Fraccion op2, char operador)
{
    this->operando1.setFraccion(op1);
    this->operando2.setFraccion(op2);
    this->operador = operador;

    switch (operador){
    case '+':
        this->resultado.sumar(op1,op2);
        break;
    case '-':
        this->resultado.restar(op1,op2);
        break;
    case '*':
        this->resultado.multiplicar(op1,op2);
        break;
    case '/':
        this->resultado.dividir(op1,op2);
        break;
    default:
        this->resultado.sumar(op1,op2);
    }


}

void Operacion::setOperando1(Fraccion f)
{
    this->operando1 = f;
}
void Operacion::setOperando2(Fraccion f)
{
    this->operando2 = f;
}
void Operacion::setOperador(char op)
{
    switch (op){
    case '+':
        this->operador = op;
        break;
    case '-':
        this->operador = op;
        break;
    case '*':
        this->operador = op;
        break;
    case '/':
        this->operador = op;
        break;
    default:
        this->operador = '+';
    }
}

QString Operacion::toString()
{
    QString temp;
    temp = operando1.toString() + " ";
    temp = temp + this->operador;
    temp = temp + " " + operando2.toString() + " = " + resultado.toString();
    return temp;
}

