#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

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


void MainWindow::on_confirmRegisterButton_clicked()
{
    //pegando o texto escrito no campo
    QString nome = ui->lineEditName->text();
    QString quantidade = ui->lineEditQuant->text();
    QString tipo = ui->lineEditType->text();
    QString fornecedor = ui->lineEditForne->text();
    QString peso = ui->lineEditPeso->text();



    //verificar se tem algum campo vazio
    if (nome == "" || quantidade == "" || tipo == "" || fornecedor == "" || peso == "") {
        QMessageBox::information(this, "Registros Informados:", "Digite um valor em todos campos.");
        return;
    }


    //mostrando os textos digitados
    QMessageBox::information(this, "Registros Informados:", "Nome: "+nome+"\nQuantidade: "+quantidade+"\nTipo: "+tipo+"Fornecedor: "+fornecedor+"\nPeso: "+peso+".");

}

void MainWindow::on_pushButton_clicked()
{
    //limpando os campos digitados
    ui->lineEditName->clear();
    ui->lineEditQuant->clear();
    ui->lineEditType->clear();
    ui->lineEditForne->clear();
    ui->lineEditPeso->clear();

    //colocando o cursor no campo de texto de nome
    ui->lineEditName->setFocus();
}
