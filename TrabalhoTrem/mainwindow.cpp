#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    trem1 = new Trem(1,180,120);
    trem2 = new Trem(2, 320, 80);
    trem3 = new Trem(3, 550, 80);
    trem4 = new Trem(4, 280, 320);
    trem5 = new Trem(5, 640, 220);
    trem6 = new Trem(6, 530, 340);

    connect(trem1,SIGNAL(updateGUI(int,int,int)),SLOT(updateInterface(int,int,int)));
    connect(trem2,SIGNAL(updateGUI(int,int,int)),SLOT(updateInterface(int,int,int)));
    connect(trem3,SIGNAL(updateGUI(int,int,int)),SLOT(updateInterface(int,int,int)));
    connect(trem4,SIGNAL(updateGUI(int,int,int)),SLOT(updateInterface(int,int,int)));
    connect(trem5,SIGNAL(updateGUI(int,int,int)),SLOT(updateInterface(int,int,int)));
    connect(trem6,SIGNAL(updateGUI(int,int,int)),SLOT(updateInterface(int,int,int)));

    receberEntrada = new getEntry();
    connect(receberEntrada, SIGNAL(entry(int, int, bool)), SLOT(updateTrem(int, int, bool)));

    trem1->start();
    trem2->start();
    trem3->start();
    trem4->start();
    trem5->start();
    trem6->start();

    receberEntrada->start();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateTrem(int id, int velocidade, bool enable){
    switch(id){
    case 1:
        if(enable){
            trem1->parar_retomar();
        }
        else{
            trem1->mudar_velocidade(velocidade);
        }
        break;
    case 2:
        if(enable){
            trem2->parar_retomar();
        }
        else{
            trem2->mudar_velocidade(velocidade);
        }
        break;
    case 3:
        if(enable){
            trem3->parar_retomar();
        }
        else{
            trem3->mudar_velocidade(velocidade);
        }
        break;
    case 4:
        if(enable){
            trem4->parar_retomar();
        }
        else{
            trem4->mudar_velocidade(velocidade);
        }
        break;
    case 5:
        if(enable){
            trem5->parar_retomar();
        }
        else{
            trem5->mudar_velocidade(velocidade);
        }
        break;
    case 6:
        if(enable){
            trem6->parar_retomar();
        }
        else{
            trem6->mudar_velocidade(velocidade);
        }
        break;
    }
}

void MainWindow::updateInterface(int id, int x, int y, int velocidade)
{
    switch(id){
        case 1:
            ui->labelTrem01->setGeometry(x,y,20,20);
            ui->lcdNumber->display(10000/velocidade);
            break;
        case 2:
            ui->labelTrem02->setGeometry(x,y,20,20);
            ui->lcdNumber_2->display(10000/velocidade);
            break;
        case 3:
            ui->labelTrem03->setGeometry(x,y,20,20);
            ui->lcdNumber_3->display(10000/velocidade);
            break;
        case 4:
            ui->labelTrem04->setGeometry(x,y,20,20);
            ui->lcdNumber_4->display(10000/velocidade);
            break;
        case 5:
            ui->labelTrem05->setGeometry(x,y,20,20);
            ui->lcdNumber_5->display(10000/velocidade);
            break;
        case 6:
            ui->labelTrem06->setGeometry(x,y,20,20);
            ui->lcdNumber_6->display(10000/velocidade);
            break;
        default:
            break;
    }
}
void MainWindow::on_pushButton_clicked()
{
    trem1->parar_retomar();
    trem2->parar_retomar();
    trem3->parar_retomar();
    trem4->parar_retomar();
    trem5->parar_retomar();
    trem6->parar_retomar();
}
