#include "addtourist.h"
#include "ui_addtourist.h"

AddTourist::AddTourist(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddTourist)
{
    ui->setupUi(this);
}

AddTourist::~AddTourist()
{
    delete ui;
}
