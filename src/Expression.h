#ifndef EXPRESSION_H
#define EXPRESSION_H

#include "main.h"

class Expression
{
    public:
        Expression();
        virtual ~Expression()=0;

        virtual float Eval(...)=0;
};

class Constant : public Expression
{
    public:
        explicit Constant(float _v);
        virtual ~Constant();

        float Eval();

    private:
        float value;

};

class Function : public Expression
{
    public:
        Function();
        virtual ~Function();

        float Eval(float _a[8]=0);

    private:
        static multimap<string,pair<char[8],Expression*> > functions;

};

#endif // EXPRESSION_H
