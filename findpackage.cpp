#include "findpackage.h"
#include "ui_findpackage.h"

FindPackage::FindPackage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FindPackage)
{
    ui->setupUi(this);
}

FindPackage::~FindPackage()
{
    qDebug() << "~ Findpackage()";
    delete ui;
    delete model;
}

void FindPackage::on_btnFindPackage_clicked()
{
    QString packageName = ui->txtPackageName->text();
    qDebug() << "Package Name : "<< packageName;
    QSqlDatabase database = QSqlDatabase::database("DB1");

    if(model == NULL)
        model = new QSqlQueryModel();

    model->setQuery("select * from Package where PackageName like '%" + packageName + "%'", database);
    ui->tableView->setModel(model);
}
