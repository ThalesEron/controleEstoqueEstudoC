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
        db.setDatabaseName("qt1"); //lembrar de importar o banco de dados no xampp chamado qt1

    //verificando se está online
        if (db.open()) {


        //registrando os dados no banco de dados
            QSqlQuery qry;

            qry.prepare("INSERT INTO produto (name, quantidade, tipo, fornecedor, peso)" "VALUES (:nome, :quantidade, :tipo, :fornecedor, :peso)");

            qry.bindValue(":nome", nome);
            qry.bindValue(":quantidade", quantidade);
            qry.bindValue(":tipo", tipo);
            qry.bindValue(":fornecedor", fornecedor);
            qry.bindValue(":peso", peso);

             if (qry.exec()) {
                 //confirmando ao usuário os dados registrados e que foi realizado com sucesso
                 QMessageBox::information(this, "Registro Realizado:", "Nome: "+nome+"\nQuantidade: "+quantidade+"\nTipo: "+tipo+"\nFornecedor: "+fornecedor+"\nPeso: "+peso+".");

             } else {
                 //mensagem de erro caso tenha dado algum erro nos dados informados
                 QMessageBox::information(this, "Registro Não Realizado:", "Algum dado não foi informado corretamente");
             }

        } else {
            //mensagem de erro caso o banco de dados não esteja conectando
            QMessageBox::information(this, "Not Connect:", "Banco de dados não está funcionando");

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
