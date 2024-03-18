#ifndef ERRORS_H
#define ERRORS_H

#include <iostream>
#include <string>

class ValueError : public std::exception 
{
private:
    std::string mesage;   

public:
    ValueError();
    ValueError(const std::string& mesage, const char* file, int line);
    const char* what() const throw() override;
};



#endif
