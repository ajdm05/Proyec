#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>

#include "fraccion.h"
#include "testfraccion.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void createTest();
    //void renderOperacion(int cual);


private slots:
    void on_pb_start_clicked();

    void on_pb_finish_clicked();

    void on_pb_cancel_clicked();

    void on_pb_home_clicked();

    void on_pb_previous_clicked();

    void on_pb_next_clicked();

    void on_pb_ok_clicked();

    void on_pb_scramble_clicked();

private:
    Ui::MainWindow *ui;
    void miTesting();
    TestFraccion *miTest;
    int currentOperacion;
    void renderOperacion(int cual);
    void initialize();
    void destroy();
};

#endif // MAINWINDOW_H

