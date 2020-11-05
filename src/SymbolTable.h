#ifndef SYMBOLTABLE_H
#define SYMBOLTABLE_H

#include <map>
#include <string>
#include <any>
#include "Error.h"
#include "Token.h"

class SymbolTable
{
    public:
        SymbolTable(Token*);
        virtual ~SymbolTable();

        std::map<std::string, double> vars;
        Token* token;

        double getVar(std::string);
        void setVar(std::string, double);


    protected:

    private:
};

#endif // SYMBOLTABLE_H
