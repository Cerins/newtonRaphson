#ifndef ERROR_H
#define ERROR_H
#include <string>
#include <ostream>
#include "Position.h"
#include <any>
#include <exception>
#include <iostream>

class Error
{
    public:
        Error();
        virtual ~Error();

        Position* pos_start;
        Position* pos_end;

        std::string error_name;
        std::string details;

        Error(Position*, Position*, std::string, std::string);
        Error(Position*, std::string, std::string);

        Error create(){
            return Error(pos_start, pos_end, error_name, details);
        }
        std::string what () throw ()
        {
            std::string s = error_name + ": " + details + "\n"+
            "File " + (pos_start->fn) + ", line " + std::to_string((pos_start->ln+1));
            return s;
        }


    protected:

    private:
};

class IllegalCharError: public Error{
    public:
        IllegalCharError(Position*, Position*, std::string);
        IllegalCharError( Position*, std::string);
};

class InvalidSyntaxError: public Error{
    public:
        InvalidSyntaxError(Position*, Position*, std::string);
        InvalidSyntaxError(Position*, std::string);
};

class RTError: public Error{
    public:
        RTError(Position*, Position*, std::string);
        RTError(Position*, std::string);

};

#endif // ERROR_H
