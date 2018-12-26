#ifndef PROJECT1_CHECKCONNECTION_H
#define PROJECT1_CHECKCONNECTION_H


class CheckConnection {
    bool isConnected;

public:
    CheckConnection(){
        this->isConnected = false;
    }
    void setConnect(bool flag){
        this->isConnected  = flag;
    }
    bool getConnect() const{
        return this->isConnected;
    }

    ~CheckConnection(){}
};

#endif //PROJECT1_CHECKCONNECTION_H
