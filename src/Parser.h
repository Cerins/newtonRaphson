#ifndef PARSER_H
#define PARSER_H

#include <string>
#include "Lexer.h"
#include "AST.h"
#include <iostream>

class Parser
{
    public:
        Parser();
        virtual ~Parser();

        Lexer* lexer;
        Token* current_token;
        int place = 0;
        Parser(Lexer*);
        void eat(int);
        void goBack();
        Node* factor();
        Node* term();
        Node* expr();

    protected:

    private:
};

#endif // PARSER_H
