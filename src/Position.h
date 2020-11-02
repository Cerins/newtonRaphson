#ifndef POSITION_H
#define POSITION_H
#include <string>

class Position{
    public:
        Position(int, int, int, std::string, std::string);
        virtual ~Position();

        int idx;
        int ln;
        int col;
        std::string fn;
        std::string ftxt;
        void advance(char);
        Position copy();
        Position* copyDynamic();

    protected:

    private:
};

#endif // POSITION_H
