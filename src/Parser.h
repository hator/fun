#ifndef PARSER_H
#define PARSER_H

#include "main.h"

#include "Expression.h"
#include "Tokenizer.h"

class Parser
{
    public:
        Parser(std::istream &_input);
        virtual ~Parser();

        Expression* parse();
    private:
        Tokenizer tokenizer;

};

#endif // PARSER_H
