#ifndef PROJECT1_BINDMAP_H
#define PROJECT1_BINDMAP_H

#include <string>
#include<map>

using namespace std;
/**
*PathMap
*/
class PathMap {
    //member
    map<string,string> pathMap;
public:
    /**
     * constructor
     */
    PathMap(){}
        /**
     * add to the map
     * @param key the key to insert
     * @param value the value to add
     */
    void addToPathMap(string key, string value) {
        this->pathMap.insert(pair<string,string> (key,value));
    }
    //string getBindMap(string key) const;
    //bool isInMap(string key) const;
        /**
     * the function returns the map
     * @return the map
     */
    map<string,string> getBindMap(){
        return this->pathMap;
    }

};

#endif //PROJECT1_BINDMAP_H
