#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "registerprodut.h"
#include "fornecedor.h"

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


void MainWindow::on_pushButton_clicked()
{
    registerprodut registro;
    registro.exec();
}

void MainWindow::on_pushButton_2_clicked()
{
    Fornecedor fornecedor;
    fornecedor.exec();
}
