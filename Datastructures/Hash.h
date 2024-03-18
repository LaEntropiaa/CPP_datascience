#ifndef HASH_H
#define HASH_H

#include <vector>
#include <utility>
#include <string>
#include <exception>

template <class T>
class Htable {
private:
    const double C = 1.0 / 1.618033988749895;
    std::vector<std::pair<T, std::string>> list;
    int size;
    int objects = 0;

public:
    Htable(){}
    Htable(int size) 
    {
        if (size > 0) 
        {
            this->size = size
        }
        
    }


};

#endif 

