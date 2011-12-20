#ifndef TOKEN_H
#define TOKEN_H

#include <string>

enum TokenType
{
    NAME,
    NUMBER,
    OPERATOR
};

/************/

class Token
{
    public:
        Token(){}
        virtual ~Token() {}

        virtual TokenType getType()=0;
};

/************/

class Name : public Token
{
    public:
        Name(std::string _value) : value(_value)
            {}
        virtual ~Name(){}

        std::string value;

        virtual TokenType getType() { return NAME; }
};

class Number : public Token
{
    public:
        Number(int _value) : value(_value)
            {}
        virtual ~Number(){}

        int value;

        virtual TokenType getType() { return NUMBER; }
};

class Operator : public Token
{
    public:
        Operator(char _value) : value(_value)
            {}
        virtual ~Operator(){}

        char value;

        virtual TokenType getType() { return OPERATOR; }
};
#endif // TOKEN_H
