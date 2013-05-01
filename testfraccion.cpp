#include "testfraccion.h"

TestFraccion::TestFraccion()
{
    this->cuantasOperaciones = 10;
    this->timeMinutos = 1;
    this->vmenor_numerador = 1;
    this->vmayor_numerador = 10;
    this->vmenor_denominador = 1;
    this->vmayor_denominador = 10;
    this->respuestas = new Fraccion* [10];
    this->operaciones = new Operacion[10];
    srand(time(0));
    this->generarRandom();

    for (int i=0; i<10; i++)
    {
        this->respuestas[i] = 0;
    }

}
TestFraccion::TestFraccion(int cant, int tiempo, int nmay, int nmen, int dmay, int dmen )
{
    this->cuantasOperaciones = cant;
    this->timeMinutos = tiempo;
    this->vmayor_numerador = nmay;
    this->vmenor_numerador = nmen;
    this->vmayor_denominador = dmay;
    this->vmenor_denominador = dmen;
    this->operaciones = new Operacion[cuantasOperaciones];
    this->respuestas = new Fraccion*[cuantasOperaciones];
    srand(time(0));
    this->generarRandom();

    for (int i=0; i<10; i++)
    {
        this->respuestas[i] = 0;
    }

}


void TestFraccion::generarRandom()
{
    int num, den, op;
    char o;
    Fraccion f1,f2;

    for (int i=0; i<cuantasOperaciones; i++)
    {
        num = rand() % (this->vmayor_numerador - this->vmenor_numerador) + this->vmenor_numerador;
        den = rand() % (this->vmayor_denominador - this->vmenor_denominador) + this->vmenor_denominador;
        f1.setFraccion(num,den);

        num = rand() % (this->vmayor_numerador - this->vmenor_numerador) + this->vmenor_numerador;
        den = rand() % (this->vmayor_denominador - this->vmenor_denominador) + this->vmenor_denominador;
        f2.setFraccion(num,den);

        op = rand() % 4;
        switch(op)
        {
        case 0:
            o = '+';
            break;
        case 1:
            o = '-';
            break;
        case 2:
            o = '*';
            break;
        case 3:
            o = '/';
            break;
        }

        Operacion temp;
        temp.setOperacion(f1,f2,o);
        this->operaciones[i] = temp;
    }
}

int TestFraccion::getCantidadOperaciones()
{
    return this->cuantasOperaciones;
}
Operacion TestFraccion::getOperacion(int index)
{
    return this->operaciones[index];
}

TestFraccion::~TestFraccion()
{
    delete[] this->operaciones;
    qDebug() << "Corriendo destructor";

    for (int i=0; i<cuantasOperaciones; i++)
    {
        if(this->respuestas[i] !=0 )
            delete [] this->respuestas[i];
    }


    delete [] this->respuestas;
}

