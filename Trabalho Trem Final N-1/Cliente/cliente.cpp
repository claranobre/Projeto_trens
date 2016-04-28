#include <cstdio>       //printf
#include <cstring>      //memset
#include <cstdlib>      //exit
#include <netinet/in.h> //htons
#include <arpa/inet.h>  //inet_addr
#include <sys/socket.h> //socket
#include <unistd.h>     //close
#include <iostream>

struct Comando {
    int id;
    int velocidade;
    bool enable;
};

#define PORTNUM 4325

int main(int argc, char *argv[])
{   

    bool controle = true;
    char com;
    struct sockaddr_in endereco;
    int socketId;
 
    Comando comando;
    comando.id = 0; // ID padrão: 0 = todos.
    comando.velocidade = 200; //Velocidade padrão
    comando.enable = true; //Enabled padrão

    int bytesenviados;
    /*
     * Configurações do endereço
    */
    memset(&endereco, 0, sizeof(endereco));
    endereco.sin_family = AF_INET;
    endereco.sin_port = htons((short int)(PORTNUM));
    endereco.sin_addr.s_addr = inet_addr("127.0.0.1");
    
    while(controle){
        std::cout << "----------------\n";
        std::cout << "Comandos atuais: ID: " << comando.id << ".\n";
        std::cout << "Velocidade: " << comando.velocidade << ".\n"; 
        std::cout << "Enabled: " << comando.enable << ".\n";
        std::cout << "----------------\n";
        std::cout << "Lista de comandos:\n";
        std::cout << "i: Setar ID do comando.\n";
        std::cout << "v: Setar velocidade.\n";
        std::cout << "e: Setar enabled/disabled.\n";
        std::cout << "s: Enviar comando.\n";
        std::cout << "x: Sair do programa de controle.\n";
        std::cin >> com;
        switch(com){
            case 'I':
            case 'i':
                std::cout << "Sete o ID de 0 até 6 (0 para todos).\n";
                std::cin >> comando.id;
                break;
            case 'V':
            case 'v':
                std::cout << "Sete a velocidade de 40 até 300.\n";
                std::cin >> comando.velocidade;
                break;
            case 'e':
            case 'E':
                comando.enable = !comando.enable;
                std::cout << "Você inverteu o enabled.\n";
                break;
            case 'S':
            case 's':
                /*
                 * Criando o Socket
                 *
                */
                 socketId = socket(AF_INET, SOCK_STREAM, 0);
            
                //Verificar erros
                if (socketId == -1)
                {
                    printf("Falha ao executar socket()\n");
                    exit(EXIT_FAILURE);
                }
             
                //Conectando o socket cliente ao socket servidor
                if ( connect (socketId, (struct sockaddr *)&endereco, sizeof(struct sockaddr)) == -1 )
                {
                    printf("Falha ao executar connect()\n");
                    exit(EXIT_FAILURE);
                }
                printf ("Cliente conectado ao servidor\n");
             
                //Enviar uma msg para o cliente que se conectou
                printf("Cliente vai enviar uma mensagem\n");
                bytesenviados = send(socketId, &comando,sizeof(comando),0);
             
                if (bytesenviados == -1)
                {
                    printf("Falha ao executar send()");
                    exit(EXIT_FAILURE);
                }
                //printf("Cliente enviou a seguinte msg (%d bytes) para o servidor: %d \n",bytesenviados, mensagem.id);
             
                close(socketId);
            break;
            case 'X':
            case 'x':
                controle = !controle;
                break;
            default:
                break;
        }
        std::system("clear");
    }
    return 0;
}