#include "registerprodut.h"
#include "ui_registerprodut.h"


registerprodut::registerprodut(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::registerprodut)
{
    ui->setupUi(this);
}

registerprodut::~registerprodut()
{
    delete ui;
}

void registerprodut::on_confirmRegisterButton_clicked()
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

    //Conexão banco de dados
        QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
        db.setHostName("localhost");
        db.setUserName("root");
        db.setPassword("");
        db.setDatabaseName("qt1");

    //mostrando os textos digitados
        if (db.open()) {
            QMessageBox::information(this, "Registros Informados:", "Nome: "+nome+"\nQuantidade: "+quantidade+"\nTipo: "+tipo+"Fornecedor: "+fornecedor+"\nPeso: "+peso+".");

        } else {
            QMessageBox::information(this, "Registros Informados:", "Banco de dados não está funcionando");

        }

}

void registerprodut::on_pushButton_clicked()
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
