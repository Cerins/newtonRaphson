#include "Lexer.h"


bool isLetter(char ch){
    if(ch >= 'a' && ch <= 'z'){
        return true;
    }else if(ch >= 'A' && ch <= 'Z'){
        return true;
    }else{
        return false;
    }
}

bool isDigit(char ch){
    if(ch >= '0' && ch <= '9'){
        return true;
    }else{
        return false;
    }
}

Lexer::Lexer(std::string fn, std::string text){
    this->fn = fn;
    this->text = text;
    this->pos = new Position(-1, 0, -1, fn, text);
    this->current_char = 0;
    this->advance();

}

Lexer::~Lexer(){
    delete pos;
}

std::vector<Token*>  Lexer::make_tokens(){
    std::vector<Token*> tokens;

    while(current_char != 0){

        if(current_char == '\t' or current_char == ' '){
            advance();
        }else if(current_char <='9' && current_char >= '0'){
            tokens.push_back(make_number());
        }
        else if(isLetter(current_char)){
            tokens.push_back(make_identifier());
        }else if(current_char == '+'){
            tokens.push_back(new Token(TT_PLUS, pos->copyDynamic()));
            advance();
        }else if(current_char == '-'){
            tokens.push_back(new Token(TT_MINUS, pos->copyDynamic()));
            advance();
        }else if(current_char == '*'){
            tokens.push_back(new Token(TT_MUL, pos->copyDynamic()));
            advance();
        }else if(current_char == '/'){
            tokens.push_back(new Token(TT_DIV, pos->copyDynamic()));
            advance();
        }else if(current_char == '('){
            tokens.push_back(new Token(TT_LPAREN, pos->copyDynamic()));
            advance();
        }else if(current_char == ')'){
            tokens.push_back(new Token(TT_RPAREN, pos->copyDynamic()));
            advance();
        }else if(current_char == ':'){
            tokens.push_back(new Token(TT_COLON, pos->copyDynamic()));
            advance();
        }else if(current_char == '='){
            tokens.push_back(new Token(TT_EQ, pos->copyDynamic()));
            advance();
        }else{
            Position* pos_start = pos->copyDynamic();
            char ch = current_char;
            advance();
            std::vector<Token*> emp;
            throw IllegalCharError(pos_start, pos->copyDynamic(), &ch);
            return emp;
        }
    }
    tokens.push_back(new Token(TT_EOF, pos->copyDynamic()));
    return tokens;
}

void Lexer::advance(){
    pos->advance(current_char);
    if(pos->idx < text.length()){
        current_char = text[pos->idx];
    }else{
        current_char = 0;
    }
}

Token* Lexer::make_number(){
    std::string num_str = "";
    int dot_count = 0;

    while(current_char != 0 && ((current_char >= '0' && current_char <= '9') || current_char == '.')){
        if(current_char == '.'){
            if(dot_count == 1) break;
            dot_count += 1;
            num_str += '.';
        }else{
            num_str += current_char;
        }
        advance();
    }
    return new Token(TT_DOUBLE, num_str, pos->copyDynamic());

}


Token* Lexer::make_identifier(){
    std::string id_str = "";
    Position* pos_start = pos->copyDynamic();

    while(current_char != 0 && (isLetter(current_char) || current_char == '_')){
        id_str += current_char;
        advance();
    }
    int tok_type = TT_IDENTIFIER;
    const char *keywords[1] = {"solve"};
    for(int i =0; i < 1;i++){

        if(std::strcmp( id_str.c_str(), keywords[i]) == 0){
            return new Token(TT_KEYWORD, id_str, pos_start);
        }
    }
    return new Token(tok_type, id_str, pos_start);

}



