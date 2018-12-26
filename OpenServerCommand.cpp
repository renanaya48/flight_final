#include "OpenServerCommand.h"

struct socketArgs {
    int port;
    int listenTime;
    CheckConnection* flag;
    FlightValueMap* valuesMap;
    ExitServer* exitServer;
};

OpenServerCommand::OpenServerCommand(CheckConnection* check, FlightValueMap* values, ExitServer* exit) {
    this->isConnected = check;
    this->valueMap = values;
    this->toExit = exit;
}

void* openSocket(void* args) {

    struct socketArgs *arg = (struct socketArgs *) args;
    int sockfd, newsockfd, portno, clilen;
    char buffer[256];
    struct sockaddr_in serv_addr, cli_addr;
    int n;

    /* First call to socket() function */
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    /* Initialize socket structure */
    bzero((char *) &serv_addr, sizeof(serv_addr));
    portno = arg->port;

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons((uint16_t)((size_t)portno));

    /* Now bind the host address using bind() call.*/
    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR on binding");
        exit(1);
    }

    /* Now start listening for the clients, here process will
       * go in sleep mode and will wait for the incoming connection*/
    listen(sockfd, 5);
    clilen = sizeof(cli_addr);

    /* Accept actual connection from the client */
    newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, (socklen_t *) &clilen);
    if (newsockfd < 0) {
        perror("ERROR on accept");
        exit(1);
    }
    arg->flag->setConnect(true);

    /* If connection is established then start communicating */
    while(!arg->exitServer) {
        bzero(buffer,256);
        n = read(newsockfd, buffer, 255);
        string updateMap = buffer;
        arg->valuesMap->updateMap(updateMap);
        //printf("open server: %s\n" ,buffer);
        if (n < 0) {
            perror("ERROR reading from socket");
            exit(1);

        }
        sleep(arg->listenTime);
    }
}

int OpenServerCommand::execute(vector<string>::iterator &vectorIt) {
    int port,time;
    port = stoi(*vectorIt);
    vectorIt++;
    time = stoi(*vectorIt);
    struct socketArgs* arg = new socketArgs();
    arg->port = port;
    arg->listenTime = time;
    arg->flag = this->isConnected;
    arg->valuesMap = this->valueMap;
    arg->exitServer = this->toExit;
    pthread_t pthread;
    pthread_create(&pthread, nullptr, openSocket, arg);
    pthread_detach(pthread);
    vectorIt++;
    return 0;
}