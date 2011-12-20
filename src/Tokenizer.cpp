#include "Tokenizer.h"

#define _EOF -1

Tokenizer::Tokenizer(std::istream &_input) : input(_input), line(1), col(0), ch(0)
{}

Tokenizer::~Tokenizer()
{}



/***** utilities *****/
int Tokenizer::read()
{
    ch = input.get();

    if(input.eof())
        return ch = _EOF;
    if(ch == '\n')
    {
        line++;
        col = 0;
    }
    else
        col++;
    return ch;
}

/* * * */
void Tokenizer::skipWhitespace() //skip whitespaces
{
    if(!ch)
        read();

    while(ch != _EOF)
    {
        while(ch == '#')
            skipLine();

        if(!isspace(ch))
            break;

        read();
    }
}
/* * * */
void Tokenizer::skipLine()
{
    while(ch != _EOF && ch != '\n')
        read();
    read();
}



/** get next token **/
Token* Tokenizer::getToken()
{
    skipWhitespace();
    if(ch == _EOF)
        return NULL;

    else if( isalpha( ch ) )
    {
        std::string tmp("");
        while( isalnum( ch ) )
        {
            tmp.push_back( ch );
            if(read() == _EOF) break;
        }
        return new Name(tmp);
    }

    else if(isdigit( ch ))
    {
        int tmp = ch - '0';
        while( isdigit( read() ) )
        {
            tmp *= 10;
            tmp += ch - '0';
        }
        return new Number(tmp);
    }

    else
    {
        char tmp = ch;
        read();
        return new Operator(tmp);
    }

}
