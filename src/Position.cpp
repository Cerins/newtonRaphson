#include "Position.h"

Position::Position(int idx, int ln, int col, std::string fn, std::string ftxt){
    this->idx = idx;
    this->ln = ln;
    this->col = col;
    this->fn = fn;
    this->ftxt = ftxt;
}

Position::~Position(){

}

void Position::advance(char current_char){
    this->idx++;
    this->col++;

    if(current_char == '\n'){
        this->ln++;
        this->col = 0;
    }
}

Position Position::copy(){
    return Position(idx, ln, col, fn, ftxt);
}
Position* Position::copyDynamic(){
    return new Position(idx, ln, col, fn, ftxt);
}
