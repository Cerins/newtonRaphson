#include <iostream>
#include "Lexer.h"
#include "Token.h"
#include <vector>


using namespace std;

int main(){
    cout << "Hello world!" << endl;
    while(true){
        std::string s;
        std::cin >> s;
        Lexer l("<stdin>", s);
        std::vector<Token*> tok = l.make_tokens();

        for(auto t: tok){
            std::cout << t->toString() << std::endl;
            delete t;
        }
        tok.clear();




    }
    return 0;
}
