#ifndef PROJECT1_EXITSERVER_H
#define PROJECT1_EXITSERVER_H

/**
*ExitServer class
*/

class ExitServer {
    //member
    bool toExit;

public:
    /**
    * constructor
    */
    ExitServer(){
        this->toExit = false;
    }
    /**
    * @param flag- change the exit type
    */
    void setExit(bool flag){
        this->toExit  = flag;
    }
    /**
    *@ return to exit or not
    */
    bool getExit() const{
        return this->toExit;
    }
    /**
    * distructor
    */
    ~ExitServer(){}
};


#endif //PROJECT1_EXITSERVER_H
