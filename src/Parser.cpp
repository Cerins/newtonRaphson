#include "Parser.h"

Parser::Parser(Lexer* lexer)
{
    this->lexer = lexer;
    tokens = (this->lexer->make_tokens());
    current_token = tokens[0];
    place = 0;
}

Parser::~Parser()
{
    for(auto t: tokens){
        delete t;
    }
    tokens.clear();
}

void Parser::eat(int tips){
    if(current_token->type == tips){
        place++;
        if(place >= tokens.size()){
            place = tokens.size()-1;
        }
        current_token = tokens[place];
    }else{
        throw InvalidSyntaxError(current_token->pos_start, current_token->pos_end,
        "Expected " + std::string(current_token->get_Name[tips]) + " , got " + std::string(current_token->get_Name[current_token->type]));
    }
}

void Parser::goBack(){
    if(place>0){
        place--;
        current_token = tokens[place];
    }else{
     throw "Unexpected attemp to go back in the token array";
    }
}
