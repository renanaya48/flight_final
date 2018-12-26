#ifndef PROJECT1_EXITSERVER_H
#define PROJECT1_EXITSERVER_H


class ExitServer {
    bool toExit;

public:
    ExitServer(){
        this->toExit = false;
    }
    void setExit(bool flag){
        this->toExit  = flag;
    }
    bool getExit() const{
        return this->toExit;
    }
    ~ExitServer(){}
};


#endif //PROJECT1_EXITSERVER_H
