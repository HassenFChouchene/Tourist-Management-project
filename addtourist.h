#ifndef ADDTOURIST_H
#define ADDTOURIST_H

#include <QDialog>

namespace Ui {
class AddTourist;
}

class AddTourist : public QDialog
{
    Q_OBJECT

public:
    explicit AddTourist(QWidget *parent = nullptr);
    ~AddTourist();

private:
    Ui::AddTourist *ui;
};

#endif // ADDTOURIST_H
