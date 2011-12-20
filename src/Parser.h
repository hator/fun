#ifndef PARSER_H
#define PARSER_H

#include <sstream>
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
