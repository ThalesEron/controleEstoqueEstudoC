#include "fornecedor.h"
#include "ui_fornecedor.h"

Fornecedor::Fornecedor(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Fornecedor)
{
    ui->setupUi(this);
}

Fornecedor::~Fornecedor()
{
    delete ui;
}



void Fornecedor::on_buttonConfirmFor_clicked()
{
    //pegando o texto escrito nos campos
    QString nome = ui->lineEditNomeFor->text();
    QString cnpj = ui->lineEditCnpjFor->text();
    QString telefone1 = ui->lineEditTel1For->text();
    QString email1 = ui->lineEditEmail1For->text();

    //campos não obrigatórios
    QString telefone2 = ui->lineEditTel2For->text();
    QString email2 = ui->lineEditEmail2For->text();

    //campos endereço
    QString enderecoRua = ui->lineEditRuaFor->text();
    QString enderecoNumero = ui->lineEditNumeroFor->text();
    QString enderecoBairro = ui->lineEditBairroFor->text();
    QString enderecoCidade = ui->lineEditCidadeFor->text();
    QString enderecoEstado = ui->lineEditEstadoFor->text();
    QString enderecoPais = ui->lineEditPaisFor->text();


    //verificar se os campos de telefone tem letras
    bool ok, ok2, ok3;
    int tel1 = telefone1.toInt(&ok);
     int cnpj1 = cnpj.toInt(&ok3);

   if(!ok) {
       QMessageBox::information(this, "Registros Informados:", "Digite um valor valido no campo de telefone 1.");
       return;
   }

   if(!ok3) {
       QMessageBox::information(this, "Registros Informados:", "Digite um valor valido no campo de CNPJ.");
       return;
   }

   //verificar se tem algum campo obrigatório vazio
   if (nome == "" || telefone1 == "" || email1 == "" || enderecoRua == "" || enderecoNumero == "" || enderecoBairro == "" || enderecoCidade == "" || enderecoEstado == "" || enderecoPais == "" || cnpj == "") {
       QMessageBox::information(this, "Registros Informados:", "Digite um valor em todos campos obrigatórios.");
       return;
   }

   //verificar se o campo tel2 tem registro
    if (telefone2 == "") {
    } else {

        //verificar se tem letras no campo telefone 2
        int tel2 = telefone2.toInt(&ok2);

        if(!ok2) {
            QMessageBox::information(this, "Registros Informados:", "Digite um valor valido no campo de telefone 2.");
            return;
        }

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


                //preparando os dados para ser inserido no banco de dados
                qry.prepare("INSERT INTO fornecedor (nome, cnpj, telefone, email, telefone2, email2)" "VALUES (:nome, :cnpj, :telefone, :email, :telefone2, :email2)");

                qry.bindValue(":nome", nome);
                qry.bindValue(":cnpj", cnpj);
                qry.bindValue(":telefone", telefone1);
                qry.bindValue(":email", email1);
                qry.bindValue(":telefone2", telefone2);
                qry.bindValue(":email2", email2);

                //verificando se ta tudo certo com a função e executando a função
                if (!qry.exec()) {
                    //mensagem de erro caso tenha dado algum erro nos dados informados
                    QMessageBox::information(this, "Registro Não Realizado:", "Algum dado na parte de cadastro não foi informado corretamente");
                    return;
                }

                //Pegar o id registrado no banco de dados com auto increment, colocado no fornecedor para setar no endereço
                //Necessário para fazer um select
               // QSqlQuery qry3(QSqlDatabase::database("qt1"));
                    QSqlQuery qry3;

                 //Pegando o ID do fornecedor que foi registrado, para registrar no bd de endereço

               // int fornecedorId;


                qry3.prepare("SELECT id FROM fornecedor WHERE nome='"+nome+"'");




                //verificando se o id está correto
                if (qry3.exec()) {
                    //é necessário esse next para poder pegar o select
                  qry3.next();

                  //pegando o valor do select, o 0 quer dizer que está pegando o valor do primeiro campo.
                    int fornecedorId = qry3.value(0).toInt();


                    //Registrando o endereço depois, pois vai ser necessário pegar o id do fornecedor para colocar nele.

                     QSqlQuery qry2;



                   qry2.prepare("INSERT INTO endereco (rua, numero, bairro, cidade, estado, pais, fornecedor_id)" "VALUES (:rua, :numero, :bairro, :cidade, :estado, :pais, :fornecedor_id)");

                    qry2.bindValue(":rua", enderecoRua);
                    qry2.bindValue(":numero", enderecoNumero);
                    qry2.bindValue(":bairro", enderecoBairro);
                    qry2.bindValue(":cidade", enderecoCidade);
                    qry2.bindValue(":estado", enderecoEstado);
                    qry2.bindValue(":pais", enderecoPais);
                    qry2.bindValue(":fornecedor_id", fornecedorId);

                     if (qry2.exec()) {
                         //confirmando ao usuário os dados registrados e que foi realizado com sucesso
                         QMessageBox::information(this, "Registro Realizado:", "Nome: "+nome+"\nCnpj: "+cnpj+"\nTelefone: "+telefone1+"\nEmail1: "+email1+"\nTelefone2: "+telefone2+"\nEmail2: "+email2);
                           //após
                         limparForne();
                     } else {
                         //mensagem de erro caso tenha dado algum erro nos dados informados
                         QMessageBox::information(this, "Registro Não Realizado:", "Algum dado na parte de endereço não foi informado corretamente");
                        return;
                     }


                } else {

                    QMessageBox::information(this, "Registro Não Encontrado:", "O id do fornecedor não foi encontrado");
                    return;
                }


                //vou usar dps para da um for nos fornecedores
                    //if (  while( qry3.result() ){
                     //   qry3.next();
                  //




            } else {
                //mensagem de erro caso o banco de dados não esteja conectando
                QMessageBox::information(this, "Not Connect:", "Banco de dados não está funcionando");
                return;
            }


}

void Fornecedor::on_pushButtonLimparFor_clicked()
{
    //chamand método para limpar os campos
limparForne();
}



void Fornecedor::limparForne() {

    //limpando os campos digitados
   ui->lineEditNomeFor->clear();
   ui->lineEditCnpjFor->clear();
   ui->lineEditTel1For->clear();
   ui->lineEditEmail1For->clear();
   ui->lineEditTel2For->clear();
   ui->lineEditEmail2For->clear();
   ui->lineEditRuaFor->clear();
   ui->lineEditNumeroFor->clear();
   ui->lineEditBairroFor->clear();
   ui->lineEditCidadeFor->clear();
   ui->lineEditEstadoFor->clear();
   ui->lineEditPaisFor->clear();


   //colocando o cursor no campo de texto de nome
   ui->lineEditNomeFor->setFocus();

        }
