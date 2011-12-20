#include <sstream>
#include <iostream>
#include <fstream>
#include <string>

#include "Tokenizer.h"


/**
    @author J.Michalski
    @version beta 0.2
*/

int main(int argc, char* argv[])
{

    if(argc<2)
    {
        std::cout << "FUN interpreter Beta 0.2" << std::endl;
        std::cout << "Not found source file; Going into interactive mode:" << std::endl;
        std::cout << "To exit type \"\\q\"" << std::endl << std::endl;

        std::string tmp;
        Tokenizer* tok = NULL;
        Token* token = NULL;

        while(std::getline(std::cin, tmp) && tmp!="\\q")
        {
            std::istringstream in(tmp);
            tok = new Tokenizer(in);
            token = tok->getToken();//only for test purposes
            while(token != NULL) //only for test purposes
            {
                switch(token->getType())
                {
                    case NAME:
                        std::cout << " " << ((Name*)token)->value << std::endl;
                        break;
                    case NUMBER:
                        std::cout << " " << ((Number*)token)->value << std::endl;
                        break;
                    case OPERATOR:
                        std::cout << " " << ((Operator*)token)->value << std::endl;
                        break;
                }
                delete token;
                token = tok->getToken();
            } //end of test purposes
            delete token;
            delete tok;
        }
    }
    else
    {
        std::ifstream file(argv[1]);

        Tokenizer* tok = new Tokenizer(file);

        /** for the time being **/
        Token* token = tok->getToken(); //only for test purposes
        while(token != NULL) //only for test purposes
        {
            switch(token->getType())
            {
                case NAME:
                    std::cout << " " << ((Name*)token)->value << std::endl;
                    break;
                case NUMBER:
                    std::cout << " " << ((Number*)token)->value << std::endl;
                    break;
                case OPERATOR:
                    std::cout << " " << ((Operator*)token)->value << std::endl;
                    break;
            }
            delete token;
            token = tok->getToken();
        } //end of test purposes
        delete token;
        /** endof for the time being **/

        delete tok;
    }
    return 0;
}
