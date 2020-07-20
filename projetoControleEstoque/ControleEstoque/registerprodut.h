#ifndef REGISTERPRODUT_H
#define REGISTERPRODUT_H

#include <QDialog>

namespace Ui {
class registerprodut;
}

class registerprodut : public QDialog
{
    Q_OBJECT

public:
    explicit registerprodut(QWidget *parent = nullptr);
    ~registerprodut();

private slots:
    void on_confirmRegisterButton_clicked();

    void on_pushButton_clicked();

private:
    Ui::registerprodut *ui;
};

#endif // REGISTERPRODUT_H
