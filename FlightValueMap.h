#ifndef PROJECT1_FLIGHTVALUEMAP_H
#define PROJECT1_FLIGHTVALUEMAP_H

#include <map>
#include <string>
#include <iostream>
#include <string.h>

using namespace std;
/**
* FlightValueMap class
*/
class FlightValueMap {
    //member
    map<string,double> mapOfFlightValue;
public:
    /**
    * constructor
    */
    FlightValueMap() {
        this->initalize();
    }
    /**
     * initalize the map
     */
    void initalize();
        /**
     * update the map according to the string
     * @param values  the value to update to
     */
    void updateMap(string values);
     /**
     *
     * @return the map
     */
    map<string,double> getFlightVauleMap();
    /**
    * distructor
    */
    ~FlightValueMap(){}


};


#endif //PROJECT1_FLIGHTVALUEMAP_H
