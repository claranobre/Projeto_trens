#ifndef THREAD_H
#define THREAD_H

#include <thread>
#include <QObject>

using namespace std;

class Thread : public QObject
{
    Q_OBJECT
private:
    //Função auxiliar da Thread
    static void* funcaoHelper(void*);

    //Posix thread da classe
    thread_t thread;

public:
    //Construtor
    Thread();

    //Destrutor virtual
    virtual ~Thread();

    //Inicialização virutal
    virtual void run() = 0;

    //Função para bloquear a thread até ela ser finalizada
    int wait();

    //Retorna a thread da classe
    thread_t getThread () const;
}

#endif // THREAD_H
