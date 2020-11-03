#include <iostream>
#include "Lexer.h"
#include "Token.h"
#include <vector>
#include "Error.h"

using namespace std;

int main(){
    while(true){
        std::cout << ">";
        std::string s;
        std::cin >> s;
        Lexer l("<stdin>", s);
        try{
            std::vector<Token*> tok = l.make_tokens();

            for(auto t: tok){
                std::cout << t->toString() << std::endl;
                delete t;
            }
            tok.clear();
        }catch(Error& e){
            std::cout << e.what() << std::endl;
        }



    }
    return 0;
}
