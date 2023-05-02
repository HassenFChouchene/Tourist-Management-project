
#include "registertourist.h"
#include "ui_registertourist.h"
#include <QtSql/QSql>
RegisterTourist::RegisterTourist(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RegisterTourist)
{
    ui->setupUi(this);
}

RegisterTourist::~RegisterTourist()
{
    qDebug() << "in ~RegisterTourist()";
    delete ui;
}

void RegisterTourist::on_btnSave_clicked()
{
   QString firstName = ui->txtFirstName->text();
   QString middleName = ui->txtMiddleName->text();
   QString lastName = ui->txtLastName->text();
   QString passportNo = ui->txtPassportNo->text();
   QString contactNo = ui->txtContactNo->text();
   QString permanentAddress = ui->txtPermanentAddress->text();
   QString packageName = ui->cmbChoosePackage->currentText();

   QSqlDatabase database = QSqlDatabase::database("DB1");
   QSqlQuery query(database);

    query.prepare("insert into Tourist (FirstName, MiddleName, LastName, PassportNo, ContactNo, PermanentAddress, PackageName) "
                  "values('" + firstName + "','" + middleName + "','" + lastName + "', '" + passportNo + "','" + contactNo + "','" + permanentAddress + "','" + packageName +"')");
    query.exec();
    query.finish();query.clear();
    qDebug() << "Last error : "<< query.lastQuery();
    qDebug() << "Last error : "<< query.lastError().text();
    on_btnReset_clicked();
}


void RegisterTourist::on_loadPakcage_clicked()
{
    QSqlDatabase database = QSqlDatabase::database("DB1");
    QSqlQuery query(database);

     query.prepare("select PackageName from Package");
     query.exec();
     while(query.next())
      {
             ui->cmbChoosePackage->addItem(query.value(0).toString());
             qDebug() << "Filling Combobox " << query.value(0).toString();
      }

     qDebug() << "Last error : "<< query.lastQuery();
     qDebug() << "Last error : "<< query.lastError().text();
}


void RegisterTourist::on_cmbChoosePackage_currentIndexChanged(int index)
{
    QString packageName = ui->cmbChoosePackage->currentText();
    QSqlDatabase database = QSqlDatabase::database("DB1");
    QSqlQuery query(database);

     query.prepare("select PackageDescription from Package where PackageName ='" + packageName + "'");
     query.exec(); query.next();
     ui->txtPackageDescription->setText(query.value(0).toString());
     query.finish();query.clear();
     qDebug() << "Last error : "<< query.lastQuery();
     qDebug() << "Last error : "<< query.lastError().text();
}

void RegisterTourist::on_btnReset_clicked()
{
    ui->txtFirstName->clear();
    ui->txtLastName->clear();
    ui->txtMiddleName->clear();
    ui->txtContactNo->clear();
    ui->txtPassportNo->clear();
    ui->txtPermanentAddress->clear();
    ui->txtPackageDescription->clear();
}
