#ifndef TESTFRACCION_H
#define TESTFRACCION_H

#include <string>
#include <QString>
#include <ctime>
#include <cmath>
#include <QDebug>

#include "operacion.h"
#include "fraccion.h"

class TestFraccion
{

private:
    int cuantasOperaciones;
    int timeMinutos;
    int vmenor_numerador;
    int vmayor_numerador;
    int vmenor_denominador;
    int vmayor_denominador;
    int respuestasCorrectas;
    int respuestasIncorrectas;
    void generarRandom();

    Operacion *operaciones; //apuntador (se usa un new y un delet cuando ya no se usa)
    Fraccion* *respuestas;

public:
    TestFraccion();
    TestFraccion(int cant,int tiempo, int nmay, int nmen, int dmay, int dmen);
    ~TestFraccion();
    Operacion getOperacion(int index);
    Fraccion* getRespuesta(int index);
    int getCantidadOperaciones();
    void setRespuesta(Fraccion* respuesta, int index);
    void scramble();
    QString getScore();
    QString getRespuestasCorrectas();
    QString getrespuestasIncorrectas();


};

#endif // TESTFRACCION_H
