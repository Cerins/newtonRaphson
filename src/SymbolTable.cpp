#include "SymbolTable.h"

SymbolTable::SymbolTable(Token* token)
{
    this->token = token;
}

SymbolTable::~SymbolTable()
{
    //dtor
}

double SymbolTable::getVar(std::string name){
    if(vars.count(name) >= 1){
        return vars.at(name);
    }else{
        throw RTError(token->pos_start, token->pos_end,
                "Can't access var " + token->toString());
    }
}

void SymbolTable::setVar(std::string name, double var){
    vars[name] = var;
}
