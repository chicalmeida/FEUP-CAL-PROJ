#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <iostream>
#include <exception>

class Exception : public exception {
private:
    std::string explanation;
public:
    Exception(std::string ex) {explanation = ex;}
    virtual const char* what() const throw(){return explanation.c_str();}
};

class ReadingDataException : public Exception {
public:
    ReadingDataException(std::string ex) : Exception("Error reading " + ex + "Data "){}

};

#endif //EXCEPTIONS_H
