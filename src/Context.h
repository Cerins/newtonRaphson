#ifndef CONTEXT_H
#define CONTEXT_H

#include <string>
#include "SymbolTable.h"

class SymbolTable;

class Context
{
    public:

        std::string displayName;
        SymbolTable* table = nullptr;

        Context();
        virtual ~Context();

    protected:

    private:
};

#endif // CONTEXT_H
