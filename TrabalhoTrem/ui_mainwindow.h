/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QFrame *frame;
    QLabel *labelTrem04;
    QLabel *labelTrem02;
    QLabel *labelTrilho01;
    QLabel *labelTrem06;
    QLabel *labelTrilho02;
    QLabel *labelTrilho06;
    QLabel *labelTrilho03;
    QLabel *labelTrem01;
    QLabel *labelTrilho05;
    QLabel *labelTrem05;
    QLabel *labelTrilho04;
    QLabel *labelTrem03;
    QFrame *frame_2;
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLabel *label;
    QLineEdit *velLine;
    QLabel *label_2;
    QLineEdit *idLine;
    QRadioButton *allButton;
    QRadioButton *idButton;
    QPushButton *velButton;
    QPushButton *enableButton;
    QPushButton *disableButton;
    QLabel *label_3;
    QWidget *formLayoutWidget_2;
    QFormLayout *formLayout_2;
    QLabel *label_5;
    QLineEdit *portText;
    QPushButton *serverOn;
    QLabel *label_4;
    QLineEdit *ipText;
    QLabel *label_6;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(831, 514);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        frame = new QFrame(centralWidget);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(260, 0, 511, 411));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        labelTrem04 = new QLabel(frame);
        labelTrem04->setObjectName(QStringLiteral("labelTrem04"));
        labelTrem04->setGeometry(QRect(400, 220, 20, 20));
        labelTrem04->setStyleSheet(QStringLiteral("background-color: red"));
        labelTrem02 = new QLabel(frame);
        labelTrem02->setObjectName(QStringLiteral("labelTrem02"));
        labelTrem02->setGeometry(QRect(260, 20, 20, 20));
        labelTrem02->setStyleSheet(QStringLiteral("background-color: red"));
        labelTrilho01 = new QLabel(frame);
        labelTrilho01->setObjectName(QStringLiteral("labelTrilho01"));
        labelTrilho01->setGeometry(QRect(50, 30, 140, 100));
        labelTrilho01->setStyleSheet(QStringLiteral("background-color: yellow"));
        labelTrem06 = new QLabel(frame);
        labelTrem06->setObjectName(QStringLiteral("labelTrem06"));
        labelTrem06->setGeometry(QRect(430, 290, 20, 20));
        labelTrem06->setStyleSheet(QStringLiteral("background-color: red"));
        labelTrilho02 = new QLabel(frame);
        labelTrilho02->setObjectName(QStringLiteral("labelTrilho02"));
        labelTrilho02->setGeometry(QRect(200, 30, 140, 100));
        labelTrilho02->setStyleSheet(QStringLiteral("background-color: yellow"));
        labelTrilho06 = new QLabel(frame);
        labelTrilho06->setObjectName(QStringLiteral("labelTrilho06"));
        labelTrilho06->setGeometry(QRect(280, 300, 220, 100));
        labelTrilho06->setStyleSheet(QStringLiteral("background-color: yellow"));
        labelTrilho03 = new QLabel(frame);
        labelTrilho03->setObjectName(QStringLiteral("labelTrilho03"));
        labelTrilho03->setGeometry(QRect(350, 30, 140, 100));
        labelTrilho03->setStyleSheet(QStringLiteral("background-color: yellow"));
        labelTrem01 = new QLabel(frame);
        labelTrem01->setObjectName(QStringLiteral("labelTrem01"));
        labelTrem01->setGeometry(QRect(60, 20, 20, 20));
        labelTrem01->setStyleSheet(QStringLiteral("background-color: red"));
        labelTrilho05 = new QLabel(frame);
        labelTrilho05->setObjectName(QStringLiteral("labelTrilho05"));
        labelTrilho05->setGeometry(QRect(50, 300, 220, 100));
        labelTrilho05->setStyleSheet(QStringLiteral("background-color: yellow"));
        labelTrem05 = new QLabel(frame);
        labelTrem05->setObjectName(QStringLiteral("labelTrem05"));
        labelTrem05->setGeometry(QRect(240, 390, 20, 20));
        labelTrem05->setStyleSheet(QStringLiteral("background-color: red"));
        labelTrilho04 = new QLabel(frame);
        labelTrilho04->setObjectName(QStringLiteral("labelTrilho04"));
        labelTrilho04->setGeometry(QRect(130, 140, 280, 150));
        labelTrilho04->setStyleSheet(QStringLiteral("background-color: yellow"));
        labelTrem03 = new QLabel(frame);
        labelTrem03->setObjectName(QStringLiteral("labelTrem03"));
        labelTrem03->setGeometry(QRect(450, 20, 20, 20));
        labelTrem03->setStyleSheet(QStringLiteral("background-color: red"));
        labelTrilho01->raise();
        labelTrilho02->raise();
        labelTrilho06->raise();
        labelTrilho03->raise();
        labelTrem01->raise();
        labelTrilho05->raise();
        labelTrem05->raise();
        labelTrilho04->raise();
        labelTrem03->raise();
        labelTrem04->raise();
        labelTrem06->raise();
        labelTrem02->raise();
        frame_2 = new QFrame(centralWidget);
        frame_2->setObjectName(QStringLiteral("frame_2"));
        frame_2->setGeometry(QRect(30, 0, 211, 411));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        formLayoutWidget = new QWidget(frame_2);
        formLayoutWidget->setObjectName(QStringLiteral("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(10, 40, 192, 179));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setSpacing(6);
        formLayout->setContentsMargins(11, 11, 11, 11);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(formLayoutWidget);
        label->setObjectName(QStringLiteral("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        velLine = new QLineEdit(formLayoutWidget);
        velLine->setObjectName(QStringLiteral("velLine"));

        formLayout->setWidget(0, QFormLayout::FieldRole, velLine);

        label_2 = new QLabel(formLayoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        idLine = new QLineEdit(formLayoutWidget);
        idLine->setObjectName(QStringLiteral("idLine"));

        formLayout->setWidget(1, QFormLayout::FieldRole, idLine);

        allButton = new QRadioButton(formLayoutWidget);
        allButton->setObjectName(QStringLiteral("allButton"));

        formLayout->setWidget(2, QFormLayout::LabelRole, allButton);

        idButton = new QRadioButton(formLayoutWidget);
        idButton->setObjectName(QStringLiteral("idButton"));

        formLayout->setWidget(2, QFormLayout::FieldRole, idButton);

        velButton = new QPushButton(formLayoutWidget);
        velButton->setObjectName(QStringLiteral("velButton"));

        formLayout->setWidget(3, QFormLayout::SpanningRole, velButton);

        enableButton = new QPushButton(formLayoutWidget);
        enableButton->setObjectName(QStringLiteral("enableButton"));

        formLayout->setWidget(4, QFormLayout::LabelRole, enableButton);

        disableButton = new QPushButton(formLayoutWidget);
        disableButton->setObjectName(QStringLiteral("disableButton"));

        formLayout->setWidget(4, QFormLayout::FieldRole, disableButton);

        label_3 = new QLabel(frame_2);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(40, 10, 121, 20));
        formLayoutWidget_2 = new QWidget(frame_2);
        formLayoutWidget_2->setObjectName(QStringLiteral("formLayoutWidget_2"));
        formLayoutWidget_2->setGeometry(QRect(10, 260, 191, 141));
        formLayout_2 = new QFormLayout(formLayoutWidget_2);
        formLayout_2->setSpacing(6);
        formLayout_2->setContentsMargins(11, 11, 11, 11);
        formLayout_2->setObjectName(QStringLiteral("formLayout_2"));
        formLayout_2->setContentsMargins(0, 0, 0, 0);
        label_5 = new QLabel(formLayoutWidget_2);
        label_5->setObjectName(QStringLiteral("label_5"));

        formLayout_2->setWidget(1, QFormLayout::LabelRole, label_5);

        portText = new QLineEdit(formLayoutWidget_2);
        portText->setObjectName(QStringLiteral("portText"));

        formLayout_2->setWidget(1, QFormLayout::FieldRole, portText);

        serverOn = new QPushButton(formLayoutWidget_2);
        serverOn->setObjectName(QStringLiteral("serverOn"));

        formLayout_2->setWidget(2, QFormLayout::SpanningRole, serverOn);

        label_4 = new QLabel(formLayoutWidget_2);
        label_4->setObjectName(QStringLiteral("label_4"));

        formLayout_2->setWidget(0, QFormLayout::LabelRole, label_4);

        ipText = new QLineEdit(formLayoutWidget_2);
        ipText->setObjectName(QStringLiteral("ipText"));

        formLayout_2->setWidget(0, QFormLayout::FieldRole, ipText);

        label_6 = new QLabel(frame_2);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(50, 230, 121, 17));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 831, 20));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        labelTrem04->setText(QString());
        labelTrem02->setText(QString());
        labelTrilho01->setText(QString());
        labelTrem06->setText(QString());
        labelTrilho02->setText(QString());
        labelTrilho06->setText(QString());
        labelTrilho03->setText(QString());
        labelTrem01->setText(QString());
        labelTrilho05->setText(QString());
        labelTrem05->setText(QString());
        labelTrilho04->setText(QString());
        labelTrem03->setText(QString());
        label->setText(QApplication::translate("MainWindow", "Velocidade:", 0));
        label_2->setText(QApplication::translate("MainWindow", "ID:", 0));
        allButton->setText(QApplication::translate("MainWindow", "Todos", 0));
        idButton->setText(QApplication::translate("MainWindow", "ID", 0));
        velButton->setText(QApplication::translate("MainWindow", "Setar Velocidade", 0));
        enableButton->setText(QApplication::translate("MainWindow", "On", 0));
        disableButton->setText(QApplication::translate("MainWindow", "Off", 0));
        label_3->setText(QApplication::translate("MainWindow", "   Train Controller", 0));
        label_5->setText(QApplication::translate("MainWindow", "Port:", 0));
        portText->setText(QApplication::translate("MainWindow", "4325", 0));
        serverOn->setText(QApplication::translate("MainWindow", "Ligar", 0));
        label_4->setText(QApplication::translate("MainWindow", "IP:", 0));
        ipText->setText(QApplication::translate("MainWindow", "127.0.0.1", 0));
        label_6->setText(QApplication::translate("MainWindow", "Remote Control", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
