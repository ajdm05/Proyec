#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QString>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    ui->stackedWidget->setCurrentIndex(0);
    ui->sb_cuantOperaciones->setFocus();

}


void MainWindow::initialize()
{
    miTest = 0;
    this->currentOperacion = 0;
}

void MainWindow::createTest()
{
    int operaciones = ui->sb_cuantOperaciones->text().toInt();
    int numMa = ui->sb_numMayor->text().toInt();
    int numMe = ui->sb_numMenor->text().toInt();
    int denMa = ui->sb_denMayor->text().toInt();
    int denMe = ui->sb_denMenor->text().toInt();


    this->initialize();
    this->miTest = new TestFraccion(operaciones,0,numMa,numMe,denMa,denMe);

}

MainWindow::~MainWindow()
{
    delete this->miTest;
    delete ui;
}

void MainWindow::destroy()
{
    delete this->miTest;
    miTest = 0;
}

void MainWindow::on_pb_start_clicked()
{
    this->createTest();
    ui->stackedWidget->setCurrentIndex(1);
    this->renderOperacion(0);
    ui->le_num3->setFocus();

}

void MainWindow::on_pb_finish_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
    ui->lbl_TotalOperaciones->setText(QString::number(miTest->getCantidadOperaciones()));

    ui->lbl_TotalScore->setText(miTest->getScore());
    ui->lbl_OperacionesCorrectas->setText(miTest->getRespuestasCorrectas());
    ui->lbl_OperacionesIncorrectas->setText(miTest->getrespuestasIncorrectas());
    this->destroy();
}

void MainWindow::on_pb_cancel_clicked()
{
    this->destroy();
    ui->stackedWidget->setCurrentIndex(0); 
}

void MainWindow::on_pb_home_clicked()
{
    this->destroy();
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_pb_previous_clicked()
{
    this->currentOperacion--;
    this->renderOperacion(this->currentOperacion);

}

void MainWindow::on_pb_next_clicked()
{
    this->currentOperacion++;
    this->renderOperacion(this->currentOperacion);

}

void MainWindow::renderOperacion(int cual)
{
    ui->lbl_currentOperacion->setText( QString::number(this->currentOperacion+1) + "/"
                                       + QString::number(miTest->getCantidadOperaciones()));

    if (cual == 0){
        qDebug() << "Atras";
         ui->pb_previous->setEnabled(false);
    }

    else{
        ui->pb_previous->setEnabled(true);
        qDebug() << "adelante";
    }

   if (cual == miTest->getCantidadOperaciones()-1){
       qDebug() << "Fin adelante";
       qDebug() << miTest->getCantidadOperaciones();
       ui->pb_next->setEnabled(false);
   }

    else
        ui->pb_next->setEnabled(true);


    Operacion op;
    op = miTest->getOperacion(cual);

    Fraccion f1 = op.getOperando1();
    Fraccion f2 = op.getOperando2();
    int num1 = f1.getNumerador();
    int den1 = f1.getDenominador();
    int num2 = f2.getNumerador();
    int den2 = f2.getDenominador();
    ui->lbl_num1->setText(QString::number(num1));
    ui->lbl_den1->setText(QString::number(den1));
    ui->lbl_operador->setText(QChar(op.getOperador()));
    ui->lbl_num2->setText(QString::number(num2));
    ui->lbl_den2->setText(QString::number(den2));

    QString t1,t2;
    Fraccion* f = miTest->getRespuesta(cual);
    if (f != 0)
    {
        t1.setNum(f->getNumerador());
        t2.setNum(f->getDenominador());
        ui->le_num3->setText(t1);
        ui->le_dm3->setText(t2);
    }else {
        ui->le_num3->clear();
        ui->le_dm3->clear();
    }
}

void MainWindow::on_pb_ok_clicked()
{
    Fraccion *f1;
    f1 = new Fraccion(ui->le_num3->text().toInt(), ui->le_dm3->text().toInt());
    miTest->setRespuesta(f1,this->currentOperacion);
}

void MainWindow::on_pb_scramble_clicked()
{
    miTest->scramble();
}
