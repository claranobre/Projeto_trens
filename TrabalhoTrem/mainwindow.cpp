#include "mainwindow.h"
#include "ui_mainwindow.h"


/*
 * Global
*/

bool ligado = false;

/*
 * Mainwindow
*/

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    s0 = new Semaforo(1238,1,IPC_CREAT|0600);
    sem.push_back(s0);
    s1 = new Semaforo(1231,1,IPC_CREAT|0600);
    sem.push_back(s1);
    s2 = new Semaforo(1232,1,IPC_CREAT|0600);
    sem.push_back(s2);
    s3 = new Semaforo(1233,1,IPC_CREAT|0600);
    sem.push_back(s3);
    s4 = new Semaforo(1234,1,IPC_CREAT|0600);
    sem.push_back(s4);
    s5 = new Semaforo(1235,1,IPC_CREAT|0600);
    sem.push_back(s5);
    s6 = new Semaforo(1236,1,IPC_CREAT|0600);
    sem.push_back(s6);
    s7 = new Semaforo(1237,1,IPC_CREAT|0600);
    sem.push_back(s7);

    trem1 = new Trem(1,50,20,40,20,180,120, sem);
    listaTrem.append(trem1);
    connect(trem1,SIGNAL(updateGUI(int,int,int)),SLOT(updateInterface(int,int,int)));
    trem1->start();

    trem2 = new Trem(2,320,20,190,20,330,120, sem);
    listaTrem.append(trem2);
    connect(trem2,SIGNAL(updateGUI(int,int,int)),SLOT(updateInterface(int,int,int)));
    trem2->start();

    trem3 = new Trem(3,350,20,340,20,480,120 , sem);
    listaTrem.append(trem3);
    connect(trem3,SIGNAL(updateGUI(int,int,int)),SLOT(updateInterface(int,int,int)));
    trem3->start();

    trem4 = new Trem(4,120,150,120,130,400,280, sem);
    listaTrem.append(trem4);
    connect(trem4,SIGNAL(updateGUI(int,int,int)),SLOT(updateInterface(int,int,int)));
    trem4->start();

    trem5 = new Trem(5,50,290,40,290,260,390, sem);
    listaTrem.append(trem5);
    connect(trem5,SIGNAL(updateGUI(int,int,int)),SLOT(updateInterface(int,int,int)));
    trem5->start();

    trem6 = new Trem(6,440,390,270,290,490,390, sem);
    listaTrem.append(trem6);
    connect(trem6,SIGNAL(updateGUI(int,int,int)),SLOT(updateInterface(int,int,int)));
    trem6->start();
}

MainWindow::~MainWindow()
{
    delete ui;

    delete s0;
    delete s1;
    delete s2;
    delete s3;
    delete s4;
    delete s5;
    delete s6;
    delete s7;
}


void MainWindow::updateComand(){
    if(ligado){
        if(conect->comando.id == 0){
            this->setVelocidadeGeral(conect->comando.velocidade);
            this->setEnableGeral(conect->comando.enable);
        }
        else{
            this->setVelocidade(conect->comando.id, conect->comando.velocidade);
            this->setEnable(conect->comando.id, conect->comando.enable);
        }
    }
}

void MainWindow::updateInterface(int id, int x, int y)
{
    switch(id){
        case 1:
            ui->labelTrem01->setGeometry(x,y,20,20);
            break;
        case 2:
            ui->labelTrem02->setGeometry(x,y,20,20);
            break;
        case 3:
            ui->labelTrem03->setGeometry(x,y,20,20);
            break;
        case 4:
            ui->labelTrem04->setGeometry(x,y,20,20);
            break;
        case 5:
            ui->labelTrem05->setGeometry(x,y,20,20);
            break;
        case 6:
            ui->labelTrem06->setGeometry(x,y,20,20);
            break;
        default:
            break;
    }

}
/*
 * Setando Velociodade
*/

void MainWindow::setVelocidadeGeral (int velocidade){
    for (int i = 0; i <listaTrem.size(); i++){
        listaTrem.at(i)->setVelocidade(velocidade);
    }
}

void MainWindow::setVelocidade (int id, int velocidade){
        listaTrem.at(id -1)->setVelocidade(velocidade);
}

/*
 * ENABLE
 * DISABLE
*/

void MainWindow::setEnableGeral (bool enable){
    for (int i = 0; i <listaTrem.size(); i++){
        listaTrem.at(i)->setEnable(enable);
    }
}

void MainWindow::setEnable (int id, bool enable){
    listaTrem.at(id -1)->setEnable(enable);
}

/*
 * Buttons
*/

void MainWindow::on_velButton_clicked()
{
    if(ui->idButton->isChecked()){
        this->setVelocidade(ui->idLine->text().toInt(), ui->velLine->text().toInt());
    }
    else{
        if(ui->allButton->isChecked()){
            this->setVelocidadeGeral(ui->velLine->text().toInt());
        }
    }
}

void MainWindow::on_enableButton_clicked()
{
    if(ui->idButton->isChecked()){
        this->setEnable(ui->idLine->text().toInt(), true);
    }
    else{
        if(ui->allButton->isChecked()){
            this->setEnableGeral(true);
        }
    }
}

void MainWindow::on_disableButton_clicked()
{
    if(ui->idButton->isChecked()){
        this->setEnable(ui->idLine->text().toInt(), false);
    }
    else{
        if(ui->allButton->isChecked()){
            this->setEnableGeral(false);
        }
    }
}

void MainWindow::on_serverOn_clicked()
{
    if(!ligado){
        conect = new Socket(ui->portText->text().toInt(), strdup(ui->ipText->text().toStdString().c_str()));
        this->conect->start();
        ligado = !ligado;
        ui->serverOn->setText("Desligar");
        ui->serverOn->setDisabled(true);
        ui->ipText->setDisabled(true);
        ui->portText->setDisabled(true);
        connect(conect, SIGNAL(update()), SLOT(updateComand()));
    }
    else{
        cout << "Servidor ligado";
    }
}
