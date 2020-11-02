#ifndef LEXER_H
#define LEXER_H
#include <string>
#include <vector>
#include "Position.h"
#include "Token.h"



class Lexer
{
    public:
        Lexer();
        virtual ~Lexer();

        Position* pos_start;
        Position* pos_end;



    protected:

    private:
};

#endif // LEXER_H
