#include "socket.h"

Socket::Socket(int portnum = 4325, char* ip = "127.0.0.1"){
    this->portnum = portnum;
    this->ip = ip;
    this->ligado = false;
    this->pass = false;
    this->comando.id = 0;
    this->comando.velocidade = 200;
    this->comando.enable = 1;
}

Socket::~Socket(){
    connect.join();
}


void Socket::setIp(char* ip){
    this->ip = ip;
}

void Socket::setPort(int port){
    this->portnum = port;
}

void Socket::changeStat(bool set){
    this->ligado = set;
}

void Socket::socketHandler(int socketDescriptor, Comando comando)
{
    int byteslidos;
    //Verificando erros
    if ( socketDescriptor == -1)
    {
        printf("Falha ao executar accept()");
        exit(EXIT_FAILURE);
    }

    //receber uma msg do cliente
    //printf("Servidor vai ficar esperando uma mensagem\n");
    byteslidos = recv(socketDescriptor,&comando,sizeof(comando),0);
    if (byteslidos == -1)
    {
        printf("Falha ao executar recv()");
        exit(EXIT_FAILURE);
    }
    else if (byteslidos == 0)
    {
        printf("Cliente finalizou a conexão\n");
        exit(EXIT_SUCCESS);
    }

    cout << "Servidor recebeu os seguintes dados do cliente: " << endl;
    cout << comando.id << endl;
    cout << comando.velocidade << endl;
    cout << comando.enable << endl;

    this->comando.id = comando.id;
    this->comando.velocidade = comando.velocidade;
    this->comando.enable = comando.enable;
    emit update();
    close(socketDescriptor);
}

void Socket::start()
{
    connect = std::thread(&Socket::run,this);
}

void Socket::run(){

    struct sockaddr_in endereco;
    int socketId;

    //variáveis relacionadas com as conexões clientes
    struct sockaddr_in enderecoCliente;
    socklen_t tamanhoEnderecoCliente = sizeof(struct sockaddr);
    int conexaoClienteId;

    //mensagem enviada pelo cliente
    Comando *comando;

    /*
     * Configurações do endereço
    */
    memset(&endereco, 0, sizeof(endereco));
    endereco.sin_family = AF_INET;
    endereco.sin_port = htons(this->portnum);
    //endereco.sin_addr.s_addr = INADDR_ANY;
    endereco.sin_addr.s_addr = inet_addr(this->ip);

    /*
     * Criando o Socket
     *
     * PARAM1: AF_INET ou AF_INET6 (IPV4 ou IPV6)
     * PARAM2: SOCK_STREAM ou SOCK_DGRAM
     * PARAM3: protocolo (IP, UDP, TCP, etc). Valor 0 escolhe automaticamente
    */
    socketId = socket(AF_INET, SOCK_STREAM, 0);

    //Verificar erros
    if (socketId == -1)
    {
        printf("Falha ao executar socket()\n");
        //exit(EXIT_FAILURE);
        return;
    }

    //Conectando o socket a uma porta. Executado apenas no lado servidor
    if ( bind (socketId, (struct sockaddr *)&endereco, sizeof(struct sockaddr)) == -1 )
    {
        printf("Falha ao executar bind()\n");
        //exit(EXIT_FAILURE);
        return;
    }

    //Habilitando o servidor a receber conexoes do cliente
    if ( listen( socketId, 10 ) == -1)
    {
        printf("Falha ao executar listen()\n");
        //exit(EXIT_FAILURE);
        return;
    }
    this->ligado = true;
    cout << "Abrindo conexão em" << this->ip << " na porta " << this->portnum << ".";
    while(this->ligado)
    {

        cout << "Servidor: esperando conexões clientes\n";
        //Servidor fica bloqueado esperando uma conexão do cliente
        conexaoClienteId = accept( socketId,(struct sockaddr *) &enderecoCliente,&tamanhoEnderecoCliente );

        printf("Servidor: recebeu conexão de %s\n", inet_ntoa(enderecoCliente.sin_addr));

        //disparar a thread
        std::thread t(&Socket::socketHandler, this, conexaoClienteId, *comando);
        t.detach();
        //this->pass = false;
    }
}
