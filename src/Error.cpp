#include "Error.h"

Error::Error()
{
    //ctor
}

Error::~Error()
{
    delete pos_start;
    delete pos_end;
}



Error::Error(Position* pos_start, Position* pos_end, std::string error_name, std::string details)
{
    this->pos_start = pos_start;
    this->pos_end = pos_end;
    this->error_name = error_name;
    this->details = details;
}
Error::Error(Position* pos_start, std::string error_name, std::string details)
{
    this->pos_start = pos_start;
    Position* en = pos_start->copyDynamic();
    en->advance(' ');
    this->pos_end = en;
    this->error_name = error_name;
    this->details = details;


}

IllegalCharError::IllegalCharError(Position* pos_start, Position* pos_end, std::string details): Error(pos_start,pos_end,"IllegalCharError",details) {}
IllegalCharError::IllegalCharError(Position* pos_start, std::string details): Error(pos_start, "IllegalCharError",details) {}

InvalidSyntaxError::InvalidSyntaxError(Position* pos_start, Position* pos_end, std::string details): Error(pos_start,pos_end,"InvalidSyntaxError",details) {}
InvalidSyntaxError::InvalidSyntaxError(Position* pos_start, std::string details): Error(pos_start,"InvalidSyntaxError",details) {}

RTError::RTError(Position* pos_start, Position* pos_end, std::string details): Error(pos_start,pos_end,"RTError",details) {}
RTError::RTError(Position* pos_start, std::string details): Error(pos_start,"RTError",details) {}
