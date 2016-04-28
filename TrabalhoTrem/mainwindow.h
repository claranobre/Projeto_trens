#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "trem.h"
#include "socket.h"
#include "semaforo.h"
#include <vector>
#include <QMainWindow>
#include <QList>

using namespace std;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void updateInterface(int,int,int);
    void updateComand();
    void setVelocidadeGeral (int);
    void setVelocidade (int id, int velocidade);
    void setEnableGeral (bool enable);
    void setEnable (int id, bool enable);

private slots:
    void on_velButton_clicked();
    void on_enableButton_clicked();
    void on_disableButton_clicked();
    void on_serverOn_clicked();

private:
    QList<Trem*> listaTrem;
    vector<Semaforo*> sem;
    Ui::MainWindow *ui;
    Trem *trem1;
    Trem *trem2;
    Trem *trem3;
    Trem *trem4;
    Trem *trem5;
    Trem *trem6;
    Semaforo *s0;
    Semaforo *s1;
    Semaforo *s2;
    Semaforo *s3;
    Semaforo *s4;
    Semaforo *s5;
    Semaforo *s6;
    Semaforo *s7;

    Socket *conect;
};

#endif // MAINWINDOW_H
