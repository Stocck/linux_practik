#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QString>
#include <string>
#include <iostream>
#include <iomanip>
using namespace std;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


double fuction(double x){
    return 9*log(x) - 2*x;
}

double fi(double x){
    return 9*log(x)/2.0;
}
double fi1(double x){
    return 9/(2*x); // x > 4.5 передел Xk является ед корнем
}

void MainWindow::on_pushButton_clicked()
{
    bool isReadIntStartPoint;
    double startPoint = ui->startPoint->text().toDouble(&isReadIntStartPoint);
    if (!isReadIntStartPoint || startPoint <= 4.5){
        QMessageBox::warning(this, "Внимание", "Введи вещественное число\nбольше 4.5 для начальной точки");
        return;
    }
    bool isReadMaxCount;
    int maxCount = ui->maxCount->text().toInt(&isReadMaxCount);
    if (!isReadMaxCount){
        QMessageBox::warning(this, "Внимание", "Введи целое число\nбольше 0 для максимального кол-ва итераций");
        return;
    }
    bool isReadAccuracy;
    double accuracy = ui->accuracy->text().toDouble(&isReadAccuracy);
    if (!isReadAccuracy){
        QMessageBox::warning(this, "Внимание", "Введи вещественное число\nбольше 0 для допустимой погрешности");
        return;
    }
    double x = startPoint;
    double xold = - 10e100;
    int i;
    for (i = 0; i <= maxCount && abs(x-xold) > accuracy; i++){
        xold = x;
        x = fi(xold);
    }
    ui->answerCount->setText(QString::number(i));
    ui->answer->setText(QString::number(x, 'f', 7));
    ui->answerAccuracy->setText(QString::number(abs(x-xold)));

    cout << setprecision(15) << x << endl;
    cout << i << endl;
    cout << abs(x-xold) << endl;
}


