#include "Token.h"

Token::Token(int type, Position* pos_start, Position* pos_end)
{
    this->type = type;
    this->pos_start = pos_start;
    this->pos_end = pos_end;
}

Token::Token(int type, Position* pos_start)
{
    this->type = type;
    this->pos_start = pos_start;
    Position* temp = pos_start->copyDynamic();
    temp->advance(' ');
    this->pos_end = temp;

}

Token::Token(int type, std::string v, Position* pos_start, Position* pos_end)
{
    this->type = type;
    this->pos_start = pos_start;
    this->pos_end = pos_end;

    this->v = v;
}

Token::Token(int type, std::string v, Position* pos_start)
{
    this->type = type;
    this->pos_start = pos_start;
    Position* temp = pos_start->copyDynamic();
    temp->advance(' ');
    this->pos_end = temp;

    this->v = v;



}

std::string Token::toString(){
    return (get_Name[this->type] + ":" + v);
}

Token::~Token()
{
   delete pos_start;
   delete pos_end;
}
