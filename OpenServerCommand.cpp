#include "OpenServerCommand.h"
//struct
struct socketArgs {
    int port;
    int listenTime;
    CheckConnection* flag;
    FlightValueMap* valuesMap;
    ExitServer* exitServer;
};
    /**
     * constructor
     * @param check CheckConnection
     * @param vaules FlightValueMap
     */
OpenServerCommand::OpenServerCommand(CheckConnection* check, FlightValueMap* values, ExitServer* exit) {
    this->isConnected = check;
    this->valueMap = values;
    this->toExit = exit;
}
/**
* open the socket
*@param args arguments
*/
void* openSocket(void* args) {

    struct socketArgs *arg = (struct socketArgs *) args;
    int sockfd, newsockfd, portno, clilen;
    char buffer[256];
    struct sockaddr_in serv_addr, cli_addr;
    int n;

    //  call to socket function
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    
    //if there is a problem open the socket
    if (sockfd < 0) {
        perror("ERROR: unable to open socket");
        exit(1);
    }

    // initialize socket structure 
    bzero((char *) &serv_addr, sizeof(serv_addr));
    portno = arg->port;

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons((uint16_t)((size_t)portno));

    // bind the host address using call bind
    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR: problem on binding");
        exit(1);
    }

    // start listening for the clients, here process will
     //go in sleep mode and will wait for the incoming connection
    listen(sockfd, 5);
    clilen = sizeof(cli_addr);

    // accept actual connection from the client 
    newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, (socklen_t *) &clilen);
    if (newsockfd < 0) {
        perror("ERROR: don't accept");
        exit(1);
    }
    arg->flag->setConnect(true);

    // if connection is established then start communicating 
    while(!arg->exitServer) {
        bzero(buffer,256);
        n = read(newsockfd, buffer, 255);
        string updateMap = buffer;
        arg->valuesMap->updateMap(updateMap);
        //printf("open server: %s\n" ,buffer);
        //if it can't read drom the socket
        if (n < 0) {
            perror("ERROR: can't read from socket");
            exit(1);

        }
        //sleep
        sleep(arg->listenTime);
    }
}
    /**
     * execute
     * @param vectorIt the iterator
     * @return 0 when done
     */
int OpenServerCommand::execute(vector<string>::iterator &vectorIt) {
    int port,time;
    //get the port value by string
    port = stoi(*vectorIt);
    vectorIt++;
    //get the time by number value
    time = stoi(*vectorIt);
    //new struct
    struct socketArgs* arg = new socketArgs();
    //values of the struct
    arg->port = port;
    arg->listenTime = time;
    arg->flag = this->isConnected;
    arg->valuesMap = this->valueMap;
    arg->exitServer = this->toExit;
    pthread_t pthread;
    //create the socket
    pthread_create(&pthread, nullptr, openSocket, arg);
    pthread_detach(pthread);
    vectorIt++;
    return 0;
}
