#include "ConnectCommand.h"

//struct
struct socketArgs {
    string ip;
    int port;
    CheckConnection* flag;
    StringFlightControls* controlString;
    ExitServer* exitServer;
};
/**
 * constructor
 * @param check CheckConnection
 * @param flightStr  StringFlightControls
 */
ConnectCommand::ConnectCommand(CheckConnection* check, StringFlightControls* flightStr, ExitServer* exit) {
    this->isConnected = check;
    this->flightString = flightStr;
    this->toExit = exit;
}
/**
 * connection client
 * @param args agrs
 * @return
 */
void* connectClient(void* args) {

    struct socketArgs *arg = (struct socketArgs *) args;

    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char buffer[256];
    portno = arg->port;

    /// Create a socket point
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    //if there is a problem open socket
    if (sockfd < 0) {
        perror("ERROR: can't open socket");
        exit(1);
    }
    
    const char *hostName = arg->ip.c_str();
    server = gethostbyname(hostName);
    //there is no such host
    if (server == NULL) {
        fprintf(stderr, "ERROR: no such host");
        exit(0);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *) server->h_addr, (char *) &serv_addr.sin_addr.s_addr,
          server->h_length);
    serv_addr.sin_port = htons(portno);
    //if there is no connection
    while (arg->flag->getConnect() == false) {
        sleep(1);
    }
    // try connect to the server
    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) <
        0) {
        //problem in connection
        perror("ERROR: connecting");
        exit(1);
    }

    while(!arg->exitServer) {
        bzero(buffer, 256);
        //there are still arguments
        while(!arg->controlString->isEmpty()){
            strcpy(buffer, arg->controlString->getControl().c_str());
           // cout << buffer <<endl;
            ssize_t ssize = write(sockfd, buffer, strlen(buffer));
            //problem to write to the socket
            if (ssize < 0) {
                perror("ERROR: problem writing to socket");
                exit(1);
            }
            arg->controlString->setControl("");
        }
    }
    //close(sockfd);
    delete arg;
}
/**
 *
 * @param vectorIt the iterator
 * @return 0 when done
 */
int ConnectCommand::execute(vector<string>::iterator &vectorIt) {
    int port;
    string ip;
    //get the ip
    ip = *vectorIt;
    //move the iterator +1
    vectorIt++;
    //get the number value of the port
    port = stoi(*vectorIt);
    struct socketArgs* arg = new socketArgs();
    //put the values in the struct
    arg->port = port;
    arg->ip = ip;
    arg->flag = isConnected;
    arg->controlString = this->flightString;
    arg->exitServer = this->toExit;
    pthread_t pthread;
    //create
    pthread_create(&pthread, nullptr, connectClient, arg);
    pthread_detach(pthread);
    vectorIt++;
    return 0;
}
