#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->miTesting();
    this->miTest = 0;

}
   void MainWindow::miTesting()
    {


    this->miTest = new TestFraccion;

     for (int i=0; i<miTest->getCantidadOperaciones(); i++)
     {
         qDebug() << miTest->getOperacion(i).toString();
      }
    ui->sb_cuantOperaciones->setFocus();
    ui->stackedWidget->setCurrentIndex(0);
    delete this->miTest;
    //delete this->miTest = 0;


}

MainWindow::~MainWindow()
{

    delete ui;
}


void MainWindow::on_pb_start_clicked()
{
    TestFraccion test;
    this->currentOperacion = 0;
    ui->lbl_currentOperacion->setText( "1/" + ui->sb_cuantOperaciones->text() );
    ui->stackedWidget->setCurrentIndex(1);
    ui->pb_previous->setEnabled(false);
    this->renderOperacion(this->currentOperacion);

}

void MainWindow::on_pb_finish_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
    ui->lbl_TotalOperaciones->setText(ui->sb_cuantOperaciones->text());
}

void MainWindow::on_pb_cancel_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_pb_home_clicked()
{
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
    if (cual == 0)
        ui->pb_previous->setEnabled(false);
    else
        ui->pb_previous->setEnabled(true);

    if (cual == miTest->getCantidadOperaciones())
       ui->pb_next->setEnabled(false);
   // else
   //     ui->pb_next->setEnabled(true);

}
