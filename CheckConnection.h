#ifndef PROJECT1_CHECKCONNECTION_H
#define PROJECT1_CHECKCONNECTION_H

/**
 *  CheckConnection class.
 */
class CheckConnection {
    //member
    bool isConnected;

public:
     /**
     * construstor
     */
    CheckConnection(){
        this->isConnected = false;
    }
    /**
     * set the connection according to the flag
     * @param flag the new value
     */
    void setConnect(bool flag){
        this->isConnected  = flag;
    }
     /**
     * get the connection status
     * @return the connection status
     */
    bool getConnect() const{
        return this->isConnected;
    }
    /**
    * distructor
    */
    ~CheckConnection(){}
};

#endif //PROJECT1_CHECKCONNECTION_H
