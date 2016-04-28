#ifndef TREM_H
#define TREM_H

#include <QThread>

using namespace std;

class Trem : public QThread
{
    Q_OBJECT
public:
    Trem(int,int,int);
    ~Trem();
    void start();
    void run();
    void setVelocidade(int);
    void setEnable(bool);
    void parar_retomar();
    void mudar_velocidade(int);

signals:
    void updateGUI(int,int,int);

private:
   std::thread thread;
   int id;
   int x;
   int y;
   int velocidade;
   bool enable; //stop
};

#endif // TREM_H



