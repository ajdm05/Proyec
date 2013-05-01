#ifndef FRACCION_H
#define FRACCION_H


#include <string>
#include <QString>
using namespace std;


class Fraccion
{

private:
    int numerador;
    int denominador;

    int MCD(int nuevoNum, int nuevoDen);

public:
    Fraccion();
    Fraccion(int num, int den);

        QString toString();

        int getNumerador();
        int getDenominador();

        void setNumerador(int nuevoNum);
        void setDenominador(int nuevoDen);
        void setFraccion(int num, int denom);
        void setFraccion(Fraccion f);

        void simplificar();

        bool esIgual(Fraccion F1);
        bool esMenor(Fraccion F1);
        bool esMayor(Fraccion F1);


        void sumar(Fraccion F);
        void sumar(Fraccion F1, Fraccion F2);
        static Fraccion Sumar(Fraccion F1, Fraccion F2);

        void restar(Fraccion F);
        void restar(Fraccion F1, Fraccion F2);
        static Fraccion Restar(Fraccion F1, Fraccion F2);

        void multiplicar(Fraccion F);
        void multiplicar(Fraccion F1, Fraccion F2);
        static Fraccion Multiplicar(Fraccion F1, Fraccion F2);

        void dividir(Fraccion F);
        void dividir(Fraccion F1, Fraccion F2);
        static Fraccion Dividir(Fraccion F1, Fraccion F2);

};

#endif // FRACCION_H

