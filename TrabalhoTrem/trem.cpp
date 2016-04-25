#include "trem.h"
#include <QtCore>
#include <QMutex>

QMutex semaforo[8];

Trem::Trem(int id, int x, int y)
{
    this->id = id;
    this->x = x;
    this->y = y;
    velocidade = 250;
    enable = true;
}

Trem::~Trem()
{
    thread.join();
}

void Trem::setVelocidade(int velocidade)
{
    this->velocidade = velocidade;
}

void Trem::setEnable(bool enable)
{
    this->enable = enable;
}

void Trem::start()
{
    threadTrem = std::thread(&Trem::run,this);
}

void Trem::run()
{
    while(true){
        switch(id){
        case 1:
            if (enable)
            {
                emit updateGUI(id,x,y);
                if (y == 120 && x <290)
                    semaforo[0].lock();
                    semaforo[1].lock();
                    semaforo[2].lock();
                    x+=10;
                else if (x == 290 && y < 220)
                    semaforo[3].lock();
                    semaforo[4].lock();
                    semaforo[5].lock();
                    y+=10;
                else if (x > 150 && y == 220)
                    semaforo[0].lock();
                    semaforo[2].lock();
                    semaforo[4].lock();
                    semaforo[5].lock();
                    x-=10;
                else
                    y-=10;
            }
            break;
        case 2:
            //emit updateGUI(id, x,y);
            break;
        default:
            break;
        }
        this_thread::sleep_for(chrono::milliseconds(velocidade));
    }
}

void Trem::parar_retomar()
{
    enable = !enable;
}

void Trem::mudar_velocidade(int velocidade)
{
    velocidade = velocidade;
}
