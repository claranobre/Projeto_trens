#include "trem.h"
#include <QtCore>
#include <QMutex>

QMutex semaforo[8];

/*
 * Método Trem
*/

Trem::Trem(int id, int x, int y, int ix, int iy, int fx, int fy, vector<Semaforo*> semaforos )
{
    this->id = id;
    this->x = x;
    this->y = y;
    this->ix = ix;
    this->iy = iy;
    this->fx = fx;
    this->fy = fy;
    this->semaforos = semaforos;
    velocidade = 200; //milisegundos
    enable = true;
}

Trem::~Trem()
{
    threadTrem.join();
}

/*
 * Criação da Thread "run"
*/
void Trem::start()
{
    switch(id){
        case 1:
            threadTrem = std::thread(&Trem::run1,this);
            break;
        case 2:
            threadTrem = std::thread(&Trem::run2,this);
            break;
        case 3:
            threadTrem = std::thread(&Trem::run3,this);
            break;
        case 4:
            threadTrem = std::thread(&Trem::run4,this);
            break;
        case 5:
            threadTrem = std::thread(&Trem::run5,this);
            break;
        case 6:
            threadTrem = std::thread(&Trem::run6,this);
            break;
        }
    }
    //threadTrem = std::thread(&Trem::run,this);

/*
 * Movimentação dos trens
*/
void Trem::move(){

    /*
     * Sentido horario
     */
    if(id==1 || id==3 || id==5 || id==6){
        if (enable)
        {
            emit updateGUI(id,x,y);
            if (y == iy && x <fx)
                x+=10;
            else if (x == fx && y < fy)
                y+=10;
            else if (x > ix && y == fy)
                x-=10;
            else
                y-=10;
        }
    }

    /*
     * Sentido anti-horario
     */
    else{
        if(id==2 || id==4){
            if (enable)
            {
                emit updateGUI(id,x,y);
                if (y == iy && x > ix)
                    x-=10;
                else if (x == ix && y < fy)
                    y+=10;
                else if (x < fx && y == fy)
                    x+=10;
                else
                    y-=10;
            }
        }
    }
}

/*
 * Trens_ação
 */
void Trem::run1(){

    while(true){
        /*
         * Sentido horario
         */
        move();

        //Se chegar na primeira regiao critica
        if( x ==170 && y == 20){
            //da P()  em S2
            semaforos.at(2)->P();
            //da P()  em S0
            semaforos.at(0)->P();
        }

        //Passou pela primeira regiao critica e a libera
        else if (x  == 170 && y == 120){
            //da V() em S0
            semaforos.at(0)->V();
        }

        //Passou pela ultima regiao critia e a libera
        else if (x  == 100 && y == 120){
            //da V() em S2
            semaforos.at(2)->V();
        }

        this_thread::sleep_for(chrono::milliseconds(velocidade));
    }
}

void Trem::run2(){

    while(true){
        /*
         * Sentido anti-horário
         */
        move();

        //Chega na primeira região critia
        if (x == 200 && y == 20){
            //da P() em s1
            semaforos.at(1)->P();
            //da P() em s3
            semaforos.at(3)->P();
            //da P() em s0
            semaforos.at(0)->P();
        }

        //Passou pela primeira regiao critia e a libera
        else if (x == 200 && y == 120){
            //da v() em s0
            semaforos.at(0)->V();
        }

        //Passou pela segunda regiao critica e a libera
        else if (x == 330 && y == 110){
            //da v() em s3
            semaforos.at(3)->V();
        }

        //Passou pela ultima regiao critica e a libera
        else if (x == 320 && y == 20){
            //da P() em s1
            semaforos.at(1)->V();
        }

        this_thread::sleep_for(chrono::milliseconds(velocidade));
    }
}

void Trem::run3(){

    while(true){
        /*
         * Sentido horário
         */
        move();

        //Chegando na primeira regiao critica
        if( x ==420 && y == 120){
            //da P()  em S1
            semaforos.at(1)->P();
            //da P()  em S4
            semaforos.at(4)->P();
        }

        //Passou pela primeira regiao critica e a libera
        else if (x  == 340 && y == 110){
            //da V() em S4
            semaforos.at(4)->V();
        }

        //Passou pela ultima regiao critica e a libera
        else if (x  == 350 && y == 20){
            //da V() em S1
            semaforos.at(1)->V();
        }

        this_thread::sleep_for(chrono::milliseconds(velocidade));
    }
}

void Trem::run4(){

    while(true){
        /*
         * Sentido anti-horário
         */
        move();

        //trajeto superior
        //Chegou na primeira zona critica
        if (x == 400 && y == 140){
            //da P() em s2
            semaforos.at(2)->P();
            //da P() em s3
            semaforos.at(3)->P();
            //da P() em s4
            semaforos.at(4)->P();
        }

        //Passou pela primeira zona critica e a libera
        else if (x == 320 && y == 130){
            //da v() em s4
            semaforos.at(4)->V();
        }

        //Passou pela segunda zona critica e a libera
        else if (x == 170 && y == 130){
            //da v() em s3
            semaforos.at(3)->V();
        }

        //Passou pela ultima zona crítica e a libera
        else if (x == 120 && y == 140){
            //da P() em s2
            semaforos.at(2)->V();
        }

        //trajeto inferior
        //Chegou na primeira zona critica
        else if( x ==120 && y == 270){
            //da P()  em S6
            semaforos.at(6)->P();
            //da P()  em S5
            semaforos.at(5)->P();
        }

        //Passou pela primeira zona critica e a libera
        else if (x  == 280 && y == 280){
            //da V() em S5
            semaforos.at(5)->V();
        }

        //Passou pela ultima zona critica e a libera
        else if (x  == 400 && y == 270){
            //da V() em S6
            semaforos.at(6)->V();
        }

        this_thread::sleep_for(chrono::milliseconds(velocidade));
    }
}

void Trem::run5(){
    while(true){
        /*
         * Sentido horario
         */
        move();

        //Chegou na primeira zona critica
        if( x ==100 && y == 290){
            //da P()  em S7
            semaforos.at(7)->P();
            //da P()  em S5
            semaforos.at(5)->P();
        }

        //passou pela primeira zona critica e a libera
        else if (x  == 260 && y == 310){
            //da V() em S5
            semaforos.at(5)->V();
        }

        //Passou pela ultima zona critica e a libera
        else if (x  == 240 && y == 390){
            //da V() em S7
            semaforos.at(7)->V();
        }

        this_thread::sleep_for(chrono::milliseconds(velocidade));
    }
}

void Trem::run6(){
    while(true){
        /*
         * Sentido horario
         */
        move();

        //Chegou na primeira zona critica
        if( x ==280 && y == 390){
            //da P()  em S6
            semaforos.at(6)->P();
            //da P()  em S7
            semaforos.at(7)->P();
        }

        //Passou pela primeira zona critica e a libera
        else if (x  == 280 && y == 290){
            //da V() em S7
            semaforos.at(7)->V();
        }

        //Passou pela ultima zona critica e a libera
        else if (x  == 430 && y == 290){
            //da V() em S6
            semaforos.at(6)->V();
        }
        this_thread::sleep_for(chrono::milliseconds(velocidade));
    }
}

void Trem::setVelocidade(int velocidade)
{
    this->velocidade = velocidade;
}

void Trem::setEnable(bool enable)
{
    this->enable = enable;
}
