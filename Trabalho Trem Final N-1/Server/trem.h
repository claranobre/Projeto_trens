#ifndef TREM_H
#define TREM_H

#include <QObject>
#include <thread>
#include <chrono>
#include <vector>
#include "semaforo.h"
#include <QtDebug>
using namespace std;

class Trem : public QObject
{
    Q_OBJECT
public:
    Trem(int,int,int,int,int,int,int, vector<Semaforo*>);
    ~Trem();
    void start();
    void run();
    void setVelocidade(int);
    void setEnable(bool);
    void move();
    void run1();
    void run2();
    void run3();
    void run4();
    void run5();
    void run6();

signals:
    void updateGUI(int,int,int);

private:
   std::thread threadTrem;
   int id;
   int x;
   int y;
   int velocidade;
   bool enable;
   int ix;
   int iy;
   int fx;
   int fy;
   vector<Semaforo*> semaforos;

   //colocar aqui o vetor de semaforos
};

#endif // TREM_H



