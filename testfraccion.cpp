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
    this->respuestasCorrectas = 0;
    this->respuestasIncorrectas = 0;
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
    this->respuestasCorrectas = 0;
    this->respuestasIncorrectas = 0;
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

    int num1, den1, num2, den2, op;
    char o;
    Fraccion f1,f2;

    for (int i=0; i<cuantasOperaciones; i++)
    {

        num1 = rand() % ( this->vmayor_numerador - this->vmenor_numerador)  + this->vmenor_numerador;
        den1 = rand() % (this->vmayor_denominador - this->vmenor_denominador) + this->vmenor_denominador;

        num2 = rand() % (this->vmayor_numerador - this->vmenor_numerador) + this->vmenor_numerador;
        den2 = rand() % (this->vmayor_denominador - this->vmenor_denominador) + this->vmenor_denominador;


        f1.setFraccion(num1,den1);
        f2.setFraccion(num2,den2);
        qDebug() << num1;
         qDebug() << den1;
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
    qDebug() << this->operaciones[index].toString();
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

void TestFraccion::setRespuesta(Fraccion* respuesta, int index)
{
    this->respuestas[index]= respuesta;
}

Fraccion* TestFraccion::getRespuesta(int index)
{
    return this->respuestas[index];
}

QString TestFraccion::getScore()
{
    QString miScore;
    for (int i=0; i<this->cuantasOperaciones; i++){
        Fraccion f1, f2;

        Fraccion* f3 = this->getRespuesta(i);
        if (f3 != 0){
            int num = f3->getNumerador();
            int den = f3->getDenominador();
            f2.setFraccion(this->getOperacion(i).getResultado());

            f1.setFraccion(num,den);
            if (f1.esIgual(f2))
               this->respuestasCorrectas++;
            else
                this->respuestasIncorrectas++;
        }
    }
    QString temp;
    int total = (this->respuestasCorrectas*100)/this->cuantasOperaciones;
    temp.setNum(total);
    miScore = temp + "%";
    return miScore;
}


QString TestFraccion::getRespuestasCorrectas()
{
    QString temp;
    temp.setNum(this->respuestasCorrectas);
    return temp;
}

QString TestFraccion::getrespuestasIncorrectas()
{
    QString temp;
    temp.setNum(this->respuestasIncorrectas);
    return temp;
}

void TestFraccion::scramble()
{
    Operacion* tempOperaciones = new Operacion[this->cuantasOperaciones];
    Fraccion* *tempFracciones = new Fraccion*[this->cuantasOperaciones];
    int random;

    for (int i=0; i<this->cuantasOperaciones; i++)
    {
        random = rand() % this->cuantasOperaciones;
        qDebug() << "Random " << random;
        Operacion temp = this->getOperacion(random);
        Fraccion * temp2 = this->getRespuesta(random);
        tempOperaciones[i] = temp;
        if (temp2 !=0)
            tempFracciones[i] = this->getRespuesta(random);
        else
            tempFracciones[i] = 0;
    }


    for (int i=0; i<this->cuantasOperaciones; i++)
    {
        this->operaciones[i] = tempOperaciones[i];
        this->respuestas[i] = tempFracciones[i];
    }
}
