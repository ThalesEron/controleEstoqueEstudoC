/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionRegistrar;
    QAction *actionListar;
    QWidget *centralwidget;
    QPushButton *confirmRegisterButton;
    QLabel *labelTitle;
    QLabel *label;
    QLineEdit *lineEdit;
    QLabel *label_2;
    QLineEdit *lineEdit_2;
    QLabel *label_3;
    QLineEdit *lineEdit_3;
    QLabel *label_4;
    QLineEdit *lineEdit_4;
    QLabel *label_5;
    QLineEdit *lineEdit_5;
    QMenuBar *menubar;
    QMenu *menuRegistrar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(498, 303);
        actionRegistrar = new QAction(MainWindow);
        actionRegistrar->setObjectName(QString::fromUtf8("actionRegistrar"));
        actionListar = new QAction(MainWindow);
        actionListar->setObjectName(QString::fromUtf8("actionListar"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        confirmRegisterButton = new QPushButton(centralwidget);
        confirmRegisterButton->setObjectName(QString::fromUtf8("confirmRegisterButton"));
        confirmRegisterButton->setGeometry(QRect(360, 220, 101, 31));
        QFont font;
        font.setPointSize(10);
        font.setBold(true);
        font.setWeight(75);
        confirmRegisterButton->setFont(font);
        labelTitle = new QLabel(centralwidget);
        labelTitle->setObjectName(QString::fromUtf8("labelTitle"));
        labelTitle->setGeometry(QRect(150, 20, 211, 31));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Nirmala UI"));
        font1.setPointSize(16);
        font1.setBold(true);
        font1.setWeight(75);
        labelTitle->setFont(font1);
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 90, 101, 21));
        label->setFont(font);
        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(10, 120, 113, 20));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(200, 90, 101, 21));
        label_2->setFont(font);
        lineEdit_2 = new QLineEdit(centralwidget);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(190, 120, 113, 20));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(370, 90, 101, 21));
        label_3->setFont(font);
        lineEdit_3 = new QLineEdit(centralwidget);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(360, 120, 113, 20));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(10, 170, 101, 21));
        label_4->setFont(font);
        lineEdit_4 = new QLineEdit(centralwidget);
        lineEdit_4->setObjectName(QString::fromUtf8("lineEdit_4"));
        lineEdit_4->setGeometry(QRect(10, 200, 113, 20));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(190, 170, 101, 21));
        label_5->setFont(font);
        lineEdit_5 = new QLineEdit(centralwidget);
        lineEdit_5->setObjectName(QString::fromUtf8("lineEdit_5"));
        lineEdit_5->setGeometry(QRect(190, 200, 113, 20));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 498, 21));
        menuRegistrar = new QMenu(menubar);
        menuRegistrar->setObjectName(QString::fromUtf8("menuRegistrar"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuRegistrar->menuAction());
        menuRegistrar->addAction(actionRegistrar);
        menuRegistrar->addAction(actionListar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionRegistrar->setText(QCoreApplication::translate("MainWindow", "Registrar", nullptr));
        actionListar->setText(QCoreApplication::translate("MainWindow", "Listar", nullptr));
#if QT_CONFIG(tooltip)
        confirmRegisterButton->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p>Clique para registrar</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        confirmRegisterButton->setText(QCoreApplication::translate("MainWindow", "Registrar", nullptr));
        labelTitle->setText(QCoreApplication::translate("MainWindow", "Registrar Produto", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Digite O Nome:", nullptr));
#if QT_CONFIG(tooltip)
        lineEdit->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p>Coloque o nome do produto.</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        label_2->setText(QCoreApplication::translate("MainWindow", "Quantidade:", nullptr));
#if QT_CONFIG(tooltip)
        lineEdit_2->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p>Registre a quantidade do produto:</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        lineEdit_2->setText(QString());
        label_3->setText(QCoreApplication::translate("MainWindow", "Tipo:", nullptr));
#if QT_CONFIG(tooltip)
        lineEdit_3->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p>Coloque o tipo do produto.</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        label_4->setText(QCoreApplication::translate("MainWindow", "Fornecedor:", nullptr));
#if QT_CONFIG(tooltip)
        lineEdit_4->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p>Digite o Fornecedor do produto.</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        label_5->setText(QCoreApplication::translate("MainWindow", "Peso:", nullptr));
#if QT_CONFIG(tooltip)
        lineEdit_5->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p>Digite o peso do produto em G ou ML.</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        menuRegistrar->setTitle(QCoreApplication::translate("MainWindow", "Menu", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
