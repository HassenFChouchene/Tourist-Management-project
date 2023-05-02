#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ptrAddPackge = new AddPackage();
    ptrRegisterTourist = new RegisterTourist();
    ptrFindPackage = new FindPackage();
    ptrFindTourist = new FindTourist();
    database = QSqlDatabase::addDatabase("QSQLITE", "DB1");
    database.setDatabaseName("/home/hassen99/Documents/C/databases/MyTourstManager.db");

    if(!database.open()){
        qDebug() << "Error: Unable to open database..";
    }
    else{
        qDebug() << "Database open successfully..";
    }
}

MainWindow::~MainWindow()
{
    delete ui;
    delete ptrAddPackge;
    delete ptrRegisterTourist;
    delete ptrFindTourist;
    delete ptrFindPackage;
    database.close();
    QSqlDatabase::removeDatabase(database.connectionName());
    qDebug() << " ~MainWindow()";
}


void MainWindow::on_pushButton_clicked()
{
    ptrAddPackge->show();
}


void MainWindow::on_pushButton_2_clicked()
{
    ptrRegisterTourist->show();
}


void MainWindow::on_pushButton_3_clicked()
{
    ptrFindPackage->show();
}


void MainWindow::on_pushButton_4_clicked()
{
    ptrFindTourist->show();
}
