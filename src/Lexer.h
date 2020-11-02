#ifndef LEXER_H
#define LEXER_H
#include <string>
#include <vector>
#include "Position.h"
#include "Token.h"
#include "Error.h"
#include <iostream>
#include <cstring>



class Lexer
{
    public:
        Lexer(std::string, std::string);
        virtual ~Lexer();

        std::string fn;
        std::string text;
        Position* pos;
        char current_char;
        std::vector<Token*> make_tokens();
        Token* make_number();
        Token* make_identifier();
        Token* make_string();
        void advance();



    protected:

    private:
};

#endif // LEXER_H
