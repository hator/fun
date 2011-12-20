#ifndef TOKENIZER_H
#define TOKENIZER_H

#include <sstream>
#include <string>
#include "Token.h"

class Tokenizer
{
    public:
        Tokenizer(std::istream &_input);
        virtual ~Tokenizer();

        Token* getToken();
    private:
        void skipWhitespace();
        void skipLine();
        int read();

        std::istream &input;
        char ch;
        int line, col;
};

#endif // TOKENIZER_H
