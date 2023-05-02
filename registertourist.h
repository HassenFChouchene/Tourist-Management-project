#ifndef REGISTERTOURIST_H
#define REGISTERTOURIST_H

#include <QDialog>
#include "databaseheader.h"

namespace Ui {
class RegisterTourist;
}

class RegisterTourist : public QDialog
{
    Q_OBJECT

public:
    explicit RegisterTourist(QWidget *parent = nullptr);
    ~RegisterTourist();

private slots:
    void on_btnSave_clicked();

    void on_loadPakcage_clicked();

    void on_cmbChoosePackage_currentIndexChanged(int index);

    void on_btnReset_clicked();

private:
    Ui::RegisterTourist *ui;
    QSqlDatabase database;
};

#endif // REGISTERTOURIST_H
