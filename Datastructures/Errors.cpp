#include "Errors.h"

ValueError::ValueError()
{
    this->mesage = "Incorrect or unmanageable value";
}

ValueError::ValueError(const std::string& mesage, const char* file, int line)
{
    this->mesage = "Error:" + mesage + "\n" + "File: " + file + "\n" + "Line: " + std::to_string(line);
}

const char* ValueError::what() const throw()
{
    return this->mesage.c_str();
}


