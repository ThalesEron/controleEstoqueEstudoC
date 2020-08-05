#ifndef FORNECEDOR_H
#define FORNECEDOR_H

#include <QDialog>
#include <QtSql>
#include <QSqlDatabase>
#include <QMessageBox>

namespace Ui {
class Fornecedor;
}

class Fornecedor : public QDialog
{
    Q_OBJECT

public:
    explicit Fornecedor(QWidget *parent = nullptr);
    ~Fornecedor();

private slots:
    void on_buttonConfirmFor_clicked();

    void on_pushButtonLimparFor_clicked();

    void limparForne();

private:
    Ui::Fornecedor *ui;
};

#endif // FORNECEDOR_H
