#ifndef TOKEN_H
#define TOKEN_H
#include <string>
#include "Position.h"


enum Tokens{
    TT_DOUBLE,
    TT_PLUS,
    TT_MINUS,
    TT_MUL,
    TT_DIV,
    TT_LPAREN,
    TT_RPAREN,
    TT_EQ,
    TT_IDENTIFIER,
    TT_KEYWORD,
    TT_EOF,
    TT_COLON
};

class Token
{
    public:
        Token();
        virtual ~Token();

        Position* pos_start;
        Position* pos_end;

        std::string v;
        int type;
        Token(int, Position*, Position*);
        Token(int, Position*);
        Token(int, std::string, Position*, Position*);
        Token(int, std::string, Position*);

        std::string toString();


    protected:

    private:
};

#endif // TOKEN_H
